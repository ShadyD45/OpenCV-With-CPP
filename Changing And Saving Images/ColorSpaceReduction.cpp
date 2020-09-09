// Simple Color Space Reduction Algorithm
// This algorithm is very useful if the some input image has way too many colors which will slow down our program
// In this alogorithm all we will do is go through each pixel of given image and reduce the color space value
// This can be done by dividing the current color space value with new value which will result in less colors
// The formula will be Inew = (Iold / reductionValue) * reductionValue

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <sstream>

using namespace cv;
using namespace std;

Mat& ReduceImageColorSpace(Mat& mImg, const uchar* const ucLookUp)
{
	// Accept only char type matrices
	CV_Assert(mImg.depth() == CV_8U);

	int i, j;
	uchar* p;	
	
	int iChannels = mImg.channels();	// Number of color channels in the input image
	int iRows = mImg.rows;
	int iCols = mImg.cols * iChannels;
	
	// Most of the time the system will store the rows in contiguous manner 
	// If thats the sace then it will make our program more efficient
	// For checking this OpenCV provides us with the cv::Mat::isContinous() function
	if(mImg.isContinuous())
	{
		iCols *= iRows;
		iRows = 1;
	}

	for(i = 0; i < iRows; ++i)
	{
		p = mImg.ptr<uchar>(i);
		for(j = 0; j < iCols; ++j)
		{
			p[j] = ucLookUp[p[j]];
		}
	}
	return mImg;
}

int Help()
{
	cout << endl << " Program Usage: ProgramName Image.jpg ReductionValue" << endl;
	exit(1);
}

int main(int argc, char** argv )
{
	// Reading the original image into a Mat Object
	Mat mOriginalImage = imread(argv[1], IMREAD_COLOR);
	
	// We will create a copy of original image so that later we can compare it with the reduced image
	Mat mReducedImage = mOriginalImage.clone();
	
	// As we are using uchar there would be 256 input values
    uchar ucLookUpTable[256];		// Lookup table to improve our Reduction algorithms efficiency 
    
    int iReductionExtent = 0; 		// The integer value passed as command line argument
    stringstream s;
    
    // Convert the string input to number 
    s << argv[2];
    s >> iReductionExtent;

	if(!s || !iReductionExtent)
	{
		cout << "Invalid value for color space reduction" << endl;
		Help();
		return -1;
	}
	
	// Let's put values in our Lookup table;
	for(int i = 0; i < 256; ++i)
	{
		ucLookUpTable[i] = (uchar)(iReductionExtent * (i / iReductionExtent));
	}
	
	mReducedImage = ReduceImageColorSpace(mReducedImage, ucLookUpTable);
	
	namedWindow("Original Image", WINDOW_NORMAL);
	namedWindow("Reduced Image", WINDOW_NORMAL);
	
	imshow("Original Image", mOriginalImage); 
	imshow("Reduced Image", mReducedImage);

	cout << endl << "Press 's' to save  reduced image.." << endl;
	// Wait forever until key press
	char c = waitKey(0);
		
	if(c == 's')
	{
		cout << endl << "Image saved" << endl;
		imwrite("ReducedImg.jpg", mReducedImage);
	}
	return 0;
}
