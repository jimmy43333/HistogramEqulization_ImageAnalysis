//
//  HistogramEqu.h
//  HistogrimEqulization_ImageAnalysis
//
//  Created by 宋題均 on 2017/12/6.
//  Copyright © 2017年 宋題均. All rights reserved.
//

#ifndef HistogramEqu_h
#define HistogramEqu_h
using namespace cv;
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

#endif /* HistogramEqu_h */
