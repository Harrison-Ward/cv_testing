// image_processing.cpp
#include <opencv2/opencv.hpp>
#include "image_processing.h"
using namespace cv;

cv::Mat convert_to_greyscale(const cv::Mat& input_image)
{
    // read in the image matrix
    if (input_image.empty())
    {
        throw std::invalid_argument("Input image is empty");
    }
    
    // convert image to greyscale 
    cv::Mat greyscale_image;
    cv::cvtColor(input_image, greyscale_image, cv::COLOR_BGR2GRAY); 

    // return the new image matrix
    return greyscale_image;
}

void luminosity_to_ascii(cv::Mat& input_image, std::vector<std::string>& output_ascii, const std::string grey_scale) {
    // loop over each value in the function 
    for (int y = 0; y < input_image.cols; ++y) {
        std::string line;
        for (int x = 0; x < input_image.cols; ++x) {
            unsigned char brightness_value = input_image.at<unsigned char>(y, x);
            char ascii_value = grey_scale[static_cast<int>((brightness_value * 69) / 255)];
            line += ascii_value;
        }
        output_ascii.push_back(line);
    }
}