#include <processItem.h>

using namespace std;

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
	cout<<"Enter rfid"<<endl;
	cin>>rfid;
}
void itemInfo::objectdetect (string fileLocate)
{
	int val = detectAndDisplay(fileLocate,0,&name);
	if(val == -1)
	{
		cout<<"Couldnt perform object detection"<<endl;
	}
}
void itemInfo::getbarcode()
{
	string fileLocate;
	cout << "input image" << endl;
	cin>>fileLocate;
	barcode = scanBarcode(fileLocate);
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
	cout<<"enter the weight"<<endl;
	cin>>weight;
}

void itemInfo::display()
{


	cout <<"RF ID "<<rfid <<endl;
	cout<<"Bar code "<<barcode<<endl;
	cout<<"weight "<<weight<<endl;
	cout<<"name "<<name<<endl;
	cout <<"status"<<status<<endl;
}





