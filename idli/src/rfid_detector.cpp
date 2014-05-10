#include rfid_detector.h


string rfid_detector :: rfid() const
{
int r;	 //for return values
ssize_t cnt; //holding number of devices in list
int bytes_read;	  //to find out how many bytes were read


r = libusb_init(&USB_session); //initialize the library for the session that was just declared
  if(r < 0) {
      cout<<"Initialisation Error "<<r<<endl; //if there was an error
      return 1;
  }
  libusb_set_debug(USB_session, 3); //set verbosity level to 3,for debugging as suggested in the data sheet

  
cnt = libusb_get_device_list(USB_session, &device_list); //get the list of devices
  if(cnt < 0) {
      cout<<"Get Device Error"<<endl; //if there was an error
      return 1;
  }
  cout<<cnt<<" Devices in list."<<endl;

  
device_handle = libusb_open_device_with_vid_pid(USB_session, vendor_ID, product_ID);
  if(device_handle == NULL)
      cout<<"Cannot open device"<<endl;
  else
      cout<<"Device Opened"<<endl;
  libusb_free_device_list(device_list, 1); //free the list, unref the devices in it


  if(libusb_kernel_driver_active(device_handle, 0) == 1) 
  { //find out if kernel driver is attached
      cout<<"Kernel Driver Active"<<endl;
      if(libusb_detach_kernel_driver(device_handle, 0) == 0) //detach it
          cout<<"Kernel Driver Detached!"<<endl;
  }


  r = libusb_claim_interface(device_handle, 0); //claim interface 0 (the first) of device (mine had jsut 1)
  if(r < 0) {
      cout<<"Cannot Claim Interface"<<endl;
      return "error";
  }
  cout<<"Claimed Interface"<<endl;



  r = libusb_interrupt_transfer(device_handle, (end_point | LIBUSB_ENDPOINT_IN), data, 10, &bytes_read, 0);
  if(r == 0)
      cout<<"Read Successful!"<<endl;
cout<<"ID of the object is - "<<data<<endl;
//update table(data);
  else
      cout<<"Write Error"<<endl;


  r = libusb_release_interface(device_handle, 0); //release the claimed interface
  if(r!=0) 
  {
      cout<<"Cannot Release Interface"<<endl;
      return 1;
  }
  cout<<"Released Interface"<<endl;
  libusb_close(device_handle); //close the device we opened
  libusb_exit(USB_session); //needs to be called to end the

  return data;
}
