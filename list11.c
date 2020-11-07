#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/highgui/highgui.hpp> 

using namespace cv;

Mat img_src, img_bin, img_dst;

int main(int argc, char* argv[]) {
  char key;
  Mat element4 = (Mat_<uchar>(3, 3) << 0, 1, 0, 1, 1, 1, 0, 1, 0);
  Mat element8 = (Mat_<uchar>(3, 3) << 1, 1, 1, 1, 1, 1, 1, 1, 1);

  img_src = imread(argv[1], 0);
  threshold(img_src, img_bin, 120, 255, THRESH_BINARY_INV);
  dilate(img_bin, img_dst, element4, Point(-1, -1), 1);
  //erode(img_bin, img_dst, element4, Point(-1, -1), 1);

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