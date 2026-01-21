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
#include <opencv2/objdetect.hpp>
using namespace std;
using namespace cv;
int main() {
	string p = "C:\\Users\\madmi\\OneDrive\\Desktop\\test.jpg";
	Mat img = imread(p);
	CascadeClassifier faceCascade;
	faceCascade.load("D:\\opencv\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalface_default.xml");
	if(faceCascade.empty()) {
		cout << "Could not load classifier cascade" << endl;
		return -1;
	}
	vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces, 1.1, 10, 0, Size(30, 30));
	for (int i = 0; i < faces.size(); i++) {
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 2);
	}
	imshow("Display window", img);
	waitKey(0);
	return 0;
}


