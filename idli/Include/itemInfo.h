#ifndef ITEMINFO_H_
#define ITEMINFO_H_

#include<iostream>
#include <objectList.h>
#include <scanBarcode.h>
using  namespace std;
// documentation?
class itemInfo
{
public:
	// do you mean for these to be public? why would a client bother with the methods below?
    string barcode;
	string name;
	float weight;
	string status;
	time_t Timer;
	string rfid;

	 void weightupdate(float);
	 void statusupdate();
	 void Timerupdate();
	 void objectdetect (string);
	 void getbarcode( );
	 string getname();
	 void getweight();
	 void display();
	 void getrfid();
};
#endif /* ITEMINFO_H_ */
