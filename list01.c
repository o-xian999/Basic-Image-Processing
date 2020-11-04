#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/highgui/highgui.hpp>

// OpenCVのクラスや関数は、cv名前空間に格納されている。
using namespace cv;

// Cでは画像を扱うとき基本こう書く。
// unsigned char img[480][640][3]
// しかしこれは静的な配列で、サイズの変更はできない。
// Mat(Matrics)型の変数img_sourceとimg_destinationを宣言する。
// 実態はオブジェクト。
Mat img_src, img_dst;

int main(){
  char key;

  // ""で囲む。第二引数はウィンドウのオプションを指定。
  // imageというウィンドウのためのメモリを確保
  namedWindow("image", CV_WINDOW_AUTOSIZE);

  // 組み込みでよく使うのが無限ループ。
  while(1){
    // imreadは第二引数(オプション)を指定できる。例えば0と書いたら、グレースケール画像が出力。
    img_src = imread("Lenna.jpg");
    // 上下反転は0。左右難点は1。
    //flipでsrcを処理し、dstに格納。
    flip(img_src, img_dst, 1);
    imshow("image", img_dst);

    // cv名前空間のhighguiで提供されている関数waitKey()
    // キーボードの位置文字を読み取る
    key = waitKey(10);
    // ウィンドウをアクティブにしてqを叩くと消える。
    if (key == 'q') break;
    // 処理した結果の画像ファイルを、output.jpgという名前で出力。
    else if (key == 's') imwrite("output.jpg", img_dst);
  }

  // ウィンドウ用に確保したメモリを開放。マナーみたいなもの。
  destroyAllWindows();
  return 0;
}
