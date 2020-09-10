// Image Color Space Reduction Algorithm
// This is the most efficient way as per the OpenCV documentation
// OpenCV encourages us to use the built in functions in the library 
// instead of implementing them ourselves

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <sstream>

using namespace cv;
using namespace std;

int Help()
{
	cout << endl << " Usage: ProgramName Image.jpg ReductionValue" << endl;
	exit(1);
}

int ReduceImageColorSpace(Mat& mImg, const uchar* const ucLookUp)
{
	Mat lookUpTable(1, 256, CV_8U);
	Mat mReducedImg;
    uchar* p = lookUpTable.ptr();
    
    for( int i = 0; i < 256; ++i)
        p[i] = ucLookUp[i];
    
    // Here mImg is the input image and mReducedImg is the output 
    LUT(mImg, lookUpTable, mReducedImg);		// Using LUT function

    if(mReducedImg.empty())
    {
    	cout << "Something went wrong.." << endl;
		Help();
    	return 0;
    }	
    
    // There is no use in returning the local variables address
    // So we will just show the reduced image in here
    namedWindow("Reduced Image", WINDOW_NORMAL);
    imshow("Reduced Image",mReducedImg);
    return 1;	
}
