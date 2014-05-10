#ifndef OBJECTLIST_H_
#define OBJECTLIST_H_

#include <iostream>
#include <string.h>
#include <vector>

using std::string;
using std::vector;
// yucch
class objectList{
public:
		// why is this not static?
	static  vector <string >typeList;
	static  vector <string >xmlList;
	int detectAndDisplay( string inputImage, bool cameraCapture ,string *itemName);
};



#endif /* OBJECTLIST_H_ */

