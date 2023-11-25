// image_processing.h
#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <opencv2/opencv.hpp>

void image_to_ascii(cv::Mat& input_image, std::string output_file_path, int kernel_size, const std::string grey_scale);

#endif // IMAGE_PROCESSING_H
