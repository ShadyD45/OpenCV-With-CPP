// OpenCV provides us with the Mat object which we can use to store images
// As we know images are made up of multiple pixel values which can be stored in a matrix
// Mat is basically a class which have two data parts matrix header and pointer to matrix containing pixel values 
// Image processing algorithms are already computationally heavy and time consuming so we cannot always make a copy of images 
// especially large images and make our program slowdown. One way to do it is explained below in the program
// The drawback of this method is that change in anyone of the copied or original image will be reflected in other images 


#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main(int argc, char** argv )
{
	// Reading the original image into a Mat Object
	Mat mOriginal = imread(argv[1], IMREAD_UNCHANGED);	// The IMREAD_UNCHANGED flag works same as IMREAD_COLOR
	Mat mCopyTwo;
	
	// This doesn't actually copy the image 
	// All it does is copy the matrix header 
	// which also contains the pointer to the original matrix containing pixel values from the original image 
	 
	Mat mCopyOne(mOriginal);		// Using copy constructor to copy images (not actually copying)
	
	mCopyTwo = mCopyOne;			// Using assignment operator
	
	namedWindow("Original Image", WINDOW_NORMAL);
	namedWindow("Copy One", WINDOW_NORMAL);
	namedWindow("Copy Two", WINDOW_NORMAL);
	
	// Let's see if the original image and the copies are same
	// They will be as their objects contain the pointer to the original matrix 
	imshow("Original Image", mOriginal); 
	imshow("Copy One", mCopyOne);
	imshow("Copy Two", mCopyTwo);
	
	// Wait forever until key press
	waitKey(0);
	
	return 0;
}
