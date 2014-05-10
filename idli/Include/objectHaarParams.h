/*
 * ObjectDetect.h
 *
 *  Created on: May 4, 2014
 *      Author: Srinivasan
 */

#ifndef OBJECTHAARPARAMS_H_
#define OBJECTHAARPARAMS_H_

/*
 * Objectdetect.h
 *
 *  Created on: May 2, 2014
 *      Author: Krithika
 */

// these types should not be in the header file; they are not needed to define the types in this file,
// or by clients.
#include <objectList.h>
#include <cv.h>
#include <highgui.h>
#include <stdio.h>
#include "opencv2\opencv.hpp"
using namespace cv;
// usually a bad idea to import the entire std namespace
using namespace std;
#include <iostream>
#include <string.h>

class objectHaarParam
{
public:
	double scaleFactor;
	int minNeighbors;
	int flag;
	Size minSize;
	string type;
	string ClassifierFile;
	objectList objList;

	objectHaarParam ();
	objectHaarParam (string);
	objectHaarParam (string , string );
};




#endif /* OBJECTHAARPARAMS_H_ */

