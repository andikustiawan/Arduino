#include<SPI.h>
#include<MFRC522.h>

const int pin_ss = 10;
const int pin_rst = 9;
const int pin_sp = 8;
const int led = 7;

MFRC522 rfid(pin_ss, pin_rst);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  pinMode(led, OUTPUT);
}

void loop() {
  if(!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial() ){
      return;
  }
  
  Serial.print("ID Anda: ");

  String id = String(rfid.uid.uidByte[0]) + String(rfid.uid.uidByte[1]) + String(rfid.uid.uidByte[2]) + String(rfid.uid.uidByte[3]);
  Serial.println(id);
  
  if(id == "138916726"){
       digitalWrite(led, HIGH);
       delay(1000);
       digitalWrite(led.LOW);
  }
  
  rfid.PICC_HaltA();
  
}