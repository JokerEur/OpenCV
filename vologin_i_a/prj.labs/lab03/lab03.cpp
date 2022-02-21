#include <opencv2/opencv.hpp>
#include <cmath>

uint32_t BrightnessConvertion(const uint32_t color)
{
    return static_cast<uint32_t>(255 * 10 * fabs(sinf32(static_cast<float>(color) / (255.0f * 3.0f))) + 0.5f) % 256;
}

int main()
{

    cv::Mat InitialImage = cv::imread("../data/cross_0256x0256.png");

    cv::imwrite("lab03_rgb.png", InitialImage);

    cv::Mat GreyScale;
    cv::cvtColor(InitialImage, GreyScale, cv::COLOR_BGR2GRAY);
    cv::imwrite("lab03_grey.png", GreyScale);

    cv::Mat LookUpTable(1, 256, CV_8UC1);

    for (ptrdiff_t i{0}; i < 256; ++i)
        LookUpTable.at<uchar>(0, i) = BrightnessConvertion(i);

    cv::Mat result_for_initial, result_for_greyscale;
    cv::LUT(InitialImage, LookUpTable, result_for_initial);
    cv::LUT(GreyScale, LookUpTable, result_for_greyscale);

    cv::imwrite("lab03_gre_res.png", result_for_greyscale);
    cv::imwrite("lab03_rgb_res.png", result_for_initial);
}