uint8_t LedState = LOW;     //defining a variable which we will use in the interrupt to turn the LED off.

void setup() {
  pinMode(2, INPUT_PULLUP);      //defining input pin of PIR sensor and also use an internal pullup resistor of the pin.
  pinMode(3, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(2), LedOn, RISING);   //starting the interrupt on GPIO2, with LedOn as the function adn RISING as the change on which interrupt triggers.
  Serial.begin(9600);

}

void loop() {

  delay(500);

}

void LedOn()      //the function which will be ran after the interrupt is triggered.
{
  LedState = !LedState;   //change the LED state.
  digitalWrite(3, LedState);    //switch the LED on or off based on the value in the variable.
}

//this code works asme as the previous code but we are using interrrupts in place of simple program.
//interrupts are a short and quick commands in a code which (as the name suggests) interrupts the normal flow of the code.
//if an interrupt is triggered, it stops the code whereever it is, runs the code of the interrupt and then resumes the normal flow of the code.
