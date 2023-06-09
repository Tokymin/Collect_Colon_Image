
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui_c.h>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	//读取摄像头
	Mat picture;
	VideoCapture video(0);
	int d = 8;
	char ad[300] = { 0 };
	char name;
	if (!video.isOpened())
	{
		return-1;
	}
	for (int i = 0; i <= 10000; i++)
	{
		video >> picture;
		waitKey(0);
		imshow("input", picture);
		sprintf_s(ad, "record\\%d.jpg", ++d);
		imwrite(ad, picture);
		cout << "get " << d << "  picture " << endl;
		if (waitKey(10) == 27)    //按Esc键，退出
			break;
		i = i + 1;
	}
	return 0;

}