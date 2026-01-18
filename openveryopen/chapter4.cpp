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
class Solution {
public:
    double areab(const vector<vector<int>>& squares, double y) {
        double tarea = 0;
        for (int i = 0; i < squares.size(); i++) {
            if (y <= squares[i][1]) {
                continue;
            }
            else if (y < squares[i][1] + squares[i][2]) {
                tarea += (double)squares[i][2] * (y - squares[i][1]);
            }
            else {
                tarea += (double)squares[i][2] * squares[i][2];
            }
        }
        return tarea;
    }

    double areaa(const vector<vector<int>>& squares, double y) {
        double tarea = 0;
        for (int i = 0; i < squares.size(); i++) {
            if (y >= squares[i][1] + squares[i][2]) {
                continue;
            }
            else if (y > squares[i][1]) {
                tarea += (double)squares[i][2] * ((squares[i][1] + squares[i][2]) - y);
            }
            else {
                tarea += (double)squares[i][2] * squares[i][2];
            }
        }
        return tarea;
    }

    double binarysq(const vector<vector<int>>& sq, double left, double right) {
        const double EPS = 1e-5;
        double mid = (left + right) / 2;

        if (right - left < EPS) {
            return mid;
        }

        if (areaa(sq, mid) > areab(sq, mid)) {
            return binarysq(sq, mid, right);
        }
        else {
            return binarysq(sq, left, mid);
        }
    }

    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();

        sort(squares.begin(), squares.end(),
            [](const vector<int>& a, const vector<int>& b) {
                if (a[1] == b[1])
                    return a[2] < b[2];
                return a[1] < b[1];
            });

        double left = squares[0][1];
        double right = 0;

        for (int i = 0; i < n; i++) {
            right = max(right, (double)squares[i][1] + squares[i][2]);
        }

        return binarysq(squares, left, right);
    }

};

/// <summary>
/// ////////////////////////////draw and text/////////////////////////////
/// </summary>
void main() {

	Mat img(512, 512, CV_8UC3, Scalar(163,192,0));
    vector<vector<int>> squares = {
    {100, 200, 300},   // 200/100 = 2   → 2 + 300 = 302
    {50,  100, 400},   // 100/50  = 2   → 2 + 400 = 402
    {25,  75,  430},   // 75/25   = 3   → 3 + 430 = 433
    {10,  40,  470},   // 40/10   = 4   → 4 + 470 = 474
    {200, 100, 200}    // 100/200 = 0   → 0 + 200 = 200
    };

	
	Solution sol;
	for(int i=0;i<squares.size();i++){
		int x = 512-squares[i][0];
		int y = 512-squares[i][1];
		int l = 512-squares[i][2];
		rectangle(img, Point(x, y), Point(x - l, y - l), Scalar(0, 0, 255), 3);

	}
    
	double res = sol.separateSquares(squares);
    line(img, Point(0, 512-res), Point(512, 512-res), Scalar(255, 255, 255), 5);
	putText(img, to_string(res), Point(10, 512-res), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(255, 0, 0), 2);
	cout << res << endl;

	imshow("Display window", img);
	
	waitKey(0);



}