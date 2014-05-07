#ifndef OBJECTLIST_H_
#define OBJECTLIST_H_

#pragma once
#include <cv.h>
#include <highgui.h>
#include <stdio.h>
using namespace std;
#include <iostream>
#include <string.h>

class objectList{
public:
	const vector <string >typeList = {"milk","coke","salt", "apple"};
	vector <string >xmlList = {"./milk.xml","./coke.xml","./salt.xml", "./apple.xml"};
};




#endif /* OBJECTLIST_H_ */

