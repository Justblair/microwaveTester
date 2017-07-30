/*
  microwaveTester

  This is a simple sketch that tests a microwave motion detector
  On the detection of motion, it will flash a led on the arduino (pin13)
  In testing I also added a buzzer to this pin to give an audible indication

 The circuit:
 * LED attached from pin 13 to ground
 * Buzzer attached from pin 13 to ground
 * Microwave Motion detector output attached to pin 2

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.

 Feel free to use and abuse this code for your own nefarious purposes

 Blair Thompson AKA Justblair

 www.justblair.co.uk
 */

 // constants won't change. They're used here to
 // set pin numbers:
const int mwPin = 2;     // the number of the pushbutton pin
const int ledPin = 13;      // the number of the LED/Buzzer pin

// variables will change:
int mwState = 0;         // variable for reading the pushbutton status
int motionCount = 0;		 // variable 

void setup() {
	// initialize the LED pin as an output:
	pinMode(ledPin, OUTPUT);
	// initialize the pushbutton pin as an input:
	//pinMode(buttonPin, INPUT);
	attachInterrupt(0, handler, CHANGE);
	Serial.begin(115200);
	Serial.println("Hello");
}

void loop() {
	// Nothing to see here :)
}

// The handler is called via interupt and does all the hard work
void handler() {
	// read the state of the pushbutton value:
	mwState = digitalRead(mwPin);

	// check if the Microwave sensor is HIGH.
	// if it is, set the ledPin HIGH and report the count
	if (mwState == HIGH) {
		// turn LED on:   
		motionCount++;
		digitalWrite(ledPin, HIGH);
		Serial.print("Motion: ");
		Serial.println(motionCount);

	}

	// If Microwave sensor is low, switch off the led.
	else {
		// turn LED off:
		digitalWrite(ledPin, LOW);
	}
}
