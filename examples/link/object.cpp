#include <stdlib.h>
#include <math.h>
#include <string.h>

#include <algorithm>

#include "object.hpp"

using namespace blit;

#define M_PI           3.14159265358f  /* pi */

using namespace std;

texture::~texture() {
  //delete[] data;
}

/*
  object
*/

object::object() {
}

//  object::object(vertex *v, uint32_t vc, face *f, uint32_t fc, Vec3 *t, uint32_t tc) :v(v), vc(vc), f(f), fc(fc), t(t), tc(tc) {    
//    update_bbox();
//  }

object::~object() {
  delete[] v;
  delete[] t;
  delete[] n;
  delete[] g;
}

void object::update_bbox() {
  bounds.v1.x = v[0].x;
  bounds.v1.y = v[0].y;
  bounds.v1.z = v[0].z;
  bounds.v2.x = v[0].x;
  bounds.v2.y = v[0].y;
  bounds.v2.z = v[0].z;

  for (uint32_t i = 0; i < vc; i++) {
    bounds.v1.x = min(v[i].x, bounds.v1.x);
    bounds.v1.y = min(v[i].y, bounds.v1.y);
    bounds.v1.z = min(v[i].z, bounds.v1.z);
    bounds.v2.x = max(v[i].x, bounds.v2.x);
    bounds.v2.y = max(v[i].y, bounds.v2.y);
    bounds.v2.z = max(v[i].z, bounds.v2.z);
  }
}

group::group() {

}

group::~group() {
  delete[] f;
  delete[] t;
}
/* 
  camera
*/

camera::camera(vertex p, Vec3 d, Vec3 u) :p(p), d(d), u(u) {
  d.normalize();
  u.normalize();
}

Mat4 camera::translation_matrix() {
  return Mat4::translation(Vec3(-p.x, -p.y, -p.z));
}

Mat4 camera::rotation_matrix() {
  Vec3 rn(d);
  rn.normalize();

  Vec3 ru = u.cross(d);
  ru.normalize();

  Vec3 rv = rn.cross(ru);

  Mat4 r;

  r.v00 = ru.x; r.v01 = ru.y; r.v02 = ru.z;
  r.v10 = rv.x; r.v11 = rv.y; r.v12 = rv.z;
  r.v20 = rn.x; r.v21 = rn.y; r.v22 = rn.z;
  
  return r;
}

Mat4 camera::ortho_projection_matrix(float width, float height) {
  Mat4 r;
  
  r = Mat4::ortho(-width / 2.0f, width / 2.0f, -height / 2.0f, height / 2.0f, (width + height) / 4.0f, -(width + height) / 4.0f);

  return r;
}

Mat4 camera::perspective_projection_matrix(float fov, float width, float height, float near, float far) {
  Mat4 m;

  const float aspect = width / height;
  const float range = near - far;
  const float htan = tanf(fov * M_PI / 180.0f / 2.0f);

  m.v00 = 1.0f / (htan * aspect);
  m.v11 = 1.0f / htan;
  m.v22 = (near + far) / range;
  m.v32 = 2.0f * far * near / range;
  m.v23 = -1.0f;
  m.v33 = 0.0f;

  return m;
}

void discard_whitespace(char **p, char *eof) {
  while((**p == ' ' || **p == '\t' || **p == '\n') && (*p < eof)) {
    (*p)++;
  }
}

const char* fetch_token(char **p, char *eof) {
  static char token[32];
  memset(token, 0, 32);

  char *t = token;
  while((**p != '\t') && (**p != ' ') && (**p != '\n') && (*p < eof)) {
    **p = *t;
    (*p)++;
    t++;
  }

  discard_whitespace(p, eof);

  return token;
}

object* load_obj(Asset asset) {      
  char *p = (char *)asset.data;
  char *eof = p + asset.length;

  object *obj = new object();

  // first pass: count number of groups, vertices, texture coords, and normal Vec3s
  while (p <= eof) { 
    const char *token = fetch_token(&p, eof);

    if(!strcmp(token, "g")) {
      obj->gc++;
    }
    
    if(!strcmp(token, "v")) {
      obj->vc++;
    }

    if(!strcmp(token, "vn")) {
      obj->nc++;
    }
    
    if(!strcmp(token, "vt")) {
      obj->tc++;
    }        
  }

return obj;
  // allocate storage
  obj->g = new  group[obj->gc];
  obj->v = new vertex[obj->vc];
  
  obj->t = new vertex[obj->tc];
  obj->n = new Vec3[obj->nc];
  
  /*
  // group index starts at -1 since it gets incremented each time we encounter a
  // group ("g") command.
  uint32_t gi = -1, vi = 0, ti = 0, ni = 0;

  // second pass: extra vertices, texture coordinates, and normals
  // also count the number of faces per group
  p = (uint8_t*)asset.data; // back to the start...
  while (p <= eof) {     
    // each time we encounter a group ("g") then we move on to the next group index
    // to start counting the faces for that group
    if(p[0] == 'g') {
      gi++;
    } else if (p[0] == 'f') { 
          // if it's a quad then we need to add an extra face
      obj->g[gi].fc += std::count(line.begin(), line.end(), ' ') < 4 ? 1 : 2;
    } else if (p[0] == 'v' && p[1] == 'n') { 
      obj->n[ni].x = stof(strip_token(line, " "));
      obj->n[ni].y = stof(strip_token(line, " "));
      obj->n[ni].z = stof(strip_token(line, " "));
      ni++;
    } else if (p[0] == 'v' && p[1] == 't') { 
      obj->t[ti].x = stof(strip_token(line, " "));
      obj->t[ti].y = stof(strip_token(line, " "));
      ti++;
    } else if (p[0] == 'v') { 
      obj->v[vi].x = stof(strip_token(line, " "));
      obj->v[vi].y = stof(strip_token(line, " "));
      obj->v[vi].z = stof(strip_token(line, " "));
      vi++;
    }

    while(*p != '\n') { p++; } p++;


    if (type == "g") { gi++; }
    if (type == "f") { 
    }

    if (type == "v") {
    }

    if (type == "vn") {
    }

    if (type == "vt") {
    }
  }
  
  // allocate storage for faces on each group
  for (gi = 0; gi < obj->gc; gi++) {
    obj->g[gi].f = new face[obj->g[gi].fc];
  }

  // third pass: now extract the face indices      
  uint32_t fi = 0; gi = -1;
  p = (uint8_t*)asset.data; // back to the start...
  while (p <= eof) { 
    string line = getline(&p); 

    string type = strip_token(line, " \t");

    if (type == "g") { gi++; fi = 0; }
    if (type == "f") {
      face *f = &obj->g[gi].f[fi];

      string f0 = strip_token(line, " \t");
      string f1 = strip_token(line, " \t");
      string f2 = strip_token(line, " \t");

      f->v[0] = stol(strip_token(f0, "/")) - 1;
      f->t[0] = stol(strip_token(f0, "/")) - 1;
      f->v[1] = stol(strip_token(f1, "/")) - 1;
      f->t[1] = stol(strip_token(f1, "/")) - 1;
      f->v[2] = stol(strip_token(f2, "/")) - 1;
      f->t[2] = stol(strip_token(f2, "/")) - 1;

      if (f0 != "") {  // we can assume there is a normal value supplied
        f->n[0] = stol(strip_token(f0, "/")) - 1;
        f->n[1] = stol(strip_token(f1, "/")) - 1;
        f->n[2] = stol(strip_token(f2, "/")) - 1;
      }

      fi++;
      // THIS DOESNT WORK! }:-(
      // if (line != "") {
      //   face *f = &obj->g[gi].f[fi];

      //   string f3 = strip_token(line, " \t");

      //   f->v[0] = stol(strip_token(f0, "/")) - 1;
      //   f->t[0] = stol(strip_token(f0, "/")) - 1;
      //   f->v[2] = stol(strip_token(f1, "/")) - 1;
      //   f->t[2] = stol(strip_token(f1, "/")) - 1;
      //   f->v[3] = stol(strip_token(f2, "/")) - 1;
      //   f->t[3] = stol(strip_token(f2, "/")) - 1;


      //   f->v[0] = stol(strip_token(f0, "/")) - 1;
      //   f->t[0] = stol(strip_token(f0, "/")) - 1;

      //   f->obj->g[gi].f[fi].v[3] = stol(strip_token(f3, "/")) - 1;
      //   obj->g[gi].f[fi].t[3] = stol(strip_token(f3, "/")) - 1;
      //   if (f3 != "") {
      //     obj->g[gi].f[fi].n[2] = stol(strip_token(f3, "/")) - 1;
      //   }
      // }    
    }
  }        
  
  obj->update_bbox();

  return obj;*/
}