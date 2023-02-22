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
