#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

const int row = 480;		// ����
const int col = 640;		// ����

void show(Mat mat) {
	imshow("show", mat);
	waitKey(0);
	return;
}

int main() {
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
	Mat mat6 = Mat_<uchar>({ 2,3 }, {1, 2, 3, 4, 5, 6});
	mat4.create(256, 256, CV_8UC3);
	mat5.create(4, 4, CV_32FC1);

	mat4 = Scalar(255, 0, 0);
	mat5.setTo(1.f);


	return 0;
}