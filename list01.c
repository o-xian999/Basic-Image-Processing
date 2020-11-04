#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

Mat img_src, img_dst;

int main(){
  char key;

  namedWindow("image", CV_WINDOW_AUTOSIZE);

  while(1){
    img_src = imread("Lenna.jpg");
    imshow("image", img_src);

    key = waitKey(10);
    if (key == 'q') break;
    else if (key == 's') imwrite("output.jpg", img_src);
  }

  destroyAllWindows();
  return 0;
}
