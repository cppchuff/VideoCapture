// VideoCapture.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//



#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	/******** 获取视频文件(实例化的同时进行初始化)*******/
	VideoCapture capture("EZVZ0018.mp4");

	/********** 获取视频总帧数并打印*****************/
	long totalFrameNumber = capture.get(CV_CAP_PROP_FRAME_COUNT);
	cout << "total frames: " << totalFrameNumber << endl;

	Mat frame;             //定义一个Mat变量，用来存放存储每一帧图像
	bool flags = true;     //循环标志位
	long currentFrame = 0; //定义当前帧

	while (flags)
	{
		capture.read(frame); // 读取视频每一帧
		stringstream str;    //stringstream字符串流，将long类型的转换成字符型传给对象str
		str << "f" << currentFrame << ".jpg";
		cout << "正在处理第" << currentFrame << "帧" << endl;

		/***设置每10帧获取一次帧***/
		if (currentFrame );//% 10 == 0)
		{
			imwrite("C:/Users/fly/source/repos/c++/项目/VideoCapture/截图/截图" + str.str(), frame); // 将帧转成图片输出
		}
		/**** 结束条件,当前帧数大于总帧数时候时，循环停止****/
		if (currentFrame >= totalFrameNumber)
		{
			flags = false;
		}

		currentFrame++;
	}

	waitKey(0);
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
