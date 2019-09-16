#define RXD2 9
#define TXD2 10

void setup() {
  Serial.begin(115200);
  Serial2.begin(57600, SERIAL_8N1, RXD2, TXD2);
  Serial.println("Testing.....\n");
    Serial.println("For example, if you type AT\\r\\n, OK\\r\\n will be responsed!");
    Serial.println("Enter your AT command :");
}

void loop() {
   // mySerial.listen();
    delay(1000);
    while(Serial2.available()){
        Serial.write(Serial2.read());
        //delay(1000);
    }
    //mySerial.flush();
    while(Serial.available()){
        Serial2.write(Serial.read());
        //delay(1000);
    }
}
