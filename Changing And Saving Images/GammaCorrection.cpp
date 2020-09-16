#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <sstream>
using namespace cv;
using namespace std;

void Help()
{
	cout << endl << " Usage: ProgramName Image.jpg GammaCorrectionValue" << endl;
	exit(1);
}

void GammaCorrection(Mat& mImg, double gamma)
{
	CV_Assert(gamma >= 0); 		//Accept gaamma values only greater than 0
	
	Mat lookUpTable(1, 256, CV_8U); 
	Mat mCorrectedImage;
	
	uchar* p = lookUpTable.ptr();
	
	// Create a lookup table to improve our code performance
	for(int i = 0; i < 256; ++i)
	{
		p[i] = saturate_cast<uchar>(pow(i/255.0, gamma) * 255.0);
	}
	
	LUT(mImg, lookUpTable, mCorrectedImage);
	
	// There's no point in returning an address of a local varibale 
	// so we'll show the corrected image here itself
	namedWindow("Modified Image", WINDOW_NORMAL);
	imshow("Modified Image",mCorrectedImage);
}

int main(int argc, char** argv)
{	
	stringstream s;
	double gamma;
	
	if(argc == 3)
	{
		// Convert the string gamma value to number
		s << argv[2];
		s >> gamma;
	}
	else
	{
		Help();
	}

	Mat mOriginal = imread(argv[1], IMREAD_COLOR);
	
	if(mOriginal.empty())
	{
		cout << "Error: Failed to read image" << endl;
		Help();	
	}
	
	GammaCorrection(mOriginal, gamma);
	
	namedWindow("Original Image", WINDOW_NORMAL);
		
	moveWindow("Original Image", 10, 50);			// Place the output window at given co-ordinates	
	
	imshow("Original Image", mOriginal);	
	// wait forever until key press	
	waitKey(0);
	return 0;
}


