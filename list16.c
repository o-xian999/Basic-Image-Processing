#include <stdio.h>
#include <opencv2/oppencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp> 

using namespace cv;

Mat img_src, img_dst;

int main(int argc, char* argv[]) {
  char key;

  Mat mi = (Mat_<double>(2, 3) <<
    1.0, 0.0, 50,                        //平行移動
    0.0, 1.0, 50;
    //cos(M_PI / 4), -sin(M_PI / 4), 128, //回転 + 平行移動
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