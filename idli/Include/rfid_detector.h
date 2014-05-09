#include <iostream>
#include <libusb.h>
using namespace std;
#define vendor_ID;
#define product_ID;
#define end_point;

class rfid_detector
{
libusb_device **device_list; //pointer to pointer of device, used to retrieve a list of devices
libusb_device_handle *device_handle; //a device handle
libusb_context *USB_session = NULL; //a libusb session
unsigned char *data = new unsigned char[10];	 //data to be read, and the maximum size of the buffer into which the data is read

string rfid();

}
