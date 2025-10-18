#include<iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;
using namespace cv;
Mat img,crop,temp;
Point start,ed ,center;
 void onMouse(int event,int x,int y,int flags,void*)
{
	if (event==EVENT_LBUTTONDOWN)
	{
	    start = Point(x, y);
	}
	if(event==EVENT_MOUSEMOVE&&(flags&EVENT_FLAG_LBUTTON))
	{ 
		ed = Point(x, y);
		rectangle(temp, start, ed, Scalar(0, 0, 255), 1, 8, 0);
		Vec3b vc3 = temp.at<Vec3b>(y, x);
		imshow("cat",temp);
		cout << "��ǰλ��:" << Point(x, y) << endl;
		cout << "��ǰ����ֵ��" << (int)vc3.val[0] << " " << (int)vc3.val[1] << " " << (int)vc3.val[2] << endl;
	}
	if (event==EVENT_LBUTTONUP)
	{
		 Rect rect(start.x, start.y,ed.x-start.x,ed.y-start.y);
		 crop = img(rect);
		 center = Point(start.x + (ed.x - start.x) / 2, start.y + (ed.y - start.y) / 2);
		 cout << "�������꣺" << center << endl;
		 imshow("crop", crop);
		 imwrite("crop.png", crop);
	}
}
int main()
{
	img = imread("opencvresourse/02.png");
	img.copyTo(temp);//���������ʱ�����ϻ����ξͲ���Ӱ��ԭͼ
	namedWindow("cat");
	imshow("cat", temp);
	setMouseCallback("cat", onMouse);

	waitKey(0);
	return 0;
}
//����ˢ���Ǹ����Σ���ѡ��ʱ�����ֺܶ�����Ρ�