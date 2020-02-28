#include <iostream>
#include<opencv2/opencv.hpp>;

using namespace std;
using namespace cv;

int main()
{
	cv::Mat srcMat = cv::imread("D:\\Files\\2.jpg");//读取图片
	cv::Mat deepMat;
	cv::Mat shallowMat;
	shallowMat = srcMat;//浅复制
	srcMat.copyTo(deepMat);//深复制
	int height = srcMat.rows;
	int width = srcMat.cols;
	uchar threshold = 100;//定义阈值
	for (int i = 0; i < height; i++)//遍历像素
	{
		for (int j = 0; j < width; j++)
		{
			uchar average = (srcMat.at<Vec3b>(i, j)[0] + srcMat.at<Vec3b>(i, j)[1] + srcMat.at<Vec3b>(i, j)[2]) / 3;//计算RGB均值
			if (average > threshold)//二值化
			{
				average = 255;
			}
			else
			{
				average = 0;
			}
			srcMat.at<Vec3b>(i, j)[0] = average;//赋值
			srcMat.at<Vec3b>(i, j)[1] = average;//赋值
			srcMat.at<Vec3b>(i, j)[2] = average;//赋值
		}
	}
	cv::imshow("deepMat", deepMat);//显示深复制图片
	cv::imshow("shallowMat", shallowMat);//显示浅复制图片
	waitKey(0);
}