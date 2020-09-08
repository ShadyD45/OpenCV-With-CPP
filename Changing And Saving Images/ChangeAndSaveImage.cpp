#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv )
{
    // Error Handling
    // Check if image path is passed to the program
    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }
   
    // Read the image using imread()
    Mat mOriginal = imread( argv[1], IMREAD_COLOR);
    //Read image in grayscale
	Mat mModified = imread(argv[1], IMREAD_GRAYSCALE); 
	
    
    // Error Handling
    // Checking if the read image has data or not
    if ( !mOriginal.data || !mModified.data)
    {
        printf("No image data \n");
        return -1;
    }
    
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
