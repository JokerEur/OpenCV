#include <opencv2/opencv.hpp>
#include <cmath>

uint32_t BrightnessConvertion(const uint32_t color)
{
    return static_cast<uint32_t>(128.0f * (sinf(color / 8.0f) + 1.0f));
}

int main()
{

    cv::Mat InitialImage = cv::imread("../data/cross_0256x0256.png");
    if (InitialImage.empty())
        std::cout << "could not find image"
                  << "\n";

    cv::Mat m(180, 768, CV_8UC1);
    m = 0;

    for (ptrdiff_t y{0}; y < 180; ++y)
        for (ptrdiff_t x{0}; x < 768; ++x)
            m.at<uchar>(y, x) = x / 3;

    cv::imwrite("lab03_rgb.png", InitialImage);

    cv::Mat GreyScale;
    cv::cvtColor(InitialImage, GreyScale, cv::COLOR_BGR2GRAY);
    cv::imwrite("lab03_grey.png", GreyScale);

    cv::Mat LookUpTable(1, 256, CV_8UC1);

    for (ptrdiff_t i{0}; i < 256; ++i)
        LookUpTable.at<uchar>(0, i) = BrightnessConvertion(i);

    cv::Mat ResultForInitial, ResultForGreyscale, ResultForChecker;
    cv::LUT(m, LookUpTable, ResultForChecker);
    cv::LUT(InitialImage, LookUpTable, ResultForInitial);
    cv::LUT(GreyScale, LookUpTable, ResultForGreyscale);

    cv::imwrite("lab03_gre_res.png", ResultForGreyscale);
    cv::imwrite("lab03_rgb_res.png", ResultForInitial);
    cv::imwrite("lab03_checker.png", ResultForChecker);

    cv::Mat FunctionVisualization(512, 512, CV_8UC1, 255);
    for (ptrdiff_t i{0}; i < 512; i += 2)
        FunctionVisualization.at<uchar>(512 - 2 * LookUpTable.at<uchar>(0, i / 2) - 1, i) = 0;

    cv::imwrite("lab03_viz_func.png", FunctionVisualization);
}