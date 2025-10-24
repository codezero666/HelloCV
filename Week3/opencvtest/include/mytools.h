#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

void getContours(cv::Mat const &imgDilate, cv::Mat const &img,std::string const &type);
void colorselect(cv::Mat const &img, cv::Mat &imgDilate, cv::Scalar const &lower, cv::Scalar const &upper);

#endif