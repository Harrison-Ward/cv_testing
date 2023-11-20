#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namesapce cv;

int main()
{
    std::string image_path = "null"
    Mat img = imread(image_path, IMREAD_COLOR);

    imshow("Display window", img);
    int k = waitKey(0);
    return 0;
}