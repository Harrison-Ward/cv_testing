#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "image_processing.h"
#include <unistd.h>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    // ensure that an file path is passed in at execution
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <image_path>" << std::endl;
        return 1;
    }

    // ascii conversion grey scale
    std::string g_scale = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";

    // loop over the argument vector, starting from first file path index and store images
    std::vector<cv::Mat> images;
    for (int i = 1; i < argc; i++)
    {
        cv::Mat img = cv::imread(argv[i], cv::IMREAD_GRAYSCALE);

        if (img.empty())
        {
            std::cerr << "Error: Image at " << argv[i] << " could not be loaded." << std::endl;
            continue; // Skip this image and continue with the next one
        }
        cv::resize(img, img, cv::Size(), 0.5, 0.5);
        // store images in the image vector
        images.push_back(img);
    }

    auto start = std::chrono::high_resolution_clock::now();
    // define kernel size for the image, smaller values for higher resolution
    cv::Size kernel_size(10, 10);
    std::vector<cv::Mat> luminosity_matricies;

    for (const auto &img : images)
    {
        // translate the images to their luminosity values
        cv::Mat luminosity_matrix;
        cv::boxFilter(img, luminosity_matrix, -1, kernel_size);
        luminosity_matricies.push_back(luminosity_matrix);
    }

    std::vector<std::vector<std::string>> ascii_images;
    // hash the luminosity values to their respective ascii chars
    for (auto &luminosity_matrix : luminosity_matricies)
    {
        std::vector<std::string> output_ascii;
        luminosity_to_ascii(luminosity_matrix, output_ascii, g_scale);

        ascii_images.push_back(output_ascii);
    }

    // loop over the images and display
    int i = 1;
    for (const auto &ascii : ascii_images)
    {
        string file_name;
        file_name += static_cast<string>(argv[i]);
        file_name = file_name.erase(file_name.length() - 5);
        file_name += ".txt";

        cout << file_name << endl;

        ofstream outFile(file_name);
        for (const auto &line : ascii)
        {
            outFile << line << "\n";
        }
        outFile.close();
        i++;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Time taken to generate ASCII art: " << duration << " milliseconds." << std::endl;
    return 0;
}