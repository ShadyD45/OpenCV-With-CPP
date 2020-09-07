// To compile the program use cmake 
// Create CMakeLists.txt file (Uploaded with every program) for using cmake 
// Open terminal in the program folder and run following commands
// cmake .
// make
// ./ProgramName <Inputs if needed>
#include <stdio.h>
#include<iostream>
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
   
    Mat image;
    // Read the image using imread()
    image = imread( argv[1], 1 );
    
    // Error Handling
    // Checking if the read image has data or not
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    // Show the image
    imshow("Display Image", image);
     
    waitKey(0);     // Wait forever until key press
    return 0;
}
