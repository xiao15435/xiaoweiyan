#include<iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;
using namespace cv;

Mat imgGray,kernel, imgHSV, mask,  imgCanny;
int hmin = 160, smin = 215, vmin = 205;
int hmax = 179, smax = 255, vmax = 255;
vector<vector<Point>>contours;
vector<Vec4i>hierarchy;
int  main()
{
	string path = "opencvresourse/01.png";
	Mat img = imread(path);
	resize(img, img, Size(1280, 720), 0, 0, INTER_CUBIC);//我感觉三次线性的插值或许会好点
	cvtColor(img, imgHSV, COLOR_BGR2HSV);
	Scalar lower(hmin, smin, vmin);
	Scalar upper(hmax, smax, vmax);
	inRange(imgHSV, lower, upper, mask);
	kernel=getStructuringElement(0, Size(3, 3));
	morphologyEx(mask, mask, MORPH_CLOSE, kernel);//用了闭运算还是有空洞，我想把里面那些黑点补上的。
	Canny(mask, imgCanny, 25, 75);
	findContours(imgCanny,contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	cvtColor(imgCanny, imgCanny, COLOR_GRAY2BGR);
	drawContours(imgCanny, contours, -1, Scalar(255, 0, 0), 2);//我检测的只是外层的轮廓但是画出来还是有内层轮廓。
	imshow("imgCanny", imgCanny);
	imwrite("imgCanny.png", imgCanny);
	waitKey(0);
}
//注释部分是我用滑动条来测试h s v 的范围。
//namedWindow("Trackbar", (640, 200));
//createTrackbar("H Min", "Trackbar", &hmin, 179);
//createTrackbar("H Max", "Trackbar", &hmax, 179);
//createTrackbar("S Min", "Trackbar", &smin, 255);
//createTrackbar("S Max", "Trackbar", &smax, 255);
//createTrackbar("V Min", "Trackbar", &vmin, 255);
//createTrackbar("V Max", "Trackbar", &vmax, 255);
//while (1)
//{
//	Scalar lower(hmin, smin, vmin);
//	Scalar upper(hmax, smax, vmax);
//	inRange(imgHSV, lower, upper, mask);
//	Canny(mask, imgCanny, 25, 75);
//	imshow("Image", img);
//	imshow("Image HSV", imgHSV);
//	imshow("Image Mask", mask);
//	imshow("Image Canny", imgCanny);
//	waitKey(1);
//}