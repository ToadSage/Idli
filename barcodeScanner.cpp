/*
 * barcodeScanner.cpp
 *
 *  Created on: Apr 26, 2014
 *      Author: Srinivasan
 */


#include <cstddef>
#include "zbar.h"
#include "cv.h"
#include "highgui.h"
#include <iostream>
using namespace std;
using namespace zbar;
using namespace cv;
string getBarcode(string s){

	/*Init scanner to scan barcodes*/
	ImageScanner scanner;
	scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);
	string RetString;
	/*load image*/
	Mat frame = imread(s,0);

	/*convert the image to grey  scale*/
	Mat greyScale;
	cvtColor(frame,greyScale,CV_GRAY2RGB);

	/*get the width and height information*/
	int width 			= frame.cols;
	int height 			= frame.rows;
	unsigned char *data 	= frame.data;
	/*Image scanner only supports Y800format, that is 8bpp grayscale format*/
	/*Wrap the raw image date into Image object provided by zlib*/

	Image image(width, height, "Y800",data, width * height);
	// scan the image for barcode, if no barcode is found outputs an empty string and a warning
	if (scanner.scan(image)){

		// extract results
		for(Image::SymbolIterator symbol = image.symbol_begin();
				symbol != image.symbol_end();
				++symbol) {

			RetString =  symbol->get_data();
		}
		// clean up data
		image.set_data(NULL, 0);
	}
	else
	{
		cout << "WARNING: NO BARCODE FOUND!\n" ;
	}
	return RetString;
}
