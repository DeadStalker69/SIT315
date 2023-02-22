uint8_t LedState = LOW;

void setup() {
  pinMode(2, INPUT_PULLUP);      
  pinMode(3, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(2), LedOn, RISING);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {

  delay;
  // put your main code here, to run repeatedly:

}

void LedOn()
{
  LedState = !LedState;
  digitalWrite(3, LedState);
}
