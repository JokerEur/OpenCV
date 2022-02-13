#include <opencv2/opencv.hpp>
#include <vector>

int main()
{
    using namespace cv;

    Mat src_rgb_img = imread("../data/cross_0256x0256.png");
    imwrite("cross_0256x0256_025.jpg", src_rgb_img, {IMWRITE_JPEG_QUALITY, 25});

    Mat img025 = imread("../data/cross_0256x0256_025.jpg");

    int hist_size = 256;
    float range[] = {0, 256};
    const float *hist_range = {range};
    int hist_w = 512, hist_h = 256;

    Mat bgr[3];
    split(src_rgb_img, bgr);
    Mat color[3], g = Mat::zeros(Size(256, 256), CV_8UC1);
    Mat src_img_ch(512, 512, CV_8UC3);

    merge(std::vector<Mat>({bgr[0], g, g}), color[0]);
    merge(std::vector<Mat>({g, bgr[1], g}), color[1]);
    merge(std::vector<Mat>({g, g, bgr[2]}), color[2]);

    src_rgb_img.copyTo(src_img_ch(Rect(0, 0, 256, 256)));
    color[0].copyTo(src_img_ch(Rect(256, 256, 256, 256)));
    color[1].copyTo(src_img_ch(Rect(0, 256, 256, 256)));
    color[2].copyTo(src_img_ch(Rect(256, 0, 256, 256)));
    imwrite("cross_0256x0256_png_channels.png", src_img_ch);

    // Mat b_hist;
    // calcHist(&color[0], 1, 0, Mat(), b_hist, 1, &hist_size, &hist_range,
    //          true, false);

    Mat bgr025[3];
    split(img025, bgr025);
    Mat color025[3];

    merge(std::vector<Mat>({bgr025[0], g, g}), color025[0]);
    merge(std::vector<Mat>({g, bgr025[1], g}), color025[1]);
    merge(std::vector<Mat>({g, g, bgr025[2]}), color025[2]);

    Mat img_ch025(512, 512, CV_8UC3);

    img025.copyTo(img_ch025(Rect(0, 0, 256, 256)));
    color025[0].copyTo(img_ch025(Rect(256, 256, 256, 256)));
    color025[1].copyTo(img_ch025(Rect(0, 256, 256, 256)));
    color025[2].copyTo(img_ch025(Rect(256, 0, 256, 256)));

    imwrite("cross_0256x0256_jpg_channels.png", img_ch025);
}