#pragma once

#include "32blit.hpp"

using namespace blit;

void draw_face(Vec3* vertices, Vec3* normals, Vec2* texture_coordinates, Surface* texture, Vec3 light, float *zbuffer, float near, float far);