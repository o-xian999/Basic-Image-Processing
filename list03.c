#include <stdio.h>
#include <opencv2/oppencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp> 

#define getB(img, x, y) (img.ptr<ucahr>(y)[(x)*3])
#define getG(img, x, y) (img.ptr<ucahr>(y)[(x)*3+1])
#define getR(img, x, y) (img.ptr<ucahr>(y)[(x)*3+2])

using namespace cv;

Mat img_src;

void on_mouse(int event, int x, int y, int flag, void *param){
  uchar r, g, b;

  switch(event){
    case CV_EVENT_LBUTTONDOWN:
      r = getR(img, x, y);
      g = getG(img, x, y);
      b = getB(img, x, y);
      printf("(x:%3d y:%3d) (R:%3d G:%3d B:%3d)\n", x, y, r, g, b);
      break;
  }
}

int main () {
  cahr key;

  VideoCapture cap(0);
  cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);
  cap.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
  namedWindow("camera", on_mouse, NULL);

  while (1) {
    cap >> img_src;
    imshow("camera", img_src);

    key = waitKey(10);
    if (key == 'q') break;
    else if (key == 's') imwrite("output.jpg", img_src);
  }

  destroyAllWindow();
  return 0;
}
