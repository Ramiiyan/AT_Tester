 /*
  * File  : DFRobot_SIM7000_ATtest.ino
  * Power : SIM7000 needs 7-12V DC power supply
  * Brief : This example use the serial port to send AT command to control the SIM7000
  *         With initialization completed, we can enter AT command to SIM7000 directly
  *         Common AT commands : 
  *         AT+CPIN? : Check SIM card
  *         AT+CSQ   : Check signal quality
  *         AT+CGATT?: Check net attached state
  *         AT+CSTT  : Start net connect task
  *         AT+CIFSR : Get local IP
  *         Get the AT command table in Resource folder :SIM7000 Series_AT Command Manual_V1.01.pdf
  * Note  : If you use Mega please connect PIN8 PIN10 and set PIN_RX = 10
  *         The AT command must end with CRLF
  */
//#include <DFRobot_SIM7000.h>
//SoftwareSerial     mySerial(PIN_TX,PIN_RX);
 HardwareSerial mySerial(1);
//DFRobot_SIM7000    sim7000;

void setup() {
    Serial.begin(115200);
    while(!Serial);
    

    Serial.println("Set baud rate......");
    mySerial.begin(9600, SERIAL_8N1, (int8_t) 17, (int8_t) 16);
    Serial.println("For example, if you type AT\\r\\n, OK\\r\\n will be responsed!");
    Serial.println("Enter your AT command :");
}

void loop() {
   // mySerial.listen();
    delay(1000);
    while(mySerial.available()){
        Serial.write(mySerial.read());
        //delay(1000);
    }
    //mySerial.flush();
    while(Serial.available()){
        mySerial.write(Serial.read());
        //delay(1000);
    }
}
