#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

#define getV(img,x,y) (img.ptr<uchar>(y)[(x)])
#define setV(img,x,y,v) (img.ptr<uchar>(y)[(x)]=(v))

void getElement9(Mat& img, int x, int y, int v[9]) {

	v[0] = (getV(img, x  , y  )==255) ? 1 : 0;
	v[1] = (getV(img, x+1, y  )==255) ? 1 : 0;
	v[2] = (getV(img, x+1, y+1)==255) ? 1 : 0;
	v[3] = (getV(img, x  , y+1)==255) ? 1 : 0;
	v[4] = (getV(img, x-1, y+1)==255) ? 1 : 0;
	v[5] = (getV(img, x-1, y  )==255) ? 1 : 0;
	v[6] = (getV(img, x-1, y-1)==255) ? 1 : 0;
	v[7] = (getV(img, x  , y-1)==255) ? 1 : 0;
	v[8] = (getV(img, x+1, y-1)==255) ? 1 : 0;
}

void thinningImg(Mat& img_bin) {
	int x, y;
	int v[9];

	for (y=1; y<img_bin.rows-1; y++) {
	for (x=1; x<img_bin.cols-1; x++) {
		getElement9(img_bin, x, y, v);
		if (v[0] == 0) {
			continue;
		} else if (v[2]*v[3]*v[4]==1 && v[6]+v[7]+v[8]==0) {
			setV(img_bin, x, y, 0);
		} else if (v[1]*v[2]*v[3]==1 && v[5]+v[6]+v[7]==0) {
			setV(img_bin, x, y, 0);
		} else if (v[1]*v[2]*v[8]==1 && v[4]+v[5]+v[6]==0) {
			setV(img_bin, x, y, 0);
		}
	}
	}

	for (y=img_bin.rows-1; y>1; y--) {
	for (x=img_bin.cols-1; x>1; x--) {
		getElement9(img_bin, x, y, v);
		if (v[0] == 0) {
			continue;
		} else if (v[6]*v[7]*v[8]==1 && v[2]+v[3]+v[4]==0) {
			setV(img_bin, x, y, 0);
		} else if (v[5]*v[6]*v[7]==1 && v[1]+v[2]+v[3]==0) {
			setV(img_bin, x, y, 0);
		} else if (v[4]*v[5]*v[6]==1 && v[1]+v[2]+v[8]==0) {
			setV(img_bin, x, y, 0);
		}
	}
	}

	for (y=1; y<img_bin.rows-1; y++) {
	for (x=img_bin.cols-1; x>1; x--) {
		getElement9(img_bin, x, y, v);
		if (v[0] == 0) {
			continue;
		} else if (v[4]*v[5]*v[6]==1 && v[1]+v[2]+v[8]==0) {
			setV(img_bin, x, y, 0);
		} else if (v[3]*v[4]*v[5]==1 && v[1]+v[7]+v[8]==0) {
			setV(img_bin, x, y, 0);
		} else if (v[2]*v[3]*v[4]==1 && v[6]+v[7]+v[8]==0) {
			setV(img_bin, x, y, 0);
		}
	}
	}

	for (y=img_bin.rows-1; y>1; y--) {
	for (x=1; x<img_bin.cols-1; x++) {
		getElement9(img_bin, x, y, v);
		if (v[0] == 0) {
			continue;
		} else if (v[1]*v[2]*v[8]==1 && v[4]+v[5]+v[6]==0) {
			setV(img_bin, x, y, 0);
		} else if (v[1]*v[7]*v[8]==1 && v[3]+v[4]+v[5]==0) {
			setV(img_bin, x, y, 0);
		} else if (v[6]*v[7]*v[8]==1 && v[2]+v[3]+v[4]==0) {
			setV(img_bin, x, y, 0);
		}
	}
	}
}
