#ifndef SCANBARCODE_H_
#define SCANBARCODE_H_
// instead of this, how about a barcode type with a constructor from string?
#include <iostream>
#include <string.h>

using std::string;
class scanBarcode{
public:
	string code;
scanBarcode(string location);
};


#endif /* SCANBARCODE_H_ */
