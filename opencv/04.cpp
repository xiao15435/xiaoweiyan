#include<iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;
using namespace cv;
//����������Ѽ�⵽�Ĵ���ĳһ����������������������Թ����ϰѺ�ɫ�ĵط��ͱ����ɫ��ֵ�����������ƻ������Ӱ�Ͳ��Ǻ�ɫ�ĵط���Ч�����á�
void getContours(Mat imgCanny, Mat img)
{
	vector<vector<Point>>contours;
	vector<Vec4i> hierarchy;
	findContours(imgCanny, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	drawContours(img, contours, -1, Scalar(255, 0, 255), 2);
	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		cout << area << endl;
		if (area > 1000)
		{

			drawContours(img, contours, i, Scalar(255, 0, 255), 2);
			Rect rect = boundingRect(contours[i]);
			rectangle(img, rect, Scalar(0, 0, 255), 2, 8, 0);
		}
	}
}

Mat img, imgGray,imgBlur,imgCanny;
int main()
{
	string path = "opencvresourse/03.png";
	Mat img = imread(path);
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgCanny, kernel, Point(-1,-1), 1, 0, 0);
	getContours(imgCanny,img);

	
	imshow("imgCanny", imgCanny);
	imshow("apple", img);


	waitKey(0);

	return 0;
}