#include <opencv2/imgcodec.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	double alpha = 1.0;		// For changing contarst
	int beta = 0;			// For changing brightness
	
	Mat mOriginal = imread(argv[1], IMREAD_COLOR);
	
	// We will create a matrix of zeroes with same size and type of original image
	// to store the modified image after changing contrast or brightness
	Mat mModified = Mat::zeros(mOriginal.size(), mOriginal.type());
	
	if(mOriginal.empty())
	{
		cout << "Error: Failed to read image" << endl;
		cout << "Usage: " << argv[0] << " <Input image>" << endl;
		exit(1);
	}
	
	
	for(int )
	{
		
	}
	return 0;
}
