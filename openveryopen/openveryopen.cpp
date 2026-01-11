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
//.........................image..................//
//int main() {
//	string p = "C:\\Users\\madmi\\OneDrive\\Desktop\\test.jpg";
//	Mat img = imread(p);
//	if (img.empty()) {
//		cout << "Could not read the image: " << p <<endl;
//		return 1;
//	}
//	imshow("Display window", img);
//	waitKey(0);
//	return 0;
//}
//..................video...............//
//void main() {
//	string p = "C:\\Users\\madmi\\OneDrive\\Desktop\\test.mp4";
//	VideoCapture cap(p);
//	Mat img;
//	while (true) {
//		cap.read(img);
//		imshow("Display window", img);
//		waitKey(50);
//
//	}
//
//}


//..................webcam...............//
//void main() {
//	VideoCapture cap(0);
//	Mat img;
//	while (true) {
//		cap.read(img);
//		imshow("Display window", img);
//		waitKey(1);
//
//	}
//
//}





//..................edge camera...............//

int main(int argc, char** argv)
{
    // Declare the output variables
    Mat dst, cdst, cdstP;

    /*const char* default_file = "test.jpg";
    const char* filename = argc >= 2 ? argv[1] : default_file;*/
    VideoCapture cap(0);
     Mat src;
     while (true) {
         cap.read(src);
         // Edge detection
         Canny(src, dst, 50, 200, 3);
         // Copy edges to the images that will display the results in BGR
         cvtColor(dst, cdst, COLOR_GRAY2BGR);
         cdstP = cdst.clone();

         // Standard Hough Line Transform
         vector<Vec2f> lines; // will hold the results of the detection
         HoughLines(dst, lines, 1, CV_PI / 180, 150, 0, 0); // runs the actual detection
         // Draw the lines
         for (size_t i = 0; i < lines.size(); i++)
         {
             float rho = lines[i][0], theta = lines[i][1];
             Point pt1, pt2;
             double a = cos(theta), b = sin(theta);
             double x0 = a * rho, y0 = b * rho;
             pt1.x = cvRound(x0 + 1000 * (-b));
             pt1.y = cvRound(y0 + 1000 * (a));
             pt2.x = cvRound(x0 - 1000 * (-b));
             pt2.y = cvRound(y0 - 1000 * (a));
             line(cdst, pt1, pt2, Scalar(0, 0, 255), 3, LINE_AA);
         }

         // Probabilistic Line Transform
         vector<Vec4i> linesP; // will hold the results of the detection
         HoughLinesP(dst, linesP, 1, CV_PI / 180, 50, 50, 10); // runs the actual detection
         // Draw the lines
         for (size_t i = 0; i < linesP.size(); i++)
         {
             Vec4i l = linesP[i];
             line(cdstP, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 3, LINE_AA);
         }

         // Show results
         imshow("Source", src);
         imshow("Detected Lines (in red) - Standard Hough Line Transform", dst);
         imshow("Detected Lines (in red) - Probabilistic Line Transform", cdstP);

         // Wait and Exit
         waitKey(1);
     }
    // Check if image is loaded fine
    //if (src.empty()) {
    //    printf(" Error opening image\n");/*
    //    printf(" Program Arguments: [image_name -- default %s] \n", default_file);*/
    //    return -1;
    //}

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file



