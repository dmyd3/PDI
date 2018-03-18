#include <iostream>
#include <opencv2/opencv.hpp>

//#include "neg_quadrantes.cpp"

using namespace cv;
using namespace std;

int main(int, char**) {
	Mat image;
	Vec3b val;

	image = imread("bolhas.png", CV_LOAD_IMAGE_GRAYSCALE);
	if (!image.data)
		cout << "nao abriu bolhas.png" << endl;

	namedWindow("janela", WINDOW_AUTOSIZE);

	for (int i = 200; i<210; i++) {
		for (int j = 10; j<200; j++) {
			image.at<uchar>(i, j) = 0;
		}
	}

	imshow("janela", image);
	waitKey();

	image = imread("bolhas.png", CV_LOAD_IMAGE_COLOR);

	val[0] = 0;   //B
	val[1] = 0;   //G
	val[2] = 255; //R

	for (int i = 200; i<210; i++) {
		for (int j = 10; j<200; j++) {
			image.at<Vec3b>(i, j) = val;
		}
	}

	imshow("janela", image);
	waitKey();
	//=============xxxxxxxxxx QUADRANTES x=x=x========--=-===
	Mat invertido = imread("bolhas.png", CV_LOAD_IMAGE_GRAYSCALE);
	uchar aux;
	
	for (int l = 0; l < invertido.rows; l++) {
		for (int c = 0; c < invertido.cols / 2; c++) {

			aux = invertido.at<uchar>(l, c);

			//Primeiro quadrante
			if (l<invertido.rows / 2) {
				invertido.at<uchar>(l, c) = invertido.at<uchar>(l + invertido.rows / 2, c + invertido.cols / 2);
				invertido.at<uchar>(l + invertido.rows / 2, c + invertido.cols / 2) = aux;
			}
			//Terceiro quadrante
			else {
				invertido.at<uchar>(l, c) = invertido.at<uchar>(l - invertido.rows / 2, c + invertido.cols / 2);
				invertido.at<uchar>(l - invertido.rows / 2, c + invertido.cols / 2) = aux;
			}
		}
	}
	cout << "Invertido funfou? /n";
	namedWindow("Invertido", WINDOW_AUTOSIZE);
	imshow("Invertido", invertido);
	waitKey();
	//=========xx=x=x=xxx=x=x=x=x===xxxx========xxxxx NEGATIVOS
	image = imread("bolhas.png", CV_LOAD_IMAGE_GRAYSCALE);
	
	Vec2i xp, yp;
	cout << "Insira os pontos do retangulo negativo, dimensoes:" << image.rows << " X " << image.cols << endl;
	cin >> xp[0] >> xp[1] >> yp[0] >> yp[1];


	for (int i = xp[0]; i < yp[0]; i++) {
		for (int j = xp[1]; j < yp[1]; j++) {
			image.at<uchar>(i, j) = 255 - image.at<uchar>(i, j);
		}
	}

	imshow("janela", image);
	waitKey();
	
	return 0;
}