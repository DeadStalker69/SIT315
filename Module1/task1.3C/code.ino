uint8_t LedState = LOW;

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT);      
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(2), RedLedOn, RISING);
  attachInterrupt(digitalPinToInterrupt(3), GreenLedOn, FALLING);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {

  delay(500);
  // put your main code here, to run repeatedly:

}

void RedLedOn()
{
  Serial.println("Change have been detected by Motion sensor");
  LedState = !LedState;
  digitalWrite(4, LedState);
}

void GreenLedOn()
{
  Serial.println("Button have been pressed.");
  LedState = !LedState;
  digitalWrite(5, LedState);
}
