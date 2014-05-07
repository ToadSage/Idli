#ifndef ITEMINFO_H_
#define ITEMINFO_H_

#include<iostream>
using  namespace std;

class itemInfo
{
public:
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
