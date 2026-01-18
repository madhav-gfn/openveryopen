#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;
using namespace cv;
Mat mask;
int hmin=0, smin=110, vmin=153;
int hmax = 19, smax = 240, vmax = 255;
int main() {
	string p = "C:\\Users\\madmi\\OneDrive\\Desktop\\OIP (2).jpg";
	Mat img = imread(p), imgHSV;
	cvtColor(img, imgHSV, COLOR_BGR2HSV);
	Scalar lower(hmin, smin, vmin);
	Scalar upper(hmax, smax, vmax);
	inRange(imgHSV,lower, upper, mask);
	imshow("Display window", img);
	imshow("Display", imgHSV);
	imshow("mask", mask);
	waitKey(0);
	return 0;
}


