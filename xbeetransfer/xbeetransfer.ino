#include <Event.h>
#include <Timer.h>
#define ledPin 12
long int idalat, satu, dua, durasi;
  
Timer t;
void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);  //XBee/UART1/pins 0 and 1
  Serial.begin(9600);   //USB
  t.every(65000, sendData);
}

void loop() {

  Serial.print("avail: ");
  Serial.println(Serial1.available());
  if (Serial1.available()== 3){ 
    idalat = Serial1.read();
    satu = Serial1.read();
    dua = Serial1.read();
    if(idalat == 14){
      durasi = (satu*255)+ dua;
      durasi = durasi*1000;
      Serial.print("satu: ");
      Serial.println(satu);
      Serial.print("dua: ");
      Serial.println(dua);
      Serial.print("durasi: ");
      Serial.println(durasi);
  
      digitalWrite(ledPin, HIGH);
      delay(durasi);
      digitalWrite(ledPin, LOW);
    }
  }

  t.update();
  delay(500);
}
void sendData(){
  byte bt[2];
  bt[0] = 14;
  bt[1] = 3;
  Serial1.write(bt,2);
}

