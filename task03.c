#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

Mat img_src, img_dst;

int main(int argc, char *argv[])
{
  char key;

  Mat gau3 = (Mat_<float>(3, 3) << 1, 2, 1,
              2, 4, 2,
              1, 2, 1) /
             16;

  Mat gau5 = (Mat_<float>(5, 5) << 1, 4, 6, 4, 1,
              4, 16, 24, 16, 4,
              6, 24, 36, 24, 6,
              4, 16, 24, 16, 4,
              1, 4, 6, 4, 1) /
             256;

  img_src = imread(argv[1]);
  GaussianBlur(img_src, img_dst, Size(3, 3), 3);
  filter2D(img_src, img_dst, CV_8U, gau3);

  namedWindow(argv[1], CV_WINDOW_AUTOSIZE);
  namedWindow("output", CV_WINDOW_AUTOSIZE);

  while (1)
  {
    imshow(argv[1], img_src);
    imshow("output", img_dst);

    key = waitKey(10);
    if (key == 'q')
      break;
    else if (key == 's')
      imwrite("output.jpg", img_dst);
  }

  destroyAllWindows();
  return 0;
}