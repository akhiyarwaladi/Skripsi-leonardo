int digitalPin = 10;  // the RSSI pin 6 of Xbee is connected to this PWM Pin. (Digital Pin 10)
int rssiDur, data;  // Variable for RSSI
int led = 13;  // LED connected to Pin 13

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(digitalPin, INPUT);
 
  Serial.begin(9600);   // this is the connection for your Arduino to your PC/MAC
  Serial3.begin(9600);   // this is the connection of your Xbee to your Arduino MEGA!!
}

void loop()
{
  //Serial.print("avail: ");
  //Serial.println(Serial3.available()); 
  if(Serial3.available()==1) {    // This isn't important. You can do here whatever you want.
    data = Serial3.read();
    //Serial.print("data: ");
    //Serial.println(data); 
    rssiDur = pulseIn(digitalPin, LOW, 200); // get's the RSSI Value
    //Serial.print("rssi: :");
    //Serial.println(rssiDur);  //for debbuging and first setup.

    byte bt[1];
    bt[0] = data;
    Serial.write(bt,1);
    
  }
  if(Serial.available()==3){
    idalat = Serial.read();
    satu = Serial.read();
    dua = Serial.read();
    byte bt[3];
    bt[0] = idalat;
    bt[1] = satu;
    bt[2] = dua;
    Serial3.write(bt,3);
  }
  delay(1000);
}

