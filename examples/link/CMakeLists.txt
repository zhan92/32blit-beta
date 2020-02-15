cmake_minimum_required(VERSION 3.1)
project (link)
include (../../32blit.cmake)
blit_executable (link link.cpp object.cpp)
blit_assets (link
    SPRITE_PACKED assets-png/boots.0.png
    SPRITE_PACKED assets-png/bracelet.0.png
    SPRITE_PACKED assets-png/eye.0.png
    SPRITE_PACKED assets-png/glove.0.png
    SPRITE_PACKED assets-png/handopen.0.png
    SPRITE_PACKED assets-png/main.0.png
    SPRITE_PACKED assets-png/mouth.0.png
    SPRITE_PACKED assets-png/sheath.0.png
    RAW link.obj)
