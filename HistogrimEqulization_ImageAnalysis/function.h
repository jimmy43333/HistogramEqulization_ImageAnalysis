//
//  function.h
//  Homework_of_ImageAnalysis
//
//  Created by 宋題均 on 2017/10/5.
//  Copyright © 2017年 宋題均. All rights reserved.
//
using namespace cv;
#ifndef function_h
#define function_h

void drawHistImg(const Mat &src, Mat &dst){
    int histSize = 256;
    float histMaxValue = 0;
    for(int i=0; i<histSize; i++){
        float tempValue = src.at<float>(i);
        if(histMaxValue < tempValue){
            histMaxValue = tempValue;
        }
    }
    
    float scale = (0.5*256)/histMaxValue;
    for(int i=0; i<histSize; i++){
        int intensity = static_cast<int>(src.at<float>(i)*scale);
        line(dst,Point(i,255),Point(i,255-intensity),Scalar(0));
    }
}

void scaleEqualize(const Mat &src, Mat &dst,int scal){
    equalizeHist(src,dst);
    int num = 256/scal;
    for(int i = 0;i<dst.rows;i++){
        for(int j = 0;j<dst.cols;j++){
            dst.at<uchar>(i,j) = ( dst.at<uchar>(i,j) / num ) * num;
        }
    }
}
/*
void convertToPaper(const Mat &src,Mat &dst,int pos){
    int start;
    
    switch(pos){
        case: 1
            start = ;
        case: 2
            start = ;
        case: 3
            start = ;
        case: 4
            start = ;
        case: 5
            start = ;
        case: 6
            start = ;
        case: 7
            start = ;
        case: 8
            start = ;
            
    };
    for(int i = 0;i<src.raws;i++){
        for(int j=0;j<src.cols;j++){
            
        }
    }
}
*/
#endif /* function_h */
