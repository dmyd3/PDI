#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main(int argc, char** argv){
	Mat image, mask;
	int width, height;
	int nobjects,bordas=0, furos=0;

	CvPoint p;
	image = imread("bolhas.png",CV_LOAD_IMAGE_GRAYSCALE);

	if(!image.data){
		std::cout << "imagem nao carregou corretamente\n";
	return(-1);
	}
	width=image.size().width;
	height=image.size().height;

	p.x=0;
	p.y=0;
	
	//elimina bolhas nas bordas
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			if(i==0 || i==height-1 || j==0 || j==width-1)
			if (image.at<uchar>(i, j) == 255) {
				// achou um objeto
				bordas++;
				p.x = j;
				p.y = i;
				floodFill(image, p, 0);
			}
		}
	}
	//muda a cor do fundo
	p.x = 0;
	p.y = 0;
	floodFill(image, p, 50);
	
	// busca objetos com buracos presentes
	nobjects=0;
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			if(image.at<uchar>(i,j) == 255){
				// achou um objeto
				nobjects++;
				p.x=j;
				p.y=i;
				floodFill(image,p,254);
			}
		}
	}

	//busca furos de valor Zero
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			if (image.at<uchar>(i, j) == 0) {
				// achou um objeto
				furos++;
				p.x = j;
				p.y = i;
				floodFill(image, p, 1);
			}
		}
	}

	cout << "No de objetos encontrados: " << nobjects;
	cout << "\nBolhas nas bordas : " << bordas;
	cout << "\nFuros nas bolhas: " << furos;

	imshow("image", image);
	imwrite("bolhas-buracos3.png", image);
	waitKey();

	return 0;
}
