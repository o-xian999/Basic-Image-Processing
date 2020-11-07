#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/highgui/highgui.hpp> 

using namespace cv;

#define getV(img, x, y) (img.ptr<uchar>(y)[(x)])

Mat img_src, img_his;

int main (int argc, char* argv[]) {
  char key;
  uchar value;
  int histgram[256] = {};

  img_src = imread(argv[1], 0);
  img_his = Mat::zeros(100, 256, CV_8UC1);

  for (int y = 0; y < img_src.rows; y++) {
    for (int x = 0; x < img_src.cols; x++) {
      value = getV(img_src, x, y);
      histgram[value]++;
    }
  }

  for(int i = 0; i < 256; i++) {
    line(img_his, Point(i, 99), Point(i, 99-histgram[i]/30),
      CV_RGB(255, 255, 255));
  }
  namedWindow(argv[1], CV_WINDOW_AUTOSIZE);
  namedWindow("histgram", CV_WINDOW_AUTOSIZE);

  while (1) {
    imshow(argv[1], img_src);
    imshow("histgram", img_his);

    key = waitKey(10);
    if (key == 'q') break;
    else if (key == 's') imwrite("histgram.jpg", img_his);
  }

  destroyAllWindows();
  return 0;
}