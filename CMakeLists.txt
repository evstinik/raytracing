cmake_minimum_required(VERSION 3.10)

project(RayTracing VERSION 1.0
                  DESCRIPTION "Ray Tracing in One Weekend"
                  LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add executable
add_executable(raytracer src/main.cpp)

# Include directories
target_include_directories(raytracer PRIVATE include)

# Add compiler warnings
if(MSVC)
    target_compile_options(raytracer PRIVATE /W4)
else()
    target_compile_options(raytracer PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install target
install(TARGETS raytracer DESTINATION bin)
