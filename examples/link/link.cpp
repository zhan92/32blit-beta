
#include <string>
#include <string.h>
#include <memory>
#include <cstdlib>

#include "32blit.hpp"
#include "object.hpp"
#include "assets.hpp"


using namespace blit;
using namespace std;

/*extern const blit::Asset asset_boots_0_png;
extern const blit::Asset asset_bracelet_0_png;
extern const blit::Asset asset_eye_0_png;
extern const blit::Asset asset_glove_0_png;
extern const blit::Asset asset_handopen_0_png;
extern const blit::Asset asset_main_0_png;
extern const blit::Asset asset_mouth_0_png;
extern const blit::Asset asset_sheath_0_png;
extern const blit::Asset asset_link;*/

SpriteSheet *main_texture;
SpriteSheet *boots_texture;
SpriteSheet *eye_texture;
SpriteSheet *mouth_texture;
SpriteSheet *handopen_texture;
SpriteSheet *bracelet_texture;
SpriteSheet *glove_texture;
SpriteSheet *sheath_texture;

object *link_object;
camera cam(
  Vec3(25.0f, 60.0f, 0.0f), 
  Vec3(0.0f, -0.2f, 0.5f),
  Vec3(0.0f, 0.0f, 1.0f));

float scale = 1.0f;

constexpr uint32_t fixed_shift = 0;
constexpr uint32_t fixed_mul = 1 << fixed_shift;


int32_t orient2d(const Point &p1, const Point &p2, const Point &p3) {
  return (((p2.x - p1.x) * (p3.y - p1.y)) >> fixed_shift) - (((p2.y - p1.y) * (p3.x - p1.x)) >> fixed_shift);
}

bool is_top_left(const Point &p1, const Point &p2) {
  return (p1.y == p2.y && p1.x > p2.x) || (p1.y < p2.y);
}

float zbuffer[160][120];


void draw_face(Vec3 *vertices, Vec3* normals, Vec2* texture_coordinates, Surface *texture, Vec3 light) {  
  // convert vertices into Q8 integer points
  Point p0(vertices[0].x, vertices[0].y);
  Point p1(vertices[1].x, vertices[1].y);
  Point p2(vertices[2].x, vertices[2].y);  

  // back-face cull if winding order is reversed
  if (orient2d(p0, p1, p2) < 0) { return; }

  // calculate bounds clipped to screen  
  int32_t minx = max(screen.clip.x, min(p0.x, min(p1.x, p2.x)));
  int32_t miny = max(screen.clip.y, min(p0.y, min(p1.y, p2.y)));
  int32_t maxx = min(screen.clip.x + screen.clip.w - 1, max(p0.x, max(p1.x, p2.x)));
  int32_t maxy = min(screen.clip.y + screen.clip.h - 1, max(p0.y, max(p1.y, p2.y)));

  // nothing to draw
  if (minx == maxx && miny == maxy) { return; }  

  // bias ensures no overdraw between neighbouring triangles along the shared edge
  // now it's fixed point can this just always be applied as -128?
  int32_t bias0 = is_top_left(p1, p2) ? 0 : -1;
  int32_t bias1 = is_top_left(p2, p0) ? 0 : -1;
  int32_t bias2 = is_top_left(p0, p1) ? 0 : -1;

  Point p(minx, miny);
  int32_t a01 = p0.y - p1.y, b01 = p1.x - p0.x;
  int32_t a12 = p1.y - p2.y, b12 = p2.x - p1.x;
  int32_t a20 = p2.y - p0.y, b20 = p0.x - p2.x;
  int32_t w0row = orient2d(p1, p2, p) - bias0;
  int32_t w1row = orient2d(p2, p0, p) - bias1;
  int32_t w2row = orient2d(p0, p1, p) - bias2;

  float invarea = 1.0f / orient2d(p0, p1, p2);


  float t1x, t1y, t2x, t2y, t3x, t3y;

  if(texture) {
    t1x = texture_coordinates[0].x * texture->bounds.w;
    t1y = texture_coordinates[0].y * texture->bounds.h;
    t2x = texture_coordinates[1].x * texture->bounds.w;
    t2y = texture_coordinates[1].y * texture->bounds.h;
    t3x = texture_coordinates[2].x * texture->bounds.w;
    t3y = texture_coordinates[2].y * texture->bounds.h;
  }

  
  for (p.y = miny; p.y < maxy; p.y++) {
    uint32_t pixel_offset = screen.offset(minx, p.y);    

    int32_t w0 = w0row;
    int32_t w1 = w1row;
    int32_t w2 = w2row;

    for (p.x = minx; p.x < maxx; p.x++) {
      // check if sign bit is set in any of our barycentric coordinates
      // if so we're outside of the triangle so skip the pixel
      if ((w0 | w1 | w2) >= 0) {
        
        // calculate barycentric coordinates of current pixel
        float alpha = w0 * invarea;
        float  beta = w1 * invarea;
        float gamma = 1.0f - alpha - beta; // ensures sum == 1.0f

        float z = vertices[0].z * alpha + vertices[1].z * beta + vertices[2].z * gamma;
    
        if(z < zbuffer[p.y][p.x]) 
        {
          zbuffer[p.y][p.x] = z;
     
          if(texture) {          
            uint16_t tx = (t1x * alpha + t2x * beta + t3x * gamma);
            uint16_t ty = (t1y * alpha + t2y * beta + t3y * gamma);

            tx = (texture->bounds.w + (tx % texture->bounds.w)) % texture->bounds.w;
            ty = (texture->bounds.h + (ty % texture->bounds.h)) % texture->bounds.h;       

            Vec3 n = normals[0] * alpha + normals[1] * beta + normals[2] * gamma;            
            float dnl = max(n.dot(light), 0.0f);
            float light = dnl * 0.5f + 0.5f;
/*
            uint8_t r = alpha * 255;
            uint8_t g = beta * 255;
            uint8_t b = gamma * 255;

            screen.pen = Pen(r, g, b, 255);

            screen.pbf(&screen.pen, &screen, pixel_offset, 1);    */      

            screen.pen = texture->palette[texture->data[tx + ty * texture->bounds.w]];
            screen.pen.r *= light;
            screen.pen.g *= light;
            screen.pen.b *= light;
          } else {
           /* uint8_t r = alpha * 255;
            uint8_t g = beta * 255;
            uint8_t b = gamma * 255;

            screen.pen = Pen(r, g, b, 255);*/
          }          
          
          screen.pbf(&screen.pen, &screen, pixel_offset, 1);          
        }
       /* else
        {
            int32_t a = int32_t(z) & 0xff;//(alpha + beta + gamma) * 255;
 screen.pen = Pen(255, 0, 0, 255);
        screen.pbf(&screen.pen, &screen, a + 160 + 160 + 160 + 160, 1);    
       screen.pen = Pen(255, 0, 255, 255);
          //uint8_t g = beta * 255;
          //uint8_t b = gamma * 255;

          screen.pbf(&screen.pen, &screen, pixel_offset, 1);          
        }*/
        
        
        /*
        float z = (vertices[0].z * a + vertices[1].z * b + vertices[2].z * c);

        if(zbuffer[p.y][p.x] < z) {
          continue;
        }
        
        zbuffer[p.y][p.x] = z;
        
        if(texture) {
          
          uint16_t tx = (t1x * a + t2x * b + t3x * c);
          uint16_t ty = (t1y * a + t2y * b + t3y * c);

          tx %= texture->bounds.w;
          ty %= texture->bounds.h;


          screen.pen = texture->palette[main_texture->data[tx + ty * texture->bounds.w]];
          //= main_texture->pixel(tx, ty);

          uint8_t r = a * 255;
          uint8_t g = b * 255;
          uint8_t b = c * 255;
          
          screen.pen = Pen(r, g, b);
        //  screen.pen.r = (screen.pen.r + r) / 2;
        //  screen.pen.g = (screen.pen.g + g) / 2;
         // screen.pen.b = (screen.pen.b + b) / 2;
        } else {
          
          uint8_t r = a * 255;
          uint8_t g = b * 255;
          uint8_t b = c * 255;
          screen.pen = Pen(r, g, b);
        }

        screen.pbf(&screen.pen, &screen, screen.offset(p), 1);    */    
      }

      w0 += a12;
      w1 += a20;
      w2 += a01;

      pixel_offset++;
    }

    w0row += b12;
    w1row += b20;
    w2row += b01;
  }
}

void init() {
  set_screen_mode(lores);

  link_object = load_obj(asset_link);

  main_texture = SpriteSheet::load(asset_main_0_png.data);  
  boots_texture = SpriteSheet::load(asset_boots_0_png.data);  
  eye_texture = SpriteSheet::load(asset_eye_0_png.data);  
  mouth_texture = SpriteSheet::load(asset_mouth_0_png.data);  
  handopen_texture = SpriteSheet::load(asset_handopen_0_png.data);  
  bracelet_texture = SpriteSheet::load(asset_bracelet_0_png.data);  
  glove_texture = SpriteSheet::load(asset_glove_0_png.data);  
  sheath_texture = SpriteSheet::load(asset_sheath_0_png.data);  
  link_object->g[1].t = main_texture;
  link_object->g[2].t = main_texture;
  link_object->g[3].t = boots_texture;
  link_object->g[4].t = eye_texture;
  link_object->g[5].t = mouth_texture;
  link_object->g[6].t = handopen_texture;
  link_object->g[7].t = bracelet_texture;
  link_object->g[8].t = glove_texture;
  link_object->g[9].t = sheath_texture;


  

//  ss = SpriteSheet::load(packed_data);
//  screen.sprites = ss;
}

int tick_count = 0;
void render(uint32_t time_ms) {
  tick_count++;
  screen.alpha = 255;
  screen.mask = nullptr;
  screen.pen = Pen(20, 30, 40);
  screen.clear();

  uint32_t ms_start = now();

  for(uint32_t zy = 0; zy < 120; zy++) {
    for(uint32_t zx = 0; zx < 160; zx++) {
      zbuffer[zy][zx] = 10000000.0f;
    }
  }
  
  /*

      Vec3 vertices[3] = {
        Vec3(-25, -50, 0),
        Vec3(25, -50, 0),
        Vec3(-25, 50, 0),
      };


      Mat4 r = Mat4::translation(Vec3(80, 60));
      r *= Mat4::rotation(time_ms / 10, Vec3(0, 0, 1));
      r *= Mat4::scale(Vec3(0.2f, 0.2f, 0.2f));
      for(auto &v : vertices) {
        v.transform(r);
      }

      Vec2 texture_coordinates[3] = {
        Vec2(0, 0),
        Vec2(1, 0),
        Vec2(0, 1)
      };
        

      draw_face(vertices, texture_coordinates, main_texture);
        return;
*/

      
     // if (g->t) {
        //triangle3d(&screen, link_object, f, v, &objlight, g->t/*, st, &shadowmap*/);
        //screen.pen = Pen(255, 255, 255);

        /*

        screen.pen = Pen(255, 255, 255);
        screen.pixel(Point(50, 50));
        screen.pixel(Point(145, 68));
        screen.pixel(Point(30, 95));
*/
        


  Vec3 light(1.0f, -0.6f, 0.2f);
  Mat4 t = Mat4::identity();    
  // offset to center on viewport
  //t *= Mat4::translation(Vec3(screen.bounds.w / 2.0f, screen.bounds.h / 2.0f, 0.0f));
  t *= Mat4::translation(Vec3(130, 0, 0.0f));


  float _near = -1.0f;
  float _far = 10.0f;


  t *= cam.ortho_projection_matrix(scale, scale);
  
  
  // camera position and direction
  t *= cam.rotation_matrix(); 

  
     /*    screen.pen = Pen(255, 255, 255);
        screen.text(std::to_string(int(t.v00 * 1000)), minimal_font, Point(0, 100));
        screen.text(std::to_string(int(t.v10 * 1000)), minimal_font, Point(0, 110));
        screen.text(std::to_string(int(t.v20 * 1000)), minimal_font, Point(0, 120));
        screen.text(std::to_string(int(t.v30 * 1000)), minimal_font, Point(0, 130));

        screen.text(std::to_string(int(t.v01 * 1000)), minimal_font, Point(30, 100));
        screen.text(std::to_string(int(t.v11 * 1000)), minimal_font, Point(30, 110));
        screen.text(std::to_string(int(t.v21 * 1000)), minimal_font, Point(30, 120));
        screen.text(std::to_string(int(t.v31 * 1000)), minimal_font, Point(30, 130));

        screen.text(std::to_string(int(t.v02 * 1000)), minimal_font, Point(60, 100));
        screen.text(std::to_string(int(t.v12 * 1000)), minimal_font, Point(60, 110));
        screen.text(std::to_string(int(t.v22 * 1000)), minimal_font, Point(60, 120));
        screen.text(std::to_string(int(t.v32 * 1000)), minimal_font, Point(60, 130));

        screen.text(std::to_string(int(t.v03 * 1000)), minimal_font, Point(90, 100));
        screen.text(std::to_string(int(t.v13 * 1000)), minimal_font, Point(90, 110));
        screen.text(std::to_string(int(t.v23 * 1000)), minimal_font, Point(90, 120));
        screen.text(std::to_string(int(t.v33 * 1000)), minimal_font, Point(90, 130));*/
    //    return;

  t *= cam.translation_matrix();


  Mat4 objt = Mat4::identity();
  // calculate transform to centre object on origin

  float objscale = std::min(screen.bounds.w / (link_object->bounds.v2.x - link_object->bounds.v1.x), screen.bounds.h / (link_object->bounds.v2.y - link_object->bounds.v1.y));
  objscale /= 2.2;

  /*float tx = (obj->bounds.v1.x + obj->bounds.v2.x) / 2.0f;
  float ty = (obj->bounds.v1.y + obj->bounds.v2.y) / 2.0f;
  float tz = (obj->bounds.v1.z + obj->bounds.v2.z) / 2.0f;
  ot.multiply(mat4::translate(-tx * objscale, -ty * objscale, -tz * objscale)); // TranslationTrans * RotateTrans * ScaleTrans (might need splitting out?)*/
  objt *= Mat4::rotation(40, Vec3(1, 0, 0));

  objt *= Mat4::translation(Vec3(0.0f, 0.0f, 0.0f));
  objt *= Mat4::rotation(time_ms / 20.0f, Vec3(0, 1.0f, 0));
  objt *= Mat4::scale(Vec3(objscale, objscale, objscale));
  

  Mat4 ot = t;
  ot *= objt;


  // apply the inverse object transform to the light source
  // this is effectively the same as transforming all of the objects
  // normals but a lot faster!
  Vec3 nlight = light;
  nlight.normalize();

  Mat4 objti = objt;
  objti.inverse();

  Vec3 objlight = objti.transform(nlight);
  objlight.normalize();

  uint32_t tri_count = 0;

  for (uint32_t gi = 1; gi < link_object->gc; gi++) {
    group *g = &link_object->g[gi];
    for (uint32_t fi = 0; fi < g->fc; fi++) {
      face *f = &g->f[fi];        
 
      Vec3 vertices[3] = {
        ot.transform(link_object->v[f->v[0]]),
        ot.transform(link_object->v[f->v[1]]),
        ot.transform(link_object->v[f->v[2]])
      };

      Vec2 texture_coordinates[3] = {
        link_object->t[f->t[0]],
        link_object->t[f->t[1]],
        link_object->t[f->t[2]]
      };

      Vec3 normals[3] = {
        link_object->n[f->n[0]],
        link_object->n[f->n[1]],
        link_object->n[f->n[2]]
      };
        
     // if (g->t) {
        //triangle3d(&screen, link_object, f, v, &objlight, g->t/*, st, &shadowmap*/);
        //screen.pen = Pen(255, 255, 255);
        draw_face(vertices, normals, texture_coordinates, g->t, objlight);
    
        /*screen.pen = Pen(255, 255, 255, 100);
        screen.line(Point(vertices[0].x, vertices[0].y), Point(vertices[1].x, vertices[1].y));
        screen.line(Point(vertices[1].x, vertices[1].y), Point(vertices[2].x, vertices[2].y));
        screen.line(Point(vertices[2].x, vertices[2].y), Point(vertices[0].x, vertices[0].y));
*/
       /* screen.pixel(Point(v[0].x, v[0].y));
        screen.pixel(Point(v[1].x, v[1].y));
        screen.pixel(Point(v[2].x, v[2].y));*/
        tri_count++;
      //}
    }
  }
  
  
  
  uint32_t ms_end = now();  
  

  // draw FPS meter
 /* screen.pen = Pen(0, 0, 0, 200);
  screen.rectangle(Rect(5, 5, 20, 16));
  screen.pen = Pen(255, 0, 0);
  std::string fms = std::to_string(ms_end - ms_start);
  screen.text(fms, minimal_font, Rect(10, 10, 10, 16));
*/
  int block_size = 4;
  for (uint32_t i = 0; i < (ms_end - ms_start); i++) {
    screen.pen = Pen(i * 5, 255 - (i * 5), 0);
    screen.rectangle(Rect(i * (block_size + 1) + 1, screen.bounds.h - block_size - 1, block_size, block_size));
  }

}

void update(uint32_t time) {
  static uint32_t last_buttons = 0;

  if (buttons != last_buttons) {  
/*    if ((buttons & DPAD_UP)) {
      set_screen_mode(lores);
      mask = lores_mask;
      screen.sprites = ss;
    }
    else {
      set_screen_mode(hires);
      mask = hires_mask;
      screen.sprites = ss;
    }*/
  }

  last_buttons = buttons;
}

