#include "spark_wiring_i2c.h"
#include "spark_wiring_usbserial.h"
#include "spark_wiring_constants.h"

class NCD2Relay{
public:
    //Constructor
    NCD2Relay(void);
    //Set Init.  a0 through a1 Indicate status of jumpers on board.  Send 0 for not installed, send 1 for installed.
    //           Optional: direction set GPIO pin as input or output bitwise, 1 input, 0 output
    //           Optional: pullup set GPIO internal pull-up resistors on or off bitwise, 1 on, 0 off.
    //           Default address: 000; direction: all inputs; pullup: all enabled.
    void setInit(int a0, int a1, int a2, byte direction = 0xFC, byte pullup = 0xFC);
    //Turn on Relay
    void turnOnRelay(int relay);
    //Turn off Relay
    void turnOffRelay(int relay);
    //Turn On all Relays
    void turnOnAllRelays();
    //Turn Off All Relays
    void turnOffAllRelays();
    //Toggle Relay
    void toggleRelay(int relay);
    //Set status of all relays in bank
    void setBankStatus(int status);
    //Read status of relay. Valid return 0 for off 1 for on.  256 returned if there is an error
    int readRelayStatus(int relay);
    //Read status of all relays in bank.  0-255 valid.  256 returned on error
    int readRelayBankStatus();
    //Read status of input
    int readInputStatus(int input);
    //Read status of all inputs
    int readAllInputs();
    // Turn on output if enabled
    void setOutputHigh(int output);
    // Turn off output if enabled
    void setOutputLow(int output);
    // Set input pull-up resistors on or off
    //void setPullUp(byte pullup);

    //User Accessible Variables
    //Whether or not the controller is ready to accept commands
    bool initialized;
    
private:
    //internal use method for refreshing bank status variables
    void readStatus();
    //Status of relays in bank 1
    byte bankOneStatus;
    //Status of relays in bank 2
    byte bankTwoStatus;
    //Status of relays in bank 3
    byte bankThreeStatus;
    //Status of relays in bank 4
    byte bankFourStatus;

    int address = 0x20;
    int address2 = 0x21;
    int retrys = 0;
    byte outputRegister = 0x0A;

};
