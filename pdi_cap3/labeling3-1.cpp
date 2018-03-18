#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//situaçao que existem 255 objetos
/*
int main(int argc, char** argv){
Mat image, image2, mask;
int width, height;
int nobjects,nob255,cont=0;
Vec3b val;

CvPoint p;
image = imread("big-bolhas.png",CV_LOAD_IMAGE_GRAYSCALE);
image2 = imread("big-bolhas.png", CV_LOAD_IMAGE_COLOR);

if(!image.data){
std::cout << "imagem nao carregou corretamente\n";
return(-1);
}
width=image.size().width;
height=image.size().height;

p.x=0;
p.y=0;

// busca objetos com buracos presentes
nobjects=0;
int tomR = 0, tomB = 0, tomG = 0, tomCinza=0;
val[0] = 255;   //B
val[1] = 255;   //G
val[2] = 255; //R

for(int i=0; i<height; i++){
	for(int j=0; j<width; j++){
		if(image2.at<Vec3b>(i,j) == val){
			// achou um objeto
			nobjects++;
			p.x=j;
			p.y=i;
			
			nob255 = nobjects;// +7 * nobjects;
			floor(nobjects / 255);
			//floodFill(image2,p,nob255%255);
			//cvFloodFill(image2, p, CV_RGB(255, 0, 0), CV_RGB(8, 90, 60), CV_RGB(10, 100, 70), NULL, 4, NULL);
			floodFill(image2, p, Scalar(255,0,0));
			if (nobjects <= 255) { //branco
				floodFill(image2, p, Scalar(tomB, 0, 0));
				tomB++;
			}else if(nobjects>255 && nobjects<500){// (static_cast<int>(floor(nobjects / 255)) % 3 == 0) { //vermelho
				floodFill(image2, p, Scalar(0, 0, tomR));
				tomR++;
			}
			else if (nobjects >= 500) {
				floodFill(image2, p, Scalar(0, tomG, 0));
				tomG++;
				cout << "oi";
			}
		}
	}
}

cout << "No de objetos encontrados: " << nobjects;
cout << "\nNumero de vezes q era 255: " << cont;

imshow("image", image2);
imwrite("labelingRGB.png", image2);
waitKey();

return 0;
}*/
