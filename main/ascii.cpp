#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "image_processing.h"
#include <unistd.h>
using namespace cv;

int main(int argc, char *argv[])
{
    // ensure that an file path is passed in at execution
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <image_path>" << std::endl;
        return 1;
    }

    // loop over the argument vector, starting from first file path index and store images 
    std::vector<cv::Mat> images;
    for (int i = 1; i < argc; i++) {
        Mat img = imread(argv[i], IMREAD_GRAYSCALE);

        if (img.empty()) {
            std::cerr << "Error: Image at " << argv[i] << " could not be loaded." << std::endl;
            continue; // Skip this image and continue with the next one
        }

        // store images in the image vector 
        images.push_back(img);
    }
    
    // loop over the images and display 
    for (const auto& img : images) {
        imshow("Display window", img);
        cv::waitKey(1);
        sleep(10);
    }
    
    return 0;

}