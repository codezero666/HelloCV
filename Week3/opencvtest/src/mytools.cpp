#include "mytools.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

void getContours(cv::Mat const &imgDilate, cv::Mat const &img,std::string const &type)
{
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    //获取轮廓
    cv::findContours(imgDilate, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    std::vector<std::vector<cv::Point>> conPoly(contours.size());
    std::vector<cv::Rect> boundrect(contours.size());

    for(int i=0; i<(int)contours.size(); i++)
    {
        int area = cv::contourArea(contours[i]);

        if(area > 8500 && area < 9600) //过滤
        {
            //std::cout << area << std::endl;
            float peri = cv::arcLength(contours[i], true);

            //将轮廓化为多边形
            cv::approxPolyDP(contours[i], conPoly[i], 0.02*peri, true);
            
            //获取外接矩形
            boundrect[i] = cv::boundingRect(conPoly[i]);

            //根据角的数量确定形状，过滤
            int corner = (int)conPoly[i].size();
            if(corner > 4 && corner < 10)
            {
                //描边测试：底布，轮廓，第几个，颜色，厚度
                //cv::drawContours(img, conPoly, i, cv::Scalar(255, 0, 255), 10);

                //方框文字展示（英文）
                cv::rectangle(img, boundrect[i].tl(), boundrect[i].br(), cv::Scalar(255, 255, 255), 3);
                cv::putText(img, type, {boundrect[i].x, boundrect[i].y - 5}, cv::FONT_HERSHEY_DUPLEX, 1.5, cv::Scalar(255, 255, 255), 2);
            }
        }
    }
}

void colorselect(cv::Mat const &img, cv::Mat &imgDilate, cv::Scalar const &lower, cv::Scalar const &upper)
{
    cv::Mat imgGray, imgBlur, imgCanny, imgHSV, mask;

    //颜色筛选
    cv::cvtColor(img, imgHSV, cv::COLOR_BGR2HSV);
    cv::inRange(imgHSV, lower, upper, mask);

    //形状筛选
    cv::GaussianBlur(mask, imgBlur, cv::Size(3, 3), 3, 0);
    cv::Canny(imgBlur, imgCanny, 25, 75);
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    cv::dilate(imgCanny, imgDilate, kernel);
}
