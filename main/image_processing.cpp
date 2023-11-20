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