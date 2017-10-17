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
#include "function.h"

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    Mat img,out;
    //read images with opencv : jpg,tif,png
    //src= imread("/Users/TGsung/Desktop/lenna.tif", 0);
    
    //read the raw file
    FILE *fp = NULL;
    char *imagedata = NULL;
    int IMAGE_WIDTH = 512;
    int IMAGE_HEIGHT = 512;
    int framesize = IMAGE_WIDTH * IMAGE_HEIGHT;
    //Open raw Bayer image.
    fp = fopen("/Users/TGsung/Desktop/lenna.raw", "rb");
    //Memory allocation for bayer image data buffer.
    imagedata = (char*) malloc (sizeof(char) * framesize);
    //Read image data and store in buffer.
    fread(imagedata, sizeof(char), framesize, fp);
    //Create Opencv mat structure for image dimension. For 8 bit bayer, type should be CV_8UC1.
    img.create(IMAGE_HEIGHT, IMAGE_WIDTH, CV_8UC1);
    memcpy(img.data, imagedata, framesize);
    free(imagedata);
    fclose(fp);
    
    
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



