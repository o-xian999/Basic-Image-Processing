#include <stdio.h>
#include <opencv2/oppencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

Mat img_src, img_dst;

int main(){
  char key;

  VideoCapture cap(0);
  cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);
  cap.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
  nameWindow("camera", CV_WINDOW_AUTOSIZE);

  while(1){
    cap >> img_src;
    imshow("camera", img_src);

    key = waitKey(10);
    if (key == 'q') break;
    else if (key == 's') imwrite("output.jpg", img_src);
  }

  destroyAllWindows();
  return 0;
}
