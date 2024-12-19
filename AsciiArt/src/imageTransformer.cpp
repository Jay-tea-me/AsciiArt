//
// Created by Justine Wright on 2024/12/18.
//

#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

std::vector<std::vector<int>> getGrayPixelValues(std::string imageFilePath) {
    Mat originalImage = imread(imageFilePath, IMREAD_COLOR);
    if ( !originalImage.data )
    {
        cout << "Image has no data" << endl;
        throw -1;
    }
    Mat grayImage;
    cvtColor(originalImage, grayImage, cv::COLOR_BGR2GRAY);
    blur(grayImage, grayImage, Size(3,3));
    vector<int> grayPixelValuesColumns(grayImage.cols);
    vector<vector<int>> grayPixelValues(grayImage.rows, grayPixelValuesColumns);
    for (int r = 0; r < grayImage.rows; r++)
    {
        for (int c = 0; c < grayImage.cols; c++) {
            int pixelValue = grayImage.at<uchar>(r, c);
            grayPixelValues[r][c] = pixelValue;
        }
    }
    return grayPixelValues;

    // Mat thresh;
    // const int threshValue = 100;
    // threshold(grayImage, thresh, threshValue, 255, THRESH_BINARY);
    //
    // const string grayImage = "Contour Window";
    // namedWindow(contourWindow, WINDOW_AUTOSIZE );
    // imshow(contourWindow, grayImage);
}
