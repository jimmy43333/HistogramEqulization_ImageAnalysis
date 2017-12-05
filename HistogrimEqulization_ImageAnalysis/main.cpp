//
//  main.cpp
//  Homework_of_ImageAnalysis
//
//  Created by 宋題均 on 2017/10/4.
//  Copyright © 2017年 宋題均. All rights reserved.
//
#include "iostream"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "HistogramEqu.h"
#include "readRawfile.h"

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    Mat src,img,out;
    //read images with opencv : jpg,tif,png
    //src= imread("/Users/TGsung/Desktop/lenna.tif", 0);
    
    img = readRawfile("/Users/TGsung/Desktop/Dataset/lenna.raw",512,512);
    //Histogram Equlization
    scaleEqualize(img,out,16);
    int histSize = 256;
    float range[] = {0, 255} ;
    const float* histRange = {range};
    Mat histImg;
    calcHist(&out, 1, 0, Mat(), histImg, 1, &histSize, &histRange);
    //show the histogram on the window.
    Mat showHistImg(300,300,CV_8UC1,Scalar(255));  //把直方圖秀在一個300*300大的影像上
    drawHistImg(histImg, showHistImg);
    Mat tmp(233,345,CV_8UC1,Scalar(255));
    img.copyTo(tmp);
    imshow("window1",tmp);
    imshow("window2",out);
    imshow("window3", showHistImg);
    waitKey(0);
    
    return 0;
}



