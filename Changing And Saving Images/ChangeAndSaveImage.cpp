#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv )
{
    // Read the image using imread()
    Mat mOriginal = imread( argv[1], IMREAD_COLOR);
    //Read image in grayscale
	Mat mModified = imread(argv[1], IMREAD_GRAYSCALE); 
    
    // Create windows for showing Original and Modified images
    namedWindow("Original Image", WINDOW_AUTOSIZE );
    namedWindow("Modified Image", WINDOW_AUTOSIZE);
    
    // Show Original and Modified Image on the created windows(Just for comaparison)
    imshow("Original Image", mOriginal);
    imshow("Modified Image", mModified);
    
    // Wait forever until key press
	waitKey(0);
	
	// Write the grayscale image
	imwrite("GrayImg.jpg", mModified);
    return 0;
}
