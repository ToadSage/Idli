#include <ObjectDetect.h>
#include <cv.h>
#include <highgui.h>
#include <stdio.h>
#include "opencv2\opencv.hpp"
#include <iostream>
#include <string.h>

using namespace cv;

using std::cout;
using std::string;


// this should be in a class

int objectList :: detectAndDisplay( string inputImage, bool cameraCapture ,string *itemName)
{

	CascadeClassifier cascade;  // cascade required for detectMultiScale
	std::vector<Rect> object;   // object the classifier returns enclosing the object in a rectangle
	CvCapture* capture;
	Rect decidedObj;
	string decidedType = "Unknown";
	Mat frame;

	decidedObj.height = 0;
	decidedObj.width = 0;
	decidedObj.x = 0;
	decidedObj.y = 0;

	//-- 2. Read the video stream
	if (cameraCapture)
	{
		capture = cvCaptureFromCAM( -1 );
		if( capture )
		{
			frame = cvQueryFrame( capture );
		}
	}
	else
		frame = imread(inputImage);

	//-- 3. Apply the classifier to the frame
	if(!frame.empty())
	{
		// yucch. at least use a for loop. even better, use an iterator
		for(auto it = typeList.begin(); it != typeList.end(); ++it)
		{
			objectHaarParam item1(typeList[it]); // instance the item

			if( !item1.ClassifierFile.empty())
			{
				if( !cascade.load( item1.ClassifierFile ) ){
					printf("--(!)Error loading Classifier File\n");
					return -1;
				}
				else
				{
					cout << "loading classifier for " << item1.type << endl;
				}
			}
			else
			{
				cout << "No classifier specified. Exiting!!";
				return -1;
			}


			//-- Detect item
			cascade.detectMultiScale( frame, object,item1.scaleFactor, item1.minNeighbors, item1.flag|CV_HAAR_SCALE_IMAGE, item1.minSize );


			if(object.size() != 0)
			{
				int max = 0, i = 0;

				/*find the biggest object for within an object type*/
				for( int j = object.begin(); j != object.end(); j++ )
				{
					if(max < object[j].width * object[j].height){
						max = object[i].width*object[i].height;
						i = j;
					}
				}

				/*If current classified object is bigger than previous object then this object is most likely the object*/
				if((decidedObj.width*decidedObj.height) < max)
				{
					decidedObj.height = object[i].height;
					decidedObj.width = object[i].width;
					decidedType = typeList[it];
				}

			}
			else
			{
				cout <<"No object detected \n" << endl;
			}
			waitKey(0);
		}
		*itemName = decidedType;
		return 1;

	}
	else
	{
		printf("No image");
		return -1;
	}
}

