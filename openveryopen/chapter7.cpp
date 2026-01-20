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
int hmin = 0, smin = 110, vmin = 153;
int hmax = 19, smax = 240, vmax = 255;
void getcontours(Mat imgdil, Mat img) {
	vector<vector<Point>> contours;
	vector<Vec4i> heirarchy;
	findContours(imgdil, contours, heirarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());
	string objtype;
	for (int i = 0; i < contours.size(); i++) {
		double area = contourArea(contours[i]);
		if (area > 1000) {
			cout << area << endl;
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 5);
			cout << conPoly[i].size() << endl;
			 boundRect[i]=boundingRect(conPoly[i]);
			 rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
			int objcor = (int)conPoly[i].size();
			if (objcor == 3) {
				objtype = "triangle";
			}
			else if(objcor==4){
				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
				if (aspRatio > 0.95 && aspRatio < 1.05) {
					objtype = "square";
				}
				else {
					objtype = "rectangle";
				}
			}
			else if (objcor > 4) {
				objtype = "circle";
			}
			else {
				objtype = "none";
			}
			putText(img, objtype, { boundRect[i].x, boundRect[i].y - 10 }, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 2);

		}
	}
}
int main() {
	string p = "C:\\Users\\madmi\\OneDrive\\Desktop\\lr.jpg";
	Mat img = imread(p), grey,dila, imgcanny,blur;
	resize(img, img, Size(), 0.5, 0.5);
	cvtColor(img, grey, COLOR_BGR2GRAY);
	
	GaussianBlur(grey, blur, Size(3, 3), 3, 0);
	Canny(img, imgcanny, 60, 100);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	dilate(imgcanny, dila, kernel);
	getcontours(dila, img);
	imshow("Display window", img);
	//imshow("gray", grey);
	//imshow("dilate", dila);
	//imshow("canny", imgcanny);
	//imshow("blur", blur);
	waitKey(0);

	return 0;
}


