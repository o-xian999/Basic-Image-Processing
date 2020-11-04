#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

Mat img_src, img_dst;

int main(){
  char key;

  // OpenCVでカメラキャプチャ。
  // VideoCaptureクラスの変数を宣言。
  VideoCapture cap(0);
  // キャプチャするビデオ画像の大きさを指定。
  cap.set(CAP_PROP_FRAME_WIDTH, 640);
  cap.set(CAP_PROP_FRAME_HEIGHT, 480);
  namedWindow("camera", CV_WINDOW_AUTOSIZE);

  while(1){
    // カメラ画像を読み込み(カメラ読み込み演算子)。
    cap >> img_src;
    imshow("camera", img_src);

    key = waitKey(10);
    if (key == 'q') break;
    else if (key == 's') imwrite("output.jpg", img_src);
  }

  destroyAllWindows();
  return 0;
}
