#include <iostream>
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

    // Image dimensions
    const int image_width = 256;
    const int image_height = 256;

    // Render
    outfile << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            auto r = double(i) / (image_width - 1);
            auto g = double(j) / (image_height - 1);
            auto b = 0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            outfile << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    std::clog << "\nDone.\n";

    outfile.close();
    
    return 0;
}
