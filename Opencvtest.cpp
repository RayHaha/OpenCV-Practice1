// Opencvtest.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include<fstream>
#include<string.h>
#include <time.h>

using namespace cv;
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Mat image = imread("lena.bmp");
	Mat grayimage;
	Mat showimage;
	Mat udimage;
	Mat rlimage;
	Mat dmimage;
	int pixel=0;
	cvtColor(image,grayimage, CV_BGR2GRAY);
	cvtColor(image,showimage, CV_BGR2GRAY);
	cvtColor(image,udimage, CV_BGR2GRAY);
	cvtColor(image,rlimage, CV_BGR2GRAY);
	cvtColor(image,dmimage, CV_BGR2GRAY);
	imshow("initial",grayimage);

	//上下左右顛倒
	for(int i=0; i<grayimage.rows; i++){
		for(int j=0; j<grayimage.cols; j++){
			pixel = grayimage.at<uchar>(i,j);
			showimage.at<uchar>(grayimage.rows-1-i,grayimage.cols-1-j) = pixel;
		}
	}

	
	//upside-down
	for(int i=0; i<grayimage.rows; i++){
		for(int j=0; j<grayimage.cols; j++){
			pixel = grayimage.at<uchar>(i,j);
			udimage.at<uchar>(grayimage.rows-1-i,j) = pixel;
		}
	}
	imshow("upside-down",udimage);
	//right-side-left
	for(int i=0; i<grayimage.rows; i++){
		for(int j=0; j<grayimage.cols; j++){
			pixel = grayimage.at<uchar>(i,j);
			rlimage.at<uchar>(i,grayimage.cols-1-j) = pixel;
		}
	}
	imshow("right-side-left",rlimage);
	//diagonally mirrored
	for(int i=0; i<grayimage.rows; i++){
		for(int j=0; j<grayimage.cols; j++){
			pixel = grayimage.at<uchar>(i,j);
			dmimage.at<uchar>(grayimage.cols-1-j,grayimage.rows-1-i) = pixel;
		}
	}
	imshow("diagonally mirrored",dmimage);
	waitKey(0);
	return 0;
}