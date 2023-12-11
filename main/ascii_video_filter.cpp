#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include "image_processing.h"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
    // initalize the video frames
    Mat frame;
    VideoCapture capture; 

    // prepare the ascii output parameters
    string g_scale = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";

    // open the default camera
    int device_id = 0;
    int api_id = cv::CAP_ANY;

    capture.open(device_id, api_id);

    // check camera opened 
    if (!capture.isOpened())
    {
        cerr << "Error, unable to open camera.\n";
        return -1;
    }

    system("clear");
    while (true)
    {
        capture >> frame;

        if (frame.empty())
        {
            cerr << "Error, frame not found.\n";
            break;
        }

        // Convert frame to ASCII
        frame_to_ascii(frame, 500, g_scale, 69);
        system("clear");
    }    
    return 0;
}