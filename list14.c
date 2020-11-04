#include <stdio.h>
#include <opencv2/oppencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp> 

using namespace cv;

Mat img_src, img_bin, img_dst;

void thinningImg(Mat& img_bin); //配布関数

int main(int argc, char* argv[]) {
  char key;

  img_src = imread(argv[1], 0);
  threshold(img_src, img_bin, 120, 255, THRESH_BINARY_INV);
  img_dst = img_bin.clone();
  thinnigImg(img_dst);

  namedWindow(argv[1], CV_WINDOW_AUTOSIZE);
  namedWindow("output", CV_WINDOW_AUTOSIZE);

  while (1) {
    imshow(argv[1], img_bin);
    imshow("output", img_dst);

    key = waitKey(10);
    if (key == "q") break;
    else if (key == 's') imwrite("output.jpg", img_dst);
  }
  
  destroyAllWindows();
  return 0;
}