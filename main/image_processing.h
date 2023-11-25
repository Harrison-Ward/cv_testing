// image_processing.h
#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <opencv2/opencv.hpp>

cv::Mat convert_to_greyscale(const cv::Mat& input_image);

void luminosity_to_ascii(cv::Mat& input_image, std::vector<std::string>& output_ascii, const std::string grey_scale);

#endif // IMAGE_PROCESSING_H
