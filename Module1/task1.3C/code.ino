uint8_t LedState = LOW;   //constant variable to define default LED state.

void setup() {
  pinMode(2, INPUT_PULLUP);   //using buiilt-in pullup resistor for PIR sensor
  pinMode(3, INPUT);      
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(2), RedLedOn, RISING);    //adding a rising interrupt by PIR sensor which stops the code and turns on Red LED once.
  attachInterrupt(digitalPinToInterrupt(3), GreenLedOn, FALLING);   //adding a falling interrupt by push button which stops the code and turns on Green LED once.
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {

  delay(500);         // a constant delay is added to potray arduino as being busy in some task, which will b esuspended by interrupt later
  // put your main code here, to run repeatedly:

}

void RedLedOn()     //a function called if PIR sensor detects motion.
{
  Serial.println("Change have been detected by Motion sensor");
  LedState = !LedState;   //turn the LED stated to opposite than current state. by default, change it to on from off.
  digitalWrite(4, LedState);    //reflect the changes state on the LED
}

void GreenLedOn()     //a function called if button is pressed
{
  Serial.println("Button have been pressed.");
  LedState = !LedState;
  digitalWrite(5, LedState);
}
