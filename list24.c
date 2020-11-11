#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

Mat img_src, img_dx, img_dy, img_dst;

int main(int argc, char* argv[]) {
  char key;

  Mat dx = (Mat_<double>(3, 3) <<
   -1, 0, 1,
   -1, 0, 1,
   -1, 0, 1
  );
  Mat dy = (Mat_<double>(3, 3) <<
   -1, -1, -1,
    0,  0,  0,
   -1,  1,  1
  );
  
  img_src = imread(argv[1], 0);
  filter2D(img_src, img_dx, CV_32F, dx);
  filter2D(img_src, img_dy, CV_32F, dy);
  pow(img_dx, 2, img_dx);
  pow(img_dy, 2, img_dy);
  sqrt(img_dx+img_dy, img_dst);
  convertScaleAbs(img_dst, img_dst, 1, 0);

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