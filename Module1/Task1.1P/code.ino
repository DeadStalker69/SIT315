void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  digitalRead(2);
  if(digitalRead(2) == HIGH)
  {
    Serial.println("Motion detected");
    digitalWrite(3, HIGH);
    time.sleep(100);
    digitalWrite(3, LOW);
  }
  time.sleep(1500);
  // put your main code here, to run repeatedly:

}

//the motion sensor and arduino are connected via a digital pin. 
//therefore, arduino and PIR sensor cannot communicate with values. digtal signal only works with 0 nad 1 as values and nothing more. 
//therefore, motion sensor constantly sends a 0volts to the arduino unless motion is detected in its range of vision. 
//if motion is deteced, it alters the voltage sent to 5v indicating a 1 in binary language. according to the delay input in the code, arduino rechecks for a signal from PIR sensor.
//if voltage is dropped down to 0, then it understands that motion have been stopped.  
