/*
	TODO Task 2. Night Light with Timer: 
			Make a night light that has a delay so that it will only turn off after 3 seconds
			Implemented

	TODO Extension Task 
		The current program pauses the execution flow due to the 'delay' method. This can cause problems if multiple devices are connected to the Arduino
		Find a method which will allow the execution flow to continue while keeping the same functionality. I.e. the LED will stay lit for 3 seconds.
		Not Implemented
*/
#define DEBUG

const int photoPin = 0;
const int redLed = 7;

const int darkLevel = 500; //The value the photoresistor has to at least be before turning the LED on
void setup()
{
	Serial.begin(9600);
	pinMode(redLed, OUTPUT);
}

// Add the main program code into the continuous loop() function
void loop()
{
	int lightLevel = analogRead(photoPin);
#ifdef DEBUG
	Serial.print("Light Level: ");
	Serial.println(lightLevel);

#endif // DEBUG

	if (lightLevel > darkLevel)
	{
		digitalWrite(redLed, HIGH);
		delay(3000);
	}
	else
	{
		digitalWrite(redLed, LOW);
	}
	delay(1000);
}
