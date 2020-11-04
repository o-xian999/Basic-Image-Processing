#include <stdio.h>
#include <opencv2/oppencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp> 

using namespace cv;

Mat img_src, img_dst;

int main(int argc, char* argv[]) {
  char key;

  Mat m1 = (Mat_<double>(3, 3) <<
   -1.0, 0.0, 0,
    0.0, 1.0, 0;
    0,   0,   1
  );
  Mat m2 = (Mat_<double>(3, 3) <<
    cos(M_PI / 2), -sin(M_PI / 2), 0,
    sin(M_PI / 2),  cos(M_PI / 2), 0,
    0,              0,             1
  );
  Mat m3 = m1 * m2;
  m3.resize(2);

  img_src = imread(argv[1]);
  warpAffine(img_src, img_dst, m3, img_src.size());

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