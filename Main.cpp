#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui_c.h>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <opencv2/videoio.hpp>
#include <opencv2/core/types_c.h> // To use CvScalar

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	//读取摄像头
	Mat picture;
	VideoCapture video(0);
	video.set(CAP_PROP_FPS, 30);//帧数
	video.set(CAP_PROP_BRIGHTNESS, 1);//亮度 1
	video.set(CAP_PROP_CONTRAST, 40);//对比度 40
	video.set(CAP_PROP_SATURATION, 50);//饱和度 50
	video.set(CAP_PROP_HUE, 50);//色调 50
	video.set(CAP_PROP_EXPOSURE, 50);//曝光 50
	video.set(CAP_PROP_FOURCC, VideoWriter::fourcc('M', 'J', 'P', 'G'));
	video.set(CAP_PROP_FRAME_WIDTH,1920);
	video.set(CAP_PROP_FRAME_HEIGHT,1080);
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