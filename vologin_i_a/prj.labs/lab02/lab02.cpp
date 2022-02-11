#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img = cv::imread("../data/cross_0256x0256.png");
    cv::imwrite("../data/cross_0256x0256.jpg", img,{cv::IMWRITE_JPEG_CHROMA_QUALITY,10});
    cv::Mat imgl = cv::imread("cross_0256x0256.jpg");

    cv::waitKey(0);
}