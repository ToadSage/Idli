#include <processItem.h>

using namespace std;
// why are these parameters strings, instead of things that computers use?
// (this is an embedded programming class)
void itemInfo::weightupdate(float wt)
{
	status="back in";
	weight=wt;
	Timer=0;
}
void itemInfo::statusupdate()
{
	status="gone out";
	time(&Timer);

}
void itemInfo::Timerupdate()
{
	status="deleted";
}
void itemInfo:: getrfid()
{
	rfid=rfid();
}
void itemInfo::objectdetect (string fileLocate)
{
	objectList objList;
	int val = objList.detectAndDisplay(fileLocate,0,&name);
	if(val == -1)
	{
		cout<<"Could not perform object detection"<<endl;
	}
}
void itemInfo::getbarcode()
{
	string fileLocate;
	cout << "input image" << endl;
	cin>>fileLocate;
	scanBarcode objBarcode(fileLocate);
	barcode = objBarcode.code;
	if(!barcode.length()){
		objectdetect(fileLocate);
	}
}
string itemInfo::getname()
{
	return name;
}
void itemInfo::getweight()
{
	while(weight!=0)
		{
			weight=rand()%5;
		}

}

void itemInfo::display()
{


	cout <<"RF ID "<<rfid <<endl;
	cout<<"Bar code "<<barcode<<endl;
	cout<<"weight "<<weight<<endl;
	cout<<"name "<<name<<endl;
	cout <<"status"<<status<<endl;
}





