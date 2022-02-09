#include <opencv4/opencv2/opencv.hpp>

#define WIGHT 768
#define HIGHT 180
#define GAMMA1 2.2
#define GAMMA2 2.4

int main(){
  cv::Mat m(HIGHT, WIGHT, CV_8UC1);
  cv::Rect2d rc = {0, 0, 768, 60};
  float invGamma1 = 1.0f / GAMMA1;
  float invGamma2 = 1.0f / GAMMA2;

  int CIndex{0};
  for (int y{0}; y < HIGHT; ++y)
    for (int x{0}; x < WIGHT; ++x)
      m.at<uchar>(y, x) = x % 3 == 0 ? CIndex++ : CIndex;

  cv::rectangle(m, rc, {150}, 1);
  rc.y += rc.height;

  cv::Mat tmp{m};
  tmp.convertTo(tmp,CV_64FC1);
  tmp = (tmp/255.0f);
  cv::pow(tmp,invGamma1,tmp);
  tmp = tmp * 255.0f;
  tmp.convertTo(tmp,CV_8UC1);

  for (int y = rc.y; y < HIGHT - rc.height; ++y)
    for (int x{0}; x < WIGHT; ++x)
      m.at<uchar>(y, x) =  tmp.at<uchar>(y,x);
 
  cv::rectangle(m, rc, {150}, 1);
  rc.y += rc.height;

  for (int y = rc.y; y < HIGHT; ++y)
    for (int x{0}; x < WIGHT; ++x)
      m.at<uchar>(y, x) = pow(m.at<uchar>(y, x) / 255.0f, invGamma2) * 255.0f;
      

  cv::rectangle(m, rc, {150}, 1);

  cv::imshow("lab01",m);
  cv::waitKey(0);
}

