#include <stdio.h>
#include <opencv2/oppencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp> 

using namespace cv;

Mat img_src, img_dst;

void thinningImg(Mat& img_bin); //配布関数

int main(int argc, char* argv[]) {
  char key;

  Mat mi = (Mat_<double>(2, 3) <<
    1.5, 0.0, 0,
    0.0, 1.5, 0;
    //cos(M_PI / 6), -sin(M_PI / 6), 0,
    //sin(M_PI / 6), cos(M_PI / 6), 0;
    //1.0, tan(M_PI / 6), 0,
    //0.0, 1.0.           0
  );

  img_src = imread(argv[1]);
  warpAffine(img_src, img_dst, m1, img_src.size());

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