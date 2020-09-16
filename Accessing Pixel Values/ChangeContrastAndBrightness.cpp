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

    cout << "Enter the alpha value [1.0-3.0]: "; 
    cin >> alpha;
    cout << "Enter the beta value [0-100]: ";    
    cin >> beta;
	
	//Iterate over each channel in each pixel of an image
	for(int row = 0; row < mOriginal.rows; ++row)			// Comment out the for loops for using convertTo() function
	{
		for(int col = 0; col < mOriginal.cols; ++col)
		{
			for(int channel = 0; channel < mOriginal.channels(); ++channel)
			{
				mModified.at<Vec3b>(row,col)[channel] = saturate_cast<uchar>( alpha * mOriginal.at<Vec3b>(row,col)[channel] + beta ); 
			}
		}
	}
	
	// Instead of using for loops, a more Efficient way is to use the  convertTo() 
	// Uncomment the below code to see how the function works 
	// mOriginal.convertTo(mModified, -1, alpha, beta);
	
	namedWindow("Original Image", WINDOW_NORMAL);
	namedWindow("Modified Image", WINDOW_NORMAL);
	
	moveWindow("Original Image", 10, 50);		// Place the output window at given co-ordinates
	moveWindow("Modified Image", 180, 250);		// Place the output window at given co-ordinates
	
	
	imshow("Original Image", mOriginal);
	imshow("Modified Image", mModified);
	
	
	cout << "Press 's' to save changed image.." endl;
	// Wait forever until key press
	char c = waitKey(0);
	if(c == 's')
	{
		imwrite("modifiedImg.jpg", mModified);
		cout<< "Image Saved.." << endl;
	}
	return 0;
}
