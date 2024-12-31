#include <iostream>
#include "opencv2/opencv.hpp"
#include "Path.h"

using namespace std;
using namespace cv;

const int row = 480;		// 세로
const int col = 640;		// 가로


void MatConstructor() {
	Mat img1;
	Mat img2(row, col, CV_8UC1);
	Mat img3(row, col, CV_8UC3);
	Mat img4(Size(col, row), CV_8UC3);

	Mat img5(row, col, CV_8UC1, Scalar(128));
	Mat img6(row, col, CV_8UC3, Scalar(0, 0, 255));

	Mat mat1 = Mat::zeros(Size(3, 3), CV_32SC1);
	Mat mat2 = Mat::ones(Size(3, 3), CV_32FC1);
	Mat mat3 = Mat::eye(Size(3, 3), CV_32FC1);

	float data[] = { 1,2,3,4,5,6 };
	Mat mat4(2, 3, CV_32FC1, data);

	Mat mat5 = (Mat_<float>(2, 3) << 1, 2, 3, 4, 5, 6);
	Mat mat6 = Mat_<uchar>({ 2,3 }, { 1, 2, 3, 4, 5, 6 });
	mat4.create(256, 256, CV_8UC3);
	mat5.create(4, 4, CV_32FC1);

	mat4 = Scalar(255, 0, 0);
	mat5.setTo(1.f);
}

void MatrixCopy() {
	// Shallow Copy
	Mat img1 = imread(PATH + "dog.bmp");
	Mat img2 = img1;
	Mat img3;
	img3 = img1;
	

	// Deep Copy
	Mat img4 = img1.clone();

	Mat img5;
	img1.copyTo(img5);
	img1.setTo(Scalar(0, 255, 255));

	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);
	imshow("img4", img4);
	imshow("img5", img5);
	
	waitKey(0);
}

void PartialMatrixExtraction() {
	Mat img1 = imread(PATH + "cat.bmp");
	Mat img2 = ~img1(Rect(220, 120, 340, 240));

	imshow("img1", img1);
	imshow("img2", img2);
	waitKey(0);
}
void MatrixReference() {
	Mat mat1 = Mat::zeros(3, 4, CV_8UC1);
	
	for (int j = 0; j < mat1.rows; j++) {
		for (int i = 0; i < mat1.cols; i++) {
			mat1.at<uchar>(j,i)++;
		}
	}

	cout << mat1;

}

int main() {
	MatrixReference();
	

	return 0;
}