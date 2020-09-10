// Image Color Space Reduction Algorithm
// This is the most efficient way as per the OpenCV documentation
// OpenCV encourages us to use the built in functions in the library 
// instead of implementing them ourselves. As they provide good performance
// Using the LUT Function is the most efficient way

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
	// Create Mat type of our lookup
	Mat lookUpTable(1, 256, CV_8U);
	Mat mReducedImg;
   
	uchar* p = lookUpTable.ptr();	// Get the pointer to our Mat type lookup
    
    	for(int i = 0; i < 256; ++i)
        	p[i] = ucLookUp[i];
    
    	// Here mImg is the input image and mReducedImg is the output 
    	LUT(mImg, lookUpTable, mReducedImg);			// Using LUT function to get the reduced image

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


int main(int argc, char** argv )
{
	if (argc < 3)
    	{
        	cout << "Not enough parameters" << endl;
        	Help();
        	return -1;
    	}

	// Reading the original image into a Mat Object
	Mat mOriginalImage = imread(argv[1], IMREAD_COLOR);
	
	if (mOriginalImage.empty())
    	{
        	cout << "The image" << argv[1] << " could not be loaded." << endl;
        	return -1;
    	}
	
    	uchar ucLookUpTable[256];		
    
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
	
	int iVal = ReduceImageColorSpace(mReducedImage, ucLookUpTable);		// Calling our reduction function
	
	if(!iVal)
	{
		cout << "Image redution failed" << endl;
		return -1;
	}
	
	// Show the original image for comparison
	namedWindow("Original Image", WINDOW_NORMAL);
	imshow("Original Image", mOriginalImage); 
	
	// Wait forever until key press
	waitKey(0);
	return 0;
}
