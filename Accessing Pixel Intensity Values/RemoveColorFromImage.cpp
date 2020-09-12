// In this program we will access pixels intensity value and change them
// This program will select a color channel and remove it from the image completely
// If Color channel not provided by user any random channel will be selected  

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace cv;
using namespace std;

int Help()
{
	cout << endl << " Usage: ./ProgramName ImageName [ ColorChannel ]" << endl;
	cout << endl << " The ColorChannel parameter is optional. If not provided any Color Channel will be selected"
	cout << endl << " ImageName : Image.jpg \nColorChannel : 0 or 1 or 2 for Blue or Green or Red resp." << endl;
	exit(1);
}

int main(int argc, char** argv)
{
	int iColorChannel;
	if(argc < 2)
	{
		cout << "Too few arguments" << endl;
		Help();
		return -1;
	}
	else if(argc == 2)
	{
		srand((unsigned) time(0));
		iColorChannel =  0 + (rand() % 2);
	}
	else
	{
		iColorChannel = argv[2];
	}

	// Read the original image 
	Mat mOriginal = imread(argv[1], IMREAD_COLOR);
	Mat mModified = mOriginal.clone();	
	
	// This is the naive way 
	// There are other efficient ways than this one
	for(int row = 0; row < mModified.rows; ++row)
	{
		for(int col = 0; col < mModified.cols; ++col)
		{
			/*  
			 Uncomment this For GrayScale Images as they only have a single channel
				mModified.at<uchar>(row, col) = mModified.at<uchar>(row, col) * 0.5f;
			*/
			// For Color images its somewhat different as they have	3 color channels BGR (Blue Green Red)
			mModified.at<Vec3b>(row, col)[iColorChannel] =  mModified.at<Vec3b>(row, col)[iColorChannel] * 0;		
		}
	}
	
	namedWindow("Original Image", WINDOW_NORMAL);
	namedWindow("Intensity changed", WINDOW_NORMAL);
	
	imshow("Original Image", mOriginal);
	imshow("Intensity changed", mModified);
	
	// Wait forever until key press
	cout << "Press 's' to save modified image" << endl;
	char c = waitKey(0);
		
	if(c == 's')
	{
		imwrite("Intensity.jpg", mModified);
		cout << endl << "Image saved" << endl;
	}
	
	return 0;
}
