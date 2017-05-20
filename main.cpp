#include <stdio.h>
#include <opencv2/opencv.hpp>
//#include <vector>
//#include <algorithm>    // std::random_shuffle
//#include <ctime>        // std::time
//#include <cstdlib>      // std::rand, std::srand
//#include <cmath>

using namespace cv;

int myrandom(int i) { return std::rand() % i; }
std::vector<int> starMapGen(Mat& view);

int main()
{
    std::srand(unsigned(std::time(0))); //seed
    Mat mainview(Size(960, 540), CV_64FC3);
    namedWindow("mainview", WINDOW_NORMAL);
    cv::setWindowProperty("mainview", WND_PROP_FULLSCREEN, WINDOW_FULLSCREEN);
    Mat outimg(Size(960, 540), CV_64FC3);
    //hauptschleife
    outimg = mainview;
    resize(outimg, outimg, Size(0, 0), 2, 2, INTER_AREA);
    imshow("mainview", outimg);
    waitKey(0);
    starMapGen(mainview);
    outimg = mainview;
    resize(outimg, outimg, Size(0, 0), 2, 2, INTER_AREA);
    imshow("mainview", outimg);

    waitKey(0);
    return 0;
}

std::vector<int> starMapGen(Mat& view)
{
    std::vector<int> starlist;
    std::vector<Mat> view_vec;
    cv::split(view, view_vec);
    for (int y = 0; y < view.size().height; y++)
    {
        for (int x = 0; x < view.size().width; x++)
        {
            view_vec.at(2).at<double>(y, x) = std::max(myrandom(100000)-99000,0)/1000.;
            view_vec.at(1).at<double>(y, x) = view_vec.at(2).at<double>(y, x)*std::min(myrandom(1000) + 600, 1000)/1000.;
            view_vec.at(0).at<double>(y, x) = (view_vec.at(1).at<double>(y, x)*std::min(myrandom(1000) + 500, 1000+2*(int(500-view_vec.at(2).at<double>(y, x)*1000)))/1000.);
            if (view_vec.at(2).at<double>(y, x)>0.)
            {
                starlist.push_back(1);
            }
        }
    }
    merge(view_vec, view);
    return starlist;
}