#include "rtweekend.h"

#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"

#include <fstream>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: raytracer <output.ppm>\n";
        exit(1);
    }
    std::clog << "Will save output to file: " << argv[argc - 1] << std::endl;

    std::ofstream outfile(argv[argc - 1]);
    if (!outfile.is_open()) {
        std::cerr << "Failed to open file\n";
        exit(1);
    }

    hittable_list world;

    auto material_ground = make_shared<lambertian>(color(0.14, 0.65, 0.29));
    auto material_center = make_shared<lambertian>(color(0.1, 0.2, 0.5));
    auto material_left   = make_shared<dielectric>(1.50);
    auto material_bubble = make_shared<dielectric>(1.00 / 1.50);
    auto material_right  = make_shared<metal>(color(0.8, 0.6, 0.2), 0.1);

    world.add(make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(make_shared<sphere>(point3( 0.0,    0.0, -1.2),   0.5, material_center));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.5, material_left));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.4, material_bubble));
    world.add(make_shared<sphere>(point3( 1.0,    0.0, -1.0),   0.5, material_right));

    camera cam;

    cam.aspect_ratio      = 16.0 / 9.0;
    cam.image_width       = 2000;
    cam.samples_per_pixel = 100;
    cam.max_depth         = 50;


    // cam.vfov     = 40;
    // cam.lookfrom = point3(-2,2,1);
    // cam.lookat   = point3(0,0,-1);
    // cam.vup      = vec3(0,1,0);

    cam.vfov     = 40;
    cam.lookfrom = point3(-2,1.25,1);
    cam.lookat   = point3(0,0,-1);
    cam.vup      = vec3(0,1,0);

    cam.render(world, outfile);

    outfile.close();
    
    return 0;
}
