/*
 * ItemInfo.h
 *
 *  Created on: May 4, 2014
 *      Author: Srinivasan
 */

#ifndef ITEMINFO_H_
#define ITEMINFO_H_

#include<iostream>
using  std::string;

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
