#include<iostream>
#include<opencv.hpp>

using namespace cv;
using namespace std;

int main() {
	VideoCapture capVideo;
	capVideo.open(0);
	if (!capVideo.isOpened())     //isOpened()�����Ƶ�Ƿ�����������������1
	{
		std::cout << "���ɴ���Ƶ�ļ�" << std::endl;
		return -1;
	}
	int cnt = 0;
	Mat frame;
	Mat bgMat;
	Mat subMat;
	Mat bny_subMat;
	while (1) {

		capVideo >> frame;
		cvtColor(frame, frame, COLOR_BGR2GRAY);
		if (cnt == 0) {
			frame.copyTo(bgMat);
		}
		else
		{
			absdiff(frame, bgMat, subMat);
			threshold(subMat, bny_subMat, 20, 255, CV_THRESH_BINARY);
			imshow("b_subMat", bny_subMat);
			imshow("subMat", subMat);
			waitKey(30);
		}
		cnt++;
	}

	return 0;
}

