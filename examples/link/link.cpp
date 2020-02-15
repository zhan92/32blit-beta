
#include <string>
#include <string.h>
#include <memory>
#include <cstdlib>

#include "32blit.hpp"
#include "object.hpp"
#include "assets.hpp"


using namespace blit;

/*extern const blit::Asset asset_boots_0_png;
extern const blit::Asset asset_bracelet_0_png;
extern const blit::Asset asset_eye_0_png;
extern const blit::Asset asset_glove_0_png;
extern const blit::Asset asset_handopen_0_png;
extern const blit::Asset asset_main_0_png;
extern const blit::Asset asset_mouth_0_png;
extern const blit::Asset asset_sheath_0_png;
extern const blit::Asset asset_link;*/

object *link_object;
camera cam(
  vertex(0.0f, 10.0f, 0.0f), 
  Vec3(0.0f, -0.5f, 0.5f),
  Vec3(0.0f, 0.0f, 1.0f));

float scale = 1.0f;

void init() {
  set_screen_mode(hires);

  link_object = load_obj(asset_link);
//  ss = SpriteSheet::load(packed_data);
//  screen.sprites = ss;
}

int tick_count = 0;
void render(uint32_t time_ms) {
  tick_count++;
  screen.alpha = 255;
  screen.mask = nullptr;
  screen.pen = Pen(tick_count % 256, 0, 0);
  screen.clear();

  screen.pen = Pen(255, 255, 255);
  screen.text(std::to_string(link_object->gc), minimal_font, Point(100,100));

  return;
  uint32_t ms_start = now();

  Vec3 light(1.0f, -0.6f, 0.2f);
  Mat4 t = Mat4::identity();    
  // offset to center on viewport
  t *= Mat4::translation(Vec3(screen.bounds.w / 2.0f, screen.bounds.h / 2.0f, 0.0f));

  float _near = -1.0f;
  float _far = 10.0f;


  t *= cam.ortho_projection_matrix(scale, scale);
  // camera position and direction
  t *= cam.rotation_matrix(); 
  t *= cam.translation_matrix();


  Mat4 objt;
  // calculate transform to centre object on origin

  float objscale = std::min(screen.bounds.w / (link_object->bounds.v2.x - link_object->bounds.v1.x), screen.bounds.h / (link_object->bounds.v2.y - link_object->bounds.v1.y));
  objscale /= 2.0;

  /*float tx = (obj->bounds.v1.x + obj->bounds.v2.x) / 2.0f;
  float ty = (obj->bounds.v1.y + obj->bounds.v2.y) / 2.0f;
  float tz = (obj->bounds.v1.z + obj->bounds.v2.z) / 2.0f;
  ot.multiply(mat4::translate(-tx * objscale, -ty * objscale, -tz * objscale)); // TranslationTrans * RotateTrans * ScaleTrans (might need splitting out?)*/
  objt *= Mat4::rotation(40, Vec3(1, 0, 0));

  objt *= Mat4::translation(Vec3(0.0f, 0.0f, 0.0f));
  objt *= Mat4::rotation(time_ms / 2.0f, Vec3(0, 1.0f, 0));
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

  for (uint32_t gi = 0; gi < link_object->gc; gi++) {
    group *g = &link_object->g[gi];
    for (uint32_t fi = 0; fi < g->fc; fi++) {
      face *f = &g->f[fi];        

      vertex v[3] = {
        ot.transform(link_object->v[f->v[0]]),
        ot.transform(link_object->v[f->v[1]]),
        ot.transform(link_object->v[f->v[2]])
      };
        
      if (g->t) {
     //   triangle3d(&screen, link_object, f, v, &objlight, g->t/*, st, &shadowmap*/);
      }
    }
  }
  

  uint32_t ms_end = now();  
  

  // draw FPS meter
  screen.pen = Pen(0, 0, 0, 200);
  screen.rectangle(Rect(5, 5, 20, 16));
  screen.pen = Pen(255, 0, 0);
  std::string fms = std::to_string(ms_end - ms_start);
  screen.text(fms, minimal_font, Rect(10, 10, 10, 16));

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



  void triangle3d_span(Surface *fb, object *obj, face *f, int32_t y, vertex *p, uint8_t a, uint8_t b, uint8_t c, uint8_t d, Vec3 *l, texture* t/*, mat4 st, ShadowMap *shadowmap*/) {
/*
    float g1 = (p[a].y != p[b].y) ? (y - p[a].y) / (p[b].y - p[a].y) : 1.0f;
    float g2 = (p[c].y != p[d].y) ? (y - p[c].y) / (p[d].y - p[c].y) : 1.0f;

    g1 = fmaxf(0.0f, std::min(1.0f, g1));
    g2 = fmaxf(0.0f, std::min(1.0f, g2));

    int32_t sx = int32_t(p[a].x + (p[b].x - p[a].x) * g1);
    int32_t ex = int32_t(p[c].x + (p[d].x - p[c].x) * g2);

    int32_t dx = ex - sx;
    int32_t ox = 0;
    if (sx < 0) {
      ox = abs(sx);
      sx = 0;      
    }

    if (ex >= (int32_t)fb->bounds.w) {
      ex = (int32_t)fb->bounds.w;
    }

    if (sx == ex) {
      return;
    }

    if (dx != 0) {
      float sz = p[a].z + (p[b].z - p[a].z) * g1;
      float ez = p[c].z + (p[d].z - p[c].z) * g2;
      float dz = (ez - sz) / dx;
      sz += (dz * ox);

      float su = obj->t[f->t[a]].x + (obj->t[f->t[b]].x - obj->t[f->t[a]].x) * g1;
      float eu = obj->t[f->t[c]].x + (obj->t[f->t[d]].x - obj->t[f->t[c]].x) * g2;
      su *= t->width;      
      eu *= t->width;
      float du = (eu - su) / dx;
      su += (du * ox);

      float sv = obj->t[f->t[a]].y + (obj->t[f->t[b]].y - obj->t[f->t[a]].y) * g1;
      float ev = obj->t[f->t[c]].y + (obj->t[f->t[d]].y - obj->t[f->t[c]].y) * g2;
      sv *= t->height;
      ev *= t->height;
      float dv = (ev - sv) / dx;
      sv += (dv * ox);

      float snx = obj->n[f->n[a]].x + (obj->n[f->n[b]].x - obj->n[f->n[a]].x) * g1;
      float enx = obj->n[f->n[c]].x + (obj->n[f->n[d]].x - obj->n[f->n[c]].x) * g2;
      float dnx = (enx - snx) / dx;
      snx += (dnx * ox);

      float sny = obj->n[f->n[a]].y + (obj->n[f->n[b]].y - obj->n[f->n[a]].y) * g1;
      float eny = obj->n[f->n[c]].y + (obj->n[f->n[d]].y - obj->n[f->n[c]].y) * g2;
      float dny = (eny - sny) / dx;
      sny += (dny * ox);

      float snz = obj->n[f->n[a]].z + (obj->n[f->n[b]].z - obj->n[f->n[a]].z) * g1;
      float enz = obj->n[f->n[c]].z + (obj->n[f->n[d]].z - obj->n[f->n[c]].z) * g2;
      float dnz = (enz - snz) / dx;
      snz += (dnz * ox);

      uint32_t off = sx + (y * fb->bounds.w);
      float *d = fb->d + off;
      colour *p = fb->p + off;

      uint16_t tx, ty;
      for (int32_t x = sx; x < ex; x++) {


        //if (x < 0 || x >= fb->width) continue;
        if (sz > *d) {
        //if (fb->d[x + (y * fb->width)] > sz) {
          tx = (int16_t)floor(su) % t->width;
          ty = (int16_t)floor(sv) % t->height;
          
          Vec3 n = Vec3(snx, sny, snz);
          float dnl = std::max(n.dot(*l), 0.0f);
          float light = dnl * 0.5f + 0.5f;

          Pen c = t->data[tx + (ty * t->width)];


          c.r = c.r * light;
          c.g = c.g * light;
          c.b = c.b * light;

          //fb->p[x + (y * fb->width)] = c;
          *p = c;          

          fb->mind = fminf(sz, fb->mind);
          fb->maxd = fmaxf(sz, fb->maxd);

          //fb->d[x + (y * fb->width)] = sz;
          *d = sz;
        }

        p++;
        d++;

        sz += dz;
        su += du;
        sv += dv;
        snx += dnx;
        sny += dny;
        snz += dnz;               
      }
    }*/
  }

  void triangle3d(Surface *fb, object *obj, face *f, vertex *p, Vec3 *l, texture *t/*, mat4 st, ShadowMap *shadowmap*/) {
    
    fb->triangle(Point(p[0].x, p[0].y), Point(p[1].x, p[1].y), Point(p[2].x, p[2].y));

    /*
    int32_t minx = int32_t(fminf(p[0].x, fminf(p[1].x, p[2].x)));
    int32_t maxx = int32_t(fmaxf(p[0].x, fmaxf(p[1].x, p[2].x)));
    int32_t miny = int32_t(fminf(p[0].y, fminf(p[1].y, p[2].y)));
    int32_t maxy = int32_t(fmaxf(p[0].y, fmaxf(p[1].y, p[2].y)));    

    // if triangle completely out of bounds then don't bother!
    if (maxx < 0 || minx >= int32_t(fb->bounds.w) || maxy < 0 || miny >= int32_t(fb->bounds.h)) {
      return;
    }

    // clip extremes to frame buffer size
    minx = fmaxf(minx, 0);
    miny = fmaxf(miny, 0);
    maxx = fminf(maxx, int32_t(fb->bounds.w));
    maxy = fminf(maxy, int32_t(fb->bounds.h));

    // clip if back facing
    float a = (p[1].x - p[0].x) * (p[2].y - p[0].y) - (p[2].x - p[0].x) * (p[1].y - p[0].y);
    if (a >= 0) {
      return;
    }

    // sort the point indices by y coordinate
    uint8_t idx[3] = { 0, 1, 2 };
    if (p[idx[0]].y > p[idx[1]].y) { uint8_t temp = idx[1]; idx[1] = idx[0]; idx[0] = temp; }
    if (p[idx[1]].y > p[idx[2]].y) { uint8_t temp = idx[1]; idx[1] = idx[2]; idx[2] = temp; }
    if (p[idx[0]].y > p[idx[1]].y) { uint8_t temp = idx[1]; idx[1] = idx[0]; idx[0] = temp; }

    float dp1p2 = 0.0;
    float dp1p3 = 0.0;

    if (p[idx[1]].y - p[idx[0]].y >= 0) {
      dp1p2 = (p[idx[1]].x - p[idx[0]].x) / (p[idx[1]].y - p[idx[0]].y);
    }

    if (p[idx[2]].y - p[idx[0]].y >= 0) {
      dp1p3 = (p[idx[2]].x - p[idx[0]].x) / (p[idx[2]].y - p[idx[0]].y);
    }

    uint32_t sy = max(0.0f, p[idx[0]].y);
    uint32_t ey = min((float)fb->height - 1, p[idx[2]].y);

    if (dp1p2 > dp1p3) {
      for (int32_t y = sy; y <= ey; y++) {
        if (y < p[idx[1]].y) {
          triangle3d_span(fb, obj, f, y, p, idx[0], idx[2], idx[0], idx[1], l, t);
        }
        else {
          triangle3d_span(fb, obj, f, y, p, idx[0], idx[2], idx[1], idx[2], l, t);
        }
      }
    }
    else {
      for (int32_t y = sy; y <= ey; y++) {
        if (y < p[idx[1]].y) {
          triangle3d_span(fb, obj, f, y, p, idx[0], idx[1], idx[0], idx[2], l, t);
        }
        else {
          triangle3d_span(fb, obj, f, y, p, idx[1], idx[2], idx[0], idx[2], l, t);
        }
      }
    }
    
    // debug each edge in red/green/blue
    //line(fb, p[0], p[1], colour(255, 0, 0));
    //line(fb, p[1], p[2], colour(0, 255, 0));
    //line(fb, p[2], p[0], colour(0, 0, 255));*/
  }

