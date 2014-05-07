#include <cstddef>
#include <iostream>
#include "zbar.h"
#include "cv.h"
#include "highgui.h"

using namespace std;
using namespace zbar;
using namespace cv;

string scanBarcode(string location){

	/* Initialise the Scanner to scan barcodes. */
	ImageScanner scanner;
	scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);
	string RetString;
    
	/* Load the image. */
	Mat frame = imread(location,0);
	if(!frame.empty())
	{
		/* Convert the input image to gray scale*/
		Mat grayScale;
		cvtColor(frame,grayScale,CV_GRAY2RGB);

		/* Get the width and height of the image. */
		int width 			= frame.cols;
		int height 			= frame.rows;
		unsigned char *data = frame.data;
		
        /* The Image Scanner only supports Y800 format, that is 8bpp Grayscale format. */
		/*Wrap the raw image data into an Image object provided by zlib*/
		Image image(width, height, "Y800", data, width * height);

		/* The functoin scans the image for a barcode, and returns an empty string and a warning message if the barcode is not found. */
		if (scanner.scan(image))
        {
			/* Extract the barcode */
			Image::SymbolIterator symbol = image.symbol_begin();
			RetString =  symbol->get_data();
            
            /* Clean up the image after it has been scanned. */
            image.set_data(NULL, 0);
		}
		else
		{
			cout << "WARNING: NO BARCODE FOUND!\n" ;
		}
	}
	else
		cout << "No image found!\n" << endl;

	return RetString;
}
