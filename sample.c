#include <stdio.h>
#include <iostream>
#include <string>
#include <stdint.h>

using namespace std;

class USBDevice { 
 public:
    USBDevice() {};
    virtual ~USBDevice() {};
    virtual int usb_control_transfer( int timeout );
    int data;
};

int 
USBDevice::usb_control_transfer(int timeout)
{
    cout << "Doing handle setup\n";
    cout << "Running a libusb transaction\n";
    return 0;
}

#include <gtest/gtest.h>
#include <gmock/gmock.h>


using ::testing::Return;
using ::testing::_;
using ::testing::Mock;


class USBMock : public USBDevice {
 public:
    MOCK_METHOD1(usb_control_transfer,  int(int timeout) );
};

TEST(Setup,first)
{
    USBDevice blah;
    int tmp = blah.usb_control_transfer(0);
    ASSERT_EQ( tmp, 0);
}

TEST(Setup,Mock)
{
    USBMock myfoo;
    EXPECT_CALL(myfoo, usb_control_transfer(100)).WillOnce(Return(0)).WillOnce(Return(1));
    int retval = myfoo.usb_control_transfer(100);
    EXPECT_EQ( 0, retval );
    retval = myfoo.usb_control_transfer(100);
    EXPECT_EQ( 0, retval );
}

int
main(int argc, char *argv[] )
{
  testing::InitGoogleTest(&argc, argv);
  testing::TestEventListeners & listeners = testing::UnitTest::GetInstance()->listeners();
  return RUN_ALL_TESTS();  
}

