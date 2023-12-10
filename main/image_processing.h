// image_processing.h
#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <omp.h>
#include <unistd.h>
#include <fstream>
#include <iostream>


void image_to_ascii(cv::Mat& input_image, std::string output_file_path, int kernel_size, const std::string grey_scale);
// void ascii_display(const std::string& ascii_frame, const std::string& output_file_path);
void ascii_display(const std::string& ascii_frame);
void frame_to_ascii(cv::Mat &input_image, int kernel_size, const std::string grey_scale);

#endif // IMAGE_PROCESSING_H
