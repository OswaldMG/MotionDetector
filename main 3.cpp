#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <Windows.h>


using namespace cv;
using namespace std;

void Mouse(int mouse) {
	INPUT input = { 0 };
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = 0;
	SendInput(1, &input, sizeof(INPUT));
}

int main(int, char**){
	Mat frame, image_hsv, mask;
	double maxArea;
	vector<Point> largestContour;
	VideoCapture cap(0);
	int LowerHue = 169, LowerSaturation = 77, LowerValue = 105;
	int UpperHue = 180, UpperSaturation = 255, UpperValue = 255;

	if (!cap.isOpened()) {
		cout << "Error al leer la camara" << endl;
		return 1;
	}
	/*
	namedWindow("Settings", WINDOW_AUTOSIZE);
	createTrackbar("Lower Hue", "Settings", &LowerHue, 255, nullptr);
	createTrackbar("Upper Hue", "Settings", &UpperHue, 255, nullptr);
	createTrackbar("Lower Saturation", "Settings", &LowerSaturation, 255, nullptr);
	createTrackbar("Upper Saturation", "Settings", &UpperSaturation, 255, nullptr);
	createTrackbar("Lower Value", "Settings", &LowerValue, 255, nullptr);
	createTrackbar("Upper Value", "Settings", &UpperValue, 255, nullptr); 
	*/


	while (1) {
		cap >> frame;

		if (frame.empty()) {
			break;
		}

		cvtColor(frame, image_hsv, COLOR_BGR2HSV);
		Scalar lowerTherehold(LowerHue, LowerSaturation, LowerValue);
		Scalar upperTherehold(UpperHue, UpperSaturation, UpperValue);

		inRange(image_hsv, lowerTherehold, upperTherehold, mask);
		vector<vector<Point>> contours;
		findContours(mask, contours,RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

		maxArea = 0.0;
		for (int i = 0; i < contours.size(); i++) {
			double area = contourArea(contours[i]);
			if (area > maxArea) {
				maxArea = area;
				largestContour = contours[i];
			}
		}

		if (!largestContour.empty()) {
			//Centro del objeto
			Moments m = moments(largestContour);
			int cx = int(m.m10/m.m00);
			int cy = int(m.m01/m.m00);
			vector<vector<Point>> contourToDraw = { largestContour };
			drawContours(frame, contourToDraw, -1, (0, 255, 0), 3);
			circle(frame, Point(cx, cy), 5, Scalar(255, 255, 255), -1);

			if (cx < frame.cols / 3) {
				cout << "Izquierda" << endl;
			}
			else if (cx > 2 * frame.cols / 3) {
				cout << "Derecha" << endl;
			}
			else if (cy < frame.rows / 3) {
				cout << "Arriba" << endl;
			}
			else if (cy > 2 * frame.rows / 3) {
				cout << "Abajo" << endl;
			}
		}


		imshow("Settings",mask);
		imshow("Original frame", frame);

		char c = (char)waitKey(25);
		if (c == 27) { //ESC
			break;
		}
	}


	cap.release();
	waitKey(0);
	destroyAllWindows();


	return 0;
}