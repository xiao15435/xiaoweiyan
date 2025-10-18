#include<iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;
using namespace cv;
VideoCapture video(0);
int bri = 100;
int ex = 0;
Mat img;
void onbright(int, void*)
{
	video.set(CAP_PROP_BRIGHTNESS, bri * 0.01);//��Ҳ��֪�����Ⱥ��ع���ֵ��Χ��0.01�����д��

}
void onexposure(int, void*)
{
	video.set(CAP_PROP_EXPOSURE, ex * 0.01);

}

int main()
{
	video >> img;
	bool isColor = (img.type() == CV_8UC3);
	VideoWriter writer;
	int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');
	double fps = 25.0;
	string filename = "live.avi";
	writer.open(filename, codec, fps, img.size(), isColor);
	cout << "֡�ʣ�" << video.get(CAP_PROP_FPS) << endl;
	cout << "��ȣ�" << video.get(CAP_PROP_FRAME_WIDTH) << endl;
	cout << "�߶ȣ�" << video.get(CAP_PROP_FRAME_HEIGHT) << endl;
	namedWindow("Trackbar");
	createTrackbar("bright", "Trackbar", &bri, 600,onbright,0);
	createTrackbar("exposure", "Trackbar", &ex, 100, onexposure, 0);
	while (1)
	{
		video >> img;
		writer.write(img);
		imshow("Live", img);
		char c = waitKey(40);
		if (c == 27)//ASCII���Ӧesc
		{
			break;
		}
	}
    return 0;
}


