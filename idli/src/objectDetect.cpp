#include <ObjectDetect.h>
#include <cv.h>
#include <highgui.h>
#include <stdio.h>
#include "opencv2\opencv.hpp"
#include <iostream>
#include <string.h>

using namespace cv;
using namespace std;

// this should be in a class

	int detectAndDisplay( string inputImage, bool cameraCapture ,string *itemName)
	{

		CascadeClassifier cascade;
		objectList l;
		std::vector<Rect> object;
		unsigned int count = 0;
		CvCapture* capture;
		string window_name = "Capture";
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
			while(count < l.typeList.size())
			{
				objectHaarParam item1(l.typeList[count]);
				if( !item1.ClassifierFile.empty())
				{
					if( !cascade.load( item1.ClassifierFile ) ){
						printf("--(!)Error loading\n");
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
					for( size_t j = 0; j < object.size(); j++ )
					{
						if(max < object[j].width*object[j].height){
							max = object[i].width*object[i].height;
							i = j;
						}
					}
					cout << "coming here "<< decidedObj.width*decidedObj.height<<decidedType<<endl;
					if((decidedObj.width*decidedObj.height) < max)
					{
						decidedObj.height = object[i].height;
						decidedObj.width = object[i].width;
						decidedType = l.typeList[count];
					}
					cout << "leaving here "<< endl;
#if 0
					{
						Point pt1, pt2;
						pt1.x = object[i].x;
						pt1.y = object[i].y;
						pt2.x = object[i].x + object[i].width;
						pt2.y = object[i].y + object[i].height;
						cout << object[i].x << "   "<< object[i].y << "  " <<endl;
						rectangle( frame, pt1, pt2, 4, 2, 0 );

						Mat faceROI = frame( object[i] );
					}

					//-- Show what you got
					imshow( window_name, frame );
#endif
					// to extract file name onto string s
					std::istringstream f(inputImage);
					std::string s;
					while (std::getline(f, s, '/')) ;

					//find the location of the input image
					unsigned pos = inputImage.find(s);
					std::string str2 = inputImage.substr (0,pos);
					//save the result in the same folder as the input
					imwrite(str2 +"o"+s,frame);
				}
				else
				{
					cout <<"No object detected \n" << endl;
				}
				waitKey(0);
				count++;
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

