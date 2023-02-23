
uint8_t LedState = LOW;
int timer1_compare_match;

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);      
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(2), RedLedOn, RISING);
  attachInterrupt(digitalPinToInterrupt(3), GreenLedOn, FALLING);

  PCICR |= B00000001;
  PCMSK0 |= B00000001;
  
  TCCR1A = 0;
  TCCR1B = 0;
  timer1_compare_match = 31249;
  TCNT1 = timer1_compare_match;
  TCCR1B |= (1 << CS12);
  TIMSK1 |= (1 << OCIE1A);

  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {

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
  Serial.println("Button 1 have been pressed.");
  LedState = !LedState;
  digitalWrite(5, LedState);
}

ISR (PCINT0_vect)
{
  
  if(digitalRead(8) == LOW){
  Serial.println("Button 2 have been pressed.");
  LedState = !LedState;
  digitalWrite(9, LedState);
  }
}

ISR(TIMER1_COMPA_vect)
{
  TCNT1 = timer1_compare_match;
  digitalWrite(10, digitalRead(10) ^ 1);
}
