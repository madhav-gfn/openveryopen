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
void main() {
	string p = "C:\\Users\\madmi\\OneDrive\\Desktop\\test.jpg";;
	Mat img=imread(p);
	Mat rezizedimg,imgcrop;
	cout << img.size()<<endl;
	resize(img, rezizedimg, Size(), 0.5, 0.5);
	//crop the image
	Rect roi(100, 100, 300, 300);
	imgcrop = img(roi);
	imshow("Display window", img);
	cout << rezizedimg.size() << endl;
	//fullscreen the resized image window

	imshow("rezized window", rezizedimg);
	imshow("cropped image", imgcrop);
	waitKey(0);

	

}