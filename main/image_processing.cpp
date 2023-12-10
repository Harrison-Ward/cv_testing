// image_processing.cpp
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <omp.h>
#include "image_processing.h"
#include <unistd.h>
#include <fstream>
#include <iostream>


using namespace std;
using namespace cv;

void image_to_ascii(cv::Mat &input_image, std::string output_file_path, int kernel_size, const std::string grey_scale)
{
    // define luminosity matrix and kernel size
    cv::Mat luminosity_matrix;
    cv::Size kernel_dimensions(kernel_size, kernel_size);

    // convert image to luminosity matrix, i.e., matrix of averaged brightness values
    cv::blur(input_image, luminosity_matrix, kernel_dimensions);

    // loop over the image and map brightness values to ascii characters
    std::vector<std::string> output_ascii;
    std::stringstream pixel_stream;
    std::ofstream output_file(output_file_path);

// multi-thread the pixel mapping
#pragma omp parallel for
    for (int y = 0; y < input_image.cols; ++y)
    {
        std::string line;
        line.reserve(input_image.cols);

        for (int x = 0; x < input_image.cols; ++x)
        {
            unsigned char brightness_value = input_image.at<unsigned char>(y, x);
            unsigned char ascii_value = grey_scale[static_cast<int>((brightness_value * 69) / 255)];
            line += ascii_value;
        }
#pragma omp critical
        pixel_stream << line << "\n";
    }
    output_file << pixel_stream.str();
    output_file.close();
}

void frame_to_ascii(cv::Mat &input_image, int kernel_size, const std::string grey_scale)
{
    // define luminosity matrix and kernel size
    cv::Mat luminosity_matrix;
    cv::Size kernel_dimensions(kernel_size, kernel_size);

    // convert image to luminosity matrix, i.e., matrix of averaged brightness values
    cv::blur(input_image, luminosity_matrix, kernel_dimensions);

    // loop over the image and map brightness values to ascii characters
    std::vector<std::string> output_ascii;
    std::stringstream pixel_stream;

// multi-thread the pixel mapping
#pragma omp parallel for
    for (int y = 0; y < input_image.cols; ++y)
    {
        std::string line;
        line.reserve(input_image.cols);

        for (int x = 0; x < input_image.cols; ++x)
        {
            unsigned char brightness_value = input_image.at<unsigned char>(y, x);
            unsigned char ascii_value = grey_scale[static_cast<int>((brightness_value * 69) / 255)];
            line += ascii_value;
        }
#pragma omp critical
        pixel_stream << line << "\n";
    }
    std::cout << pixel_stream.str();
}

void ascii_display_to_file(const std::string& ascii_frame, const std::string& output_file_path)
{
    std::ofstream file(output_file_path, std::ofstream::out | std::ofstream::trunc);

    if (!file.is_open())
    {
        cerr << "Error, unable to open file.\n";
        return;
    }

    file << ascii_frame;

    if (!file)
    {
        cerr << "Error, unable to write to file.\n";
        return;
    }

    file.close();
}

void ascii_display_to_console(const std::string& ascii_frame)
{
    // Clear the screen
    std::system("clear");

    // Print the ASCII frame to the terminal
    std::cout << ascii_frame;
    std::cout.flush();
}
