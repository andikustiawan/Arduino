#include <Ultrasonic.h>
#include <Servo.h>

Servo myservo;              // Membuat nama untuk pemanggilan servo kita
Ultrasonic ultrasonic(5,6); // (Trig PIN,Echo PIN)
int led = 13;

void setup() {
  myservo.attach(3);        // angka 3 menunjukkan kalau kita memasukkan sinyal servo ke D3
  myservo.write(0);
  delay(2000);
  Serial.begin(9600);
  digitalWrite(led, LOW);
}

void loop() {
  int dat = ultrasonic.Ranging(CM); // lihat nilai jarak disini
  Serial.println(dat);
  
  if(dat < 13){         // Jika jarak yang terdeteksi < 10cm, maka servo akan bergerak
    digitalWrite(led, HIGH);
    myservo.attach(3);
    myservo.write(53);
    delay(2000);
    digitalWrite(led, LOW);
    myservo.write(110);
    delay(2000);
  }else{                // Jika tidak mendeteksi adanya objek mendekat, maka posisikan keadaan normal
    digitalWrite(led, LOW);
    myservo.write(110);
    delay(500);
    myservo.detach();
  }
  
}

  
