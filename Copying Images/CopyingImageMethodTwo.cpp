// Sometimes we may want to copy the matrix itself 
// For this we can use the clone() and copyTo() functions
// The advantage here is that change in any of the copies won't be reflected in other copies

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main(int argc, char** argv )
{
	// Reading the original image into a Mat Object
	Mat mOriginal = imread(argv[1], IMREAD_COLOR);
	Mat mCopyTwo;
	
	// This copies the the whole matrix containing pixel values
	// into another Mat Object
	
	Mat mCopyOne = mOriginal.clone();		// Using cv::Mat::clone()
	
	mCopyOne.copyTo(mCopyTwo);			    // Using cv::Mat::copyTo()
	
	namedWindow("Original Image", WINDOW_NORMAL);
	namedWindow("Copy One", WINDOW_NORMAL);
	namedWindow("Copy Two", WINDOW_NORMAL);
	
	imshow("Original Image", mOriginal); 
	imshow("Copy One", mCopyOne);
	imshow("Copy Two", mCopyTwo);
	
	// Wait forever until key press
	waitKey(0);
	
	return 0;
}
