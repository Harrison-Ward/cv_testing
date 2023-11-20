#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "image_processing.h"
using namespace cv;

int main()
{
    // read in image
    std::string image_path = "../images/boxes.jpeg";
    Mat img = imread(image_path, IMREAD_COLOR);

    // convert image to greyscale
    Mat gs_img = convert_to_greyscale(img);

    // display image 
    imshow("Display window", gs_img);
    int k = waitKey(0);
    return 0;
}