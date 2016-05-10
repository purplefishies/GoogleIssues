#include <stdio.h>
#include <iostream>
#include <string>
#include <stdint.h>


using namespace std;
typedef struct USBDevice USBDevice;
typedef struct ADCConfigBlock ADCConfigBlock;
struct ADCConfigBlock {
    int foo;
    char *bar;

};


struct USBDevice { 
    USBDevice();
    int usb_control_transfer( USBDevice *usbdev, uint8_t request_type, uint8_t bRequest, uint16_t wValue, uint16_t wIndex, unsigned char *data, uint16_t wLength, unsigned int timeout );
    int data;
};


USBDevice::USBDevice() { 
    std::cout << "Creating USB Device\n";
}

int 
USBDevice::usb_control_transfer(USBDevice *dev_handle,
                                uint8_t request_type, uint8_t bRequest, uint16_t wValue, uint16_t wIndex,
                                unsigned char *data, uint16_t wLength, unsigned int timeout)
{
    cout << "Doign handle setup\n";
    cout << "Running a libusb transaction\n";
    return 0;
}


#include <gtest/gtest.h>
#include <gmock/gmock.h>


struct USBMock : public USBDevice {
    MOCK_METHOD8(usb_control_transfer,  int(USBDevice *,uint8_t request_type, uint8_t bRequest, uint16_t wValue, uint16_t wIndex,
                                            unsigned char *data, uint16_t wLength, unsigned int timeout));
};

using ::testing::Return;                            // #1
using ::testing::_;

TEST(Setup,first)
{
    USBDevice blah;
    int tmp = blah.usb_control_transfer(&blah,0,0,0,0,0,0,0);
    ASSERT_EQ( tmp, 0);

}


TEST(Setup,Mock)
{
    USBMock myfoo;
#if 0
    EXPECT_CALL( myfoo, usb_control_transfer( &myfoo,0,0,0,0,0,0,0))
        .WillOnce( Return(0) )
        .WillOnce( Return(1) );
    int retval = myfoo.usb_control_transfer( &myfoo,0,0,0,0,0,0,0);
    ASSERT_EQ( retval, 0);
    retval = myfoo.usb_control_transfer( &myfoo,0,0,0,0,0,0,0 );
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

