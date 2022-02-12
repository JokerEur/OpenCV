#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;

int main()
{

// Mat src_rgb_img = imread("../data/cross_0256x0256.png");
// imwrite("cross_0128x0128.jpg", src_rgb_img, { IMWRITE_JPEG_QUALITY, 25 });
// //compressed img
// Mat img025 = imread("cross_0128x0128.jpg");

// int hist_size = 256;
// float range[] = { 0, 256 };
// const float* hist_range = { range };
// int hist_w = 512, hist_h = 256;
// //original rgb channels
// Mat bgr[3];
// split(src_rgb_img, bgr);
// Mat src_img_ch(512, 512, CV_8UC3);
// Mat src_gray_img3;
// cvtColor(src_gray_img, src_gray_img3, COLOR_GRAY2BGR);
// Mat color[3], g = Mat::zeros(Size(256, 256), CV_8UC1);

// merge(std::vector<Mat>({ bgr[0], g, g }), color[0]);
// merge(std::vector<Mat>({ g, bgr[1],g }), color[1]);
// merge(std::vector<Mat>({ g, g, bgr[2] }), color[2]);

// src_gray_img3.copyTo(src_img_ch(Rect(0, 0, 256, 256)));
// color[0].copyTo(src_img_ch(Rect(256, 256, 256, 256)));
// color[1].copyTo(src_img_ch(Rect(0, 256, 256, 256)));
// color[2].copyTo(src_img_ch(Rect(256, 0, 256, 256)));
// imwrite("cross_0256x0256_png_rgb_channels.png", src_img_ch);

}