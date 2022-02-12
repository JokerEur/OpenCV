#include <opencv4/opencv2/opencv.hpp>
#include <chrono>


#define WIGHT 768
#define HIGHT 180
#define GAMMA1 2.2
#define GAMMA2 2.4

int main()
{
  cv::Mat m(HIGHT, WIGHT, CV_8UC1);
  m = 0;
  cv::Rect2d rc = {0, 0, 768, 60};

  for (ptrdiff_t y{0}; y < HIGHT; ++y)
    for (ptrdiff_t x{0}; x < WIGHT; ++x)
      m.at<uchar>(y, x) = x / 3;

  cv::rectangle(m, rc, {150}, 1);
  rc.y += rc.height;

  auto start = std::chrono::high_resolution_clock::now();
  cv::Mat tmp{m};
  tmp.convertTo(tmp, CV_32FC1, 1.0f / 255.0f);
  cv::pow(tmp, GAMMA1, tmp);
  tmp.convertTo(tmp, CV_8UC1, 255.0f);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << "Time for G1 = " << duration.count() << " μs"
            << "\n";

  tmp(rc).copyTo(m(rc));

  cv::rectangle(m, rc, {150}, 1);
  rc.y += rc.height;

  start = std::chrono::high_resolution_clock::now();
  for (ptrdiff_t y = rc.y; y < HIGHT; ++y)
    for (ptrdiff_t x{0}; x < WIGHT; ++x)
      m.at<uchar>(y, x) = pow(m.at<uchar>(y, x) / 255.0f, GAMMA2) * 255.0f;

  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
  std::cout << "Time for G2 = " << duration.count() << " μs"
            << "\n";

  cv::rectangle(m, rc, {150}, 1);

  cv::imwrite("lab01.png",m);
}