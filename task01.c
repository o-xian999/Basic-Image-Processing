#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp> 

using namespace cv;

#define getV(img, x, y) (img.ptr<uchar>(y)[(x)])
#define setV(img, x, y, v) (img.ptr<uchar>(y)[(x)] = (v))

Mat img_src, img_dst;

int main(int argc, char* argv[]) {
  char key;
  uchar v_src, v_dst;

  img_src = imread(argv[1], 0);
  img_dst = Mat::zeros(img_src.rows, img_src.cols, CV_8UC1);
  for (int y = 0; y < img_src.rows; y++) {
    for (int x = 0; x < img_src.cols; x++) {
      v_src = getV(img_src, x, y);
      if (v_src < 32) {
        v_dst = 0;
      } else if (v_src < 64) {
        v_dst = 36;
      } else if (v_src < 96) {
        v_dst = 72;
      } else if (v_src < 128) {
        v_dst = 108;
      } else if (v_src < 160) {
        v_dst = 144;
      } else if (v_src < 192) {
        v_dst = 180;
      } else if (v_src < 224) {
        v_dst = 216
      } else if {
        v_dst = 255;
      }
      setV(img_dst, x, y, v_dst);
    }
  }

  namedWindow(argv[1], CV_WINDOW_AUTOSIZE);
  namedWindow("output", CV_WINDOW_AUTOSIZE);

  while (1) {
    imshow(argv[1], img_src);
    imshow("output", img_dst);

    key = waitKey(10);
    if (key == 'q') break;
    else if (key == 's') imwrite("output.jpg", img_dst);
  }

  destroyAllWindows();
  return 0;
}