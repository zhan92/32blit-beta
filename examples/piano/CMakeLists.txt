cmake_minimum_required(VERSION 3.8)
project (piano)
include (../../32blit.cmake)
blit_executable (piano piano.cpp)
blit_metadata (piano metadata.yml)
