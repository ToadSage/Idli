#include <iostream>
#include <libusb.h>
#define vendor_ID 0x04D8
#define product_ID 0x003F
#define end_point 2

using namespace std;

class rfid_detector
{
libusb_device **device_list; //pointer to pointer of device, used to retrieve a list of devices
libusb_device_handle *device_handle; //a device handle
libusb_context *USB_session = NULL; //a libusb session
unsigned char *data = new unsigned char[10]; //data to be read, and the size of the buffer into which the data is read

string rfid() const;

}
