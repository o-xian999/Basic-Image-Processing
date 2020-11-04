#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

#define getV(img,x,y) (img.ptr<uchar>(y)[(x)])
#define setB(img,x,y,v) (img.ptr<uchar>(y)[(x)*3]=(v))
#define setG(img,x,y,v) (img.ptr<uchar>(y)[(x)*3+1]=(v))
#define setR(img,x,y,v) (img.ptr<uchar>(y)[(x)*3+2]=(v))

void labeling(Mat& img_bin, vector<vector<int> >& label_map) {
	int x, y;
	uchar v1, v2;
	int l, l1, l2;
	vector<int> label;
	int m, n;

	label_map = vector<vector<int> >(img_bin.rows, vector<int>(img_bin.cols));
	m = n = 1;

	label.push_back(0);
	for (y=0; y < img_bin.rows; y++) {
	for (x=0; x < img_bin.cols; x++) {
		if (getV(img_bin, x, y)==0) {
			; // background:0
		} else if (x==0 && y==0) {
			label_map[y][x] = m;
			label.push_back(m);
			m++;
		} else if (y==0) {
			v1 = getV(img_bin, x-1, y);
			if (v1==255) {
				l = label_map[y][x-1];
				label_map[y][x] = l;
			} else {
				label_map[y][x] = m;
				label.push_back(m);
				m++;
			}
		} else if (x==0) {
			v2 = getV(img_bin, x, y-1);
			if (v2==255) {
				l = label_map[y-1][x];
				label_map[y][x] = l;
			} else {
				label_map[y][x] = m;
				label.push_back(m);
				m++;
			}
		} else {
			v1 = getV(img_bin, x-1, y);
			v2 = getV(img_bin, x, y-1);
			if (v1==255 && v2==255) {
				l1 = label_map[y][x-1];
				l2 = label_map[y-1][x];
				if (l1 == l2) {
					label_map[y][x] = l1;
				} else if (l2 < l1) {
					label_map[y][x] = l2;
					label[l1] = l2;
				} else if (l1 < l2) {
					label_map[y][x] = l1;
					label[l2] = l1;
				}
			} else if (v1==255) {
				l = label_map[y][x-1];
				label_map[y][x] = l;
			} else if (v2==255) {
				l = label_map[y-1][x];
				label_map[y][x] = l;
			} else {
				label_map[y][x] = m;
				label.push_back(m);
				m++;
			}
		}
	}
	}

	for (l=1; l<m; l++) {
		if (label[l] == l) {
			if (l != n) {		
				label[l] = n;
			}
			n++;
		} else {
			label[l] = label[label[l]];
		}
	}

	for (y=0; y < img_bin.rows; y++) {
	for (x=0; x < img_bin.cols; x++) {
		l = label[label_map[y][x]];
		if (l != 0) {
			label_map[y][x] = l;
		}
	}
	}
}

void labelingImg(Mat& img_bin, Mat& img_col) {
	int x, y;
	int l, hue;
	uchar r, g, b;
	vector<vector<int> > label_map;
	uchar colors[10][3] = {{  0,  0,255}, {255,  0,  0}, {  0,255,  0},
	                       {  0,255,255}, {255,255,  0}, {255,  0,255},
	                       {  0,127,255}, {255,127,  0}, {255,  0,127},
	                       {  0,255,127}};

	labeling(img_bin, label_map);
	for (y=0; y < img_bin.rows; y++) {
	for (x=0; x < img_bin.cols; x++) {
		l = label_map[y][x];
		if (l == 0) {
			r = g = b = 0;
		} else {
			r = colors[(l-1)%10][0];
			g = colors[(l-1)%10][1];
			b = colors[(l-1)%10][2];
		}
		setR(img_col, x, y, r);
		setG(img_col, x, y, g);
		setB(img_col, x, y, b);
	}
	}
}
