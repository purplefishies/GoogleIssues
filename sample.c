#include <stdio.h>
#include <iostream>
#include <string>
#include <stdint.h>

using namespace std;

class USBDevice { 
 public:
    USBDevice() {};
    virtual ~USBDevice() {};
    int usb_control_transfer( int timeout );
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

class USBMock : public USBDevice {
    MOCK_METHOD1(usb_control_transfer,  int(unsigned int timeout) );
};

using ::testing::Return;
using ::testing::_;
using ::testing::Mock;

TEST(Setup,first)
{
    USBDevice blah;
    int tmp = blah.usb_control_transfer(0);
    ASSERT_EQ( tmp, 0);
}

TEST(Setup,Mock)
{
    USBMock myfoo;
    Mock::VerifyAndClearExpectations(&myfoo); 
}

int
main(int argc, char *argv[] )
{
  testing::InitGoogleTest(&argc, argv);
  testing::TestEventListeners & listeners = testing::UnitTest::GetInstance()->listeners();
  return RUN_ALL_TESTS();  
}

