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
Mat matrix;
float w = 500, h = 700;
/// <summary>
/// ////////////////////////////draw and text/////////////////////////////
/// </summary>
void main() {

    Mat img = imread("C:\\Users\\madmi\\OneDrive\\Desktop\\card.png");
	Mat warped;
	Point2f src[4] = { {39,193},  {197,164},{58,373}, {236,334} };
	Point2f dst[4] = { {0.0f,0.0f}, {w ,0.0f}, {0.0f,h }, {w ,h } };
	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, warped, matrix, Point(w, h));

	imshow("Original Image", warped);
    imshow("Display window", img);

    waitKey(0);



}