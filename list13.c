#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/highgui/highgui.hpp> 

using namespace cv;

Mat img_src, img_bin, img_dst;

void labelingImg(Mat& img_bin, Mat& img_col); //配布関数

int main(int argc, char* argv[]) {
  char key;

  img_src = imread(argv[1], 0);
  threshold(img_src, img_bin, 120, 255, THRESH_BINARY_INV);
  img_dst = Mat::zeros(img_src.rows, img_src.cols, CV_8UC3);
  labelingImg(img_bin, img_dst);

  namedWindow(argv[1], CV_WINDOW_AUTOSIZE);
  namedWindow("output", CV_WINDOW_AUTOSIZE);

  while (1) {
    imshow(argv[1], img_bin);
    imshow("output", img_dst);

    key = waitKey(10);
    if (key == 'q') break;
    else if (key == 's') imwrite("output.jpg", img_dst);
  }
  
  destroyAllWindows();
  return 0;
}