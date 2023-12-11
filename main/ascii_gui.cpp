#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <SFML/Graphics.hpp>
#include "image_processing.h"
#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

int main()
{
    // initalize the video frames
    Mat frame;
    VideoCapture capture;

    // set output size paramenters
    int kernel_size = 400;
    int font_size = 4;
    float image_resize_factor = 0.25;

    // prepare the ascii output parameters
    // string g_scale = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'.                ";
    string g_scale = "-_+^. ";
    reverse(g_scale.begin(), g_scale.end());
    int g_scale_length = g_scale.length();

    // open the default camera and grab the first frame
    int device_id = 0;
    int api_id = cv::CAP_ANY;

    capture.open(device_id, api_id);
    
    // check camera opened
    if (!capture.isOpened())
    {
        cerr << "Error, unable to open camera.\n";
        return -1;
    }

    // grab first frame
    capture >> frame;

    // store frame dimensions
    int frame_width = frame.cols;
    int frame_height = frame.rows;

    // calculate ascii frame size
    int ascii_width = frame_width;
    int ascii_height = frame_height;

    // calculate window size
    auto resized_width = static_cast<int>(frame_width * image_resize_factor);
    auto resized_height = static_cast<int>(frame_height * image_resize_factor);

    // create my SF text object
    sf::Font font;
    if (!font.loadFromFile("Menlo Regular 400.ttf"))
    {
        std::cerr << "Error loading font\n";
        return -1;
    }

    // Create a text object
    sf::Text text;
    text.setPosition(0, 0);
    text.setFont(font);
    text.setCharacterSize(8);
    text.setFillColor(sf::Color::White);

    // open the window for display
    sf::RenderWindow window(sf::VideoMode(ascii_width, ascii_height), "ASCII Art Display");

    int frames = 0;
    auto begin = chrono::high_resolution_clock::now();
    while (window.isOpen())
    {   
        auto start = chrono::high_resolution_clock::now();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // wipe window
        window.clear();

        capture >> frame;
        if (frame.empty())
        {
            cerr << "Error, frame not found.\n";
            break;
        }

        capture.read(frame);
        // check if we succeeded
        if (frame.empty()) {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        // show live and wait for a key with timeout long enough to show images
        imshow("Live", frame);
        if (waitKey(5) >= 0)
            break;

        // downsize and greyscale the frame
        Mat resized_frame;
        resize(frame, resized_frame, cv::Size(resized_width, resized_height));

        cvtColor(resized_frame, resized_frame, cv::COLOR_BGR2GRAY);

        // Convert frame to ASCII
        string ascii_frame;
        ascii_frame = frame_to_ascii(resized_frame, kernel_size, g_scale, g_scale_length);

        // display frame
        text.setString(ascii_frame);
        window.draw(text);
        window.display();

        // calculate FPS
        auto stop = chrono::high_resolution_clock::now();
        frames_per_second(start, stop);
        frames++;
    }

    // measure total run time
    auto end = chrono::high_resolution_clock::now();
    auto run_time = chrono::duration_cast<chrono::seconds>(end - begin).count();

    // calculate average FPS
    auto average_fps = frames / (run_time);

    cout << "Average FPS: " << average_fps << endl;


    return 0;
}
