#include "engine/engine.hpp"
#include "engine/api_private.hpp"

extern void init();
extern void update(uint32_t time);
extern void render(uint32_t time);

extern "C" bool cpp_do_init() {
    if(blit::api.version < blit::api_version)
        return false;

    blit::update = update;
    blit::render = render;

    blit::set_screen_mode(blit::ScreenMode::lores);

    init();

    return true;
}

extern "C" void _exit(int code) {
  blit::api.exit(code != 0);
}