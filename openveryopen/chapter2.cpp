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
int main() {
	string p = "C:\\Users\\madmi\\OneDrive\\Desktop\\test.jpg";
		Mat img = imread(p);
		Mat gray;
		Mat imgb,canny;
		cvtColor(img, gray, COLOR_BGR2GRAY);
		GaussianBlur(img, imgb, Size(3, 3), 1.5, 1.5);
		Canny(imgb, canny, 25, 75);
		if (img.empty()) {
			cout << "Could not read the image: " << p <<endl;
			return 1;
		}
		imshow("Display window", img);
		imshow("Display", gray);
		imshow("blur", imgb);
		imshow("canny", canny);
		waitKey(0);
		return 0;
}


