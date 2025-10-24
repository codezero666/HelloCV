#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include "mytools.h"

// 全局变量
cv::Mat img, imgRed, imgGreen;

int main() 
{
    cv::VideoCapture cap("../video/TrafficLight.mp4");

    std::cout << "视频生成中……\n";

    cv::VideoWriter out;
    //视频输出：输出文件路径，编码格式，视频帧率，单帧图像分辨率，彩色or灰度
    out.open("../video/result.avi", cv::VideoWriter::fourcc('X','V','I','D'), 30, cv::Size(960, 540), true);

    while(true)
    {   
        //读取视频
        cap.read(img);

        //视频结束后退出
        if(img.empty())break;

        //缩小显示
        cv::resize(img, img, cv::Size(), 0.5, 0.5);
        
        //红色范围
        cv::Scalar lowerRed(100, 100, 100);
        cv::Scalar upperRed(179, 255, 255);
        // 绿色范围
        cv::Scalar lowerGreen(30, 100, 100);
        cv::Scalar upperGreen(90, 255, 255);

        //颜色筛选
        colorselect(img, imgRed, lowerRed, upperRed);
        colorselect(img, imgGreen, lowerGreen, upperGreen);

        //形状判断 + 结果显示
        getContours(imgRed, img, "Red");
        getContours(imgGreen, img, "Green");

        cv::imshow("image", img);
        //cv::imshow("image Red", imgRed);
        //cv::imshow("image Green", imgGreen);

        //写入一帧
        out.write(img);

        cv::waitKey(1);
    }
    
    std::cout << std::endl << "视频生成完成，在：Week3/video/\n" << std::endl;

    //释放
    cap.release();
    out.release();

    cv::waitKey(33);
    
    return 0;
}