// Mask operations on matrices means nothing but to recalculate each pixel's value
// in and image according to a mask matrix.
// This mask has values that will adjust how much influence
// neighbouring pixels and the current pixel will have on the new pixel value.
// The OpenCV Documentation has implementation of applying mask on a matrix ourselves
// but this program will demonstrate the usage of built in filter2D() function
// which is actually very fast instead of the one we implement ourselves. 

#include <opencv2/core.hpp>
#include <opencv2/imgproc/hal/hal.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int Help()
{
	cout << endl << " Usage: ProgramName Image.jpg " << endl;
	exit(1);
}

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		cout << "Too few arguments" << endl;
		Help();
		return -1;
	}
	
	// Reading the original image into a Mat Object
	Mat mOriginalImage = imread(argv[1], IMREAD_COLOR);
	
	// This will be our output image after masking
	Mat mAfterMasking;	
	
	if(mOriginalImage.empty())
    	{
        	cout << "The image" << argv[1] << " could not be loaded." << endl;
        	return -1;
    	}
    	
    	// Create a mask matrix
    	Mat mMask = (Mat_<char> (3,3) <<  0, -1,  0,
                                   	 -1,  7, -1,
                                    	  0, -1,  0);
                         	
	filter2D(mOriginalImage, mAfterMasking, mOriginalImage.depth(), mMask)

	namedWindow("Original Image", WINDOW_NORMAL);
	namedWindow("After Masking Image", WINDOW_NORMAL);
	
	imshow("Original Image", mOriginalImage);
	imshow("After Masking Image", mAfterMasking);
	
	return 0;
}
