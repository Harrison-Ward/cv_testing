#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "image_processing.h"
#include <unistd.h>
#include <fstream>
using namespace std;

int main(int argc, char*argv[])
{
    // check that a file path has been provided
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <image_path>" << std::endl;
        return 1;
    }

    // ascii conversion grey scale
    std::string g_scale = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";

    // read in images from the file paths provided in the argument vector
    std::vector<cv::Mat> images;
    for (int i = 1; i < argc; i++) 
    {   
        // define grey scale map
        std::string g_scale = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
        
        auto start_load = std::chrono::high_resolution_clock::now();

        cv::Mat img = cv::imread(argv[i], cv::IMREAD_GRAYSCALE);
        if (img.empty()) {
            std::cerr << "Error: Image at " << argv[i] << " could not be loaded." << std::endl;
            continue; // Skip this image and continue with the next one
        }

        // measure load time
        auto end_load = std::chrono::high_resolution_clock::now();
        auto load_duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_load - start_load).count();
        std::cout << "\n image loaded in " << load_duration << " miliseconds" << endl;

        // resize the image to aid display
        cv::resize(img, img, cv::Size(), 0.5, 0.5);
        // create the output file path based on the name of the input image
        auto file_name = static_cast<string>(argv[i]);
        size_t extension_position = file_name.find_last_of('.');

        auto output_file_path = file_name.substr(0, extension_position);
        output_file_path += ".txt";
        
        // convert the image to ACII and write it to the output folder, time it
        auto start = std::chrono::high_resolution_clock::now();
        image_to_ascii(img, output_file_path, 5, g_scale);
        auto end = std::chrono::high_resolution_clock::now();

        // display time to generate
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << output_file_path << "generated in: " << duration << " miliseconds" << endl;
    }
    return 0;
}