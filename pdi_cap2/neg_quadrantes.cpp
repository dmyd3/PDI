#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

Mat negativo(Mat image) {

	Vec2i xp, yp;
	cout << "Insira os pontos do retangulo negativo, dimensoes:" << image.rows << " X " << image.cols << endl;
	cin >> xp[0] >> xp[1] >> yp[0] >> yp[1];


	for (int i = xp[0]; i < yp[0]; i++) {
		for (int j = xp[1]; j < yp[1]; j++) {
			image.at<uchar>(i, j) = 255 - image.at<uchar>(i, j);
		}
	}
	
	return image;
}