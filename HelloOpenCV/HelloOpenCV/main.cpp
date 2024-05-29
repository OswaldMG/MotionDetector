#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <Windows.h>

using namespace cv;
using namespace std;

// Función para mover el cursor del mouse
void MoveMouse(int dx, int dy) {
    POINT cursorPos;
    GetCursorPos(&cursorPos);
    SetCursorPos(cursorPos.x + dx, cursorPos.y + dy); // Mover el cursor directamente según el desplazamiento de la mano
}

int main()
{
    Mat frame, image_hsv, mask;
    double maxArea;
    vector<vector<Point>> contours;
    vector<Point> largestContour;

    VideoCapture cap(0);
    int lowerHue = 169, lowerSaturation = 77, lowerValue = 105;
    int upperHue = 180, upperSaturation = 255, upperValue = 255;

    if (!cap.isOpened()) {
        cout << "Error al leer la camara" << endl;
        return 1;
    }

    namedWindow("Settings", WINDOW_AUTOSIZE);

    // Variables para almacenar las coordenadas del centro de masa en el fotograma anterior
    int prevCx = 0, prevCy = 0;

    while (1) {
        cap >> frame;

        if (frame.empty())
            break;

        // Invertir horizontalmente el fotograma
        flip(frame, frame, 1);

        cvtColor(frame, image_hsv, COLOR_BGR2HSV);

        Scalar lowerThrehold(lowerHue, lowerSaturation, lowerValue);
        Scalar upperThrehold(upperHue, upperSaturation, upperValue);

        inRange(image_hsv, lowerThrehold, upperThrehold, mask);

        contours.clear();
        findContours(mask, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        maxArea = 0.0;
        for (int i = 0; i < contours.size(); i++) {
            double area = contourArea(contours[i]);
            if (area > maxArea) {
                maxArea = area;
                largestContour = contours[i];
            }
        }

        if (!largestContour.empty()) {
            // Obtener el centro del objeto
            Moments m = moments(largestContour);
            int cx = int(m.m10 / m.m00);
            int cy = int(m.m01 / m.m00);

            // Determinar la dirección del movimiento de la mano
            int dx = cx - prevCx;
            int dy = cy - prevCy;

            // Ajustar el desplazamiento del cursor según la dirección del movimiento de la mano
            MoveMouse(dx, dy);

            // Actualizar las coordenadas del centro de masa en el fotograma anterior
            prevCx = cx;
            prevCy = cy;
        }

        imshow("Settings", mask);
        imshow("Original Frame", frame);

        char c = (char)waitKey(25);
        if (c == 27) // ESC 
            break;
    }

    cap.release();
    destroyAllWindows();

    return 0;
}
