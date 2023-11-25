// image_processing.cpp
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "image_processing.h"
#include <unistd.h>
#include <fstream>
using namespace std;

void image_to_ascii(cv::Mat &input_image, std::string output_file_path, int kernel_size, const std::string grey_scale)
{
    // define luminosity matrix and kernel size
    cv::Mat luminosity_matrix;
    cv::Size kernel_dimensions(kernel_size, kernel_size);

    // convert image to luminosity matrix, i.e., matrix of averaged brightness values
    cv::boxFilter(input_image, luminosity_matrix, -1, kernel_dimensions);

    // loop over the image and map brightness values to ascii characters
    std::vector<std::string> output_ascii;

    std::ofstream output_file(output_file_path);
    for (int y = 0; y < input_image.cols; ++y)
    {
        std::string line;
        for (int x = 0; x < input_image.cols; ++x)
        {
            unsigned char brightness_value = input_image.at<unsigned char>(y, x);
            char ascii_value = grey_scale[static_cast<int>((brightness_value * 69) / 255)];
            line += ascii_value;
        }
        output_file << line << "\n";
    }
    output_file.close();
}