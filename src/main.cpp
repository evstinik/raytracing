#include "rtweekend.h"

#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"
#include "camera.h"

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

    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width  = 400;
    cam.samples_per_pixel = 400;
    cam.max_depth         = 10; // or max bounces?

    cam.render(world, outfile);

    outfile.close();
    
    return 0;
}
