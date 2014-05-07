#include <ObjectHaarParams.h>

objectHaarParam::objectHaarParam ():
scaleFactor{-1.1}, minNeighbors{4},
flag{0}, minSize{Size(10,40)},
type{},ClassifierFile {} {}

objectHaarParam::objectHaarParam (string tp)
{
	if(tp == "milk")
	{
		scaleFactor     = 1.1;
		minNeighbors    = 4;
		flag 		    = 0;
		minSize 	    = Size(10,40);
		type 		    = objList.typeList[0];
		ClassifierFile  = "./milk.xml";
	}
	else if(tp =="coke"){
		scaleFactor 	= 1.1;
		minNeighbors 	= 4;
		flag 			= 0;
		minSize 		= Size(10,40);
		type 			= objList.typeList[1];
		ClassifierFile 	= "./coke.xml";
	}
	else if(tp == "salt"){
		scaleFactor 	= 1.5;
		minNeighbors 	= 4;
		flag 			= 0;
		minSize 		= Size(40,200);
		type 			= objList.typeList[2];
		ClassifierFile 	= "./salt.xml";
	}
	else if(tp == "apple"){
		scaleFactor 	= 1.3;
		minNeighbors 	= 4;
		flag 			= 0;
		minSize 		= Size(50,50);
		type 			= objList.typeList[3];
		ClassifierFile 	= "./apple.xml";
	}

	else
	{
		cout << "Unknown object specified. Default initialization will be done \n";
		scaleFactor     = 1.1;
		minNeighbors    = 4;
		flag 		    = 0;
		minSize 	    = Size(100,100);
		type 		    = "";
		ClassifierFile  = "";
	}

}

/*If the location of the xml is specified then the initilize using the xml file*/
objectHaarParam::objectHaarParam(string tp, string fileName)
{
	if(tp == objList.typeList[0])
	{
		scaleFactor = 1.1;
		minNeighbors = 4;
		flag = 0;
		minSize = Size(10,40);
		type = objList.typeList[0];
		ClassifierFile = fileName;
	}
	if(tp == objList.typeList[1]){
		scaleFactor = 1.1;
		minNeighbors = 4;
		flag = 0;
		minSize = Size(10,40);
		type = objList.typeList[1];
		ClassifierFile = fileName;
	}
	if (tp == objList.typeList[2]){
		scaleFactor = 1.5;
		minNeighbors = 4;
		flag = 0;
		minSize = Size(40,200);
		type = objList.typeList[2];
		ClassifierFile = fileName;
	}
	if (tp == objList.typeList[3]){
		scaleFactor = 1.1;
		minNeighbors = 4;
		flag = 0;
		minSize = Size(40,200);
		type = objList.typeList[3];
		ClassifierFile = fileName;
	}

}
