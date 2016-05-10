#include <stdio.h>
#include <iostream>
#include <string>
#include <stdint.h>


using namespace std;
#if 0
typedef struct USBDevice USBDevice;
struct USBDevice { 
    int usb_control_transfer( USBDevice *usbdev, int timeout );
    int data;
};
#else
class USBDevice { 
 public:
    int usb_control_transfer( USBDevice *usbdev, int timeout );
    int data;
};
#endif

int 
USBDevice::usb_control_transfer(USBDevice *dev_handle, int timeout)
{
    cout << "Doign handle setup\n";
    cout << "Running a libusb transaction\n";
    return 0;
}


#include <gtest/gtest.h>
#include <gmock/gmock.h>


struct USBMock : public USBDevice {
    MOCK_METHOD2(usb_control_transfer,  int(USBDevice *, unsigned int timeout));
};

using ::testing::Return;
using ::testing::_;

TEST(Setup,first)
{
    USBDevice blah;
    int tmp = blah.usb_control_transfer(&blah,0);
    ASSERT_EQ( tmp, 0);
}


TEST(Setup,Mock)
{
#if 0
    USBMock myfoo;
    EXPECT_CALL( myfoo, usb_control_transfer( &myfoo,0))
        .WillOnce( Return(0) )
        .WillOnce( Return(1) );
    int retval = myfoo.usb_control_transfer( &myfoo,0);
    ASSERT_EQ( retval, 0);
    retval = myfoo.usb_control_transfer( &myfoo,0 );
    ASSERT_EQ( retval, 1);
#endif
}

int
main(int argc, char *argv[] )
{

  testing::InitGoogleTest(&argc, argv);
  testing::TestEventListeners & listeners = testing::UnitTest::GetInstance()->listeners();
  return RUN_ALL_TESTS();  
}

