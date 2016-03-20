#include <RF24.h>
#include <nRF24L01.h>

#include <SPI.h>


RF24 radio(9, 10);//ce9 csn 10

const byte txAddr[6] = "00001";//pipe address 1 transmit
const byte rxAddr[6] = "00002";//pipe address 2 receive

char incomingByte;  // incoming data

void setup()
{
  Serial.begin(9600); // initialization
  radio.begin();
  radio.setRetries(15, 15);
  radio.openWritingPipe(txAddr);
//  radio.openReadindPipe(0, rxAddr);
  
  radio.stopListening();
}

void loop()
{

if (Serial.available() > 0) {  // if the data came
  
    incomingByte = Serial.read(); // read byte


// SW1 OFF
    if(incomingByte == '0') {
      int relay1off = 9991;
  radio.write(&relay1off, sizeof(relay1off));
      Serial.println("Off");
    } // end sw1 off
    
// SW1 ON
    if(incomingByte == '1') {
      int relay1on = 9992;
  radio.write(&relay1on, sizeof(relay1on));
      Serial.println("On");  // print message
    } // end sw1 on


    // SW2 OFF
    if(incomingByte == '2') {
      int relay2off = 9993;
  radio.write(&relay2off, sizeof(relay2off));
      Serial.println("off");
    } // end sw2 off

    // SW2 ON
    if(incomingByte == '3') {
      int relay2on = 9994;
  radio.write(&relay2on, sizeof(relay2on));
      Serial.println("On");  // print message
    } // end sw2 on

    // SW3 OFF
    if(incomingByte == '4') {
      int relay3off = 9995;
  radio.write(&relay3off, sizeof(relay3off));
      Serial.println("off");
    } // end sw3 off

    // SW3 ON
    if(incomingByte == '5') {
      int relay3on = 9996;
  radio.write(&relay3on, sizeof(relay3on));
      Serial.println("On");  // print message
    } // end sw3 on

    // SW4 OFF
    if(incomingByte == '6') {
      int relay4off = 9997;
  radio.write(&relay4off, sizeof(relay4off));
      Serial.println("off");
    } // end sw4 off

    // SW4 ON
    if(incomingByte == '7') {
      int relay4on = 9998;
  radio.write(&relay4on, sizeof(relay4on));
      Serial.println("On");  // print message
    } // end sw4 on


    

} // end serial available

} // end loop
