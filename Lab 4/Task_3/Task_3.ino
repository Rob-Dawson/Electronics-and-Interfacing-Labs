/*
	The problem with the previous example is, when the daylight has gone down beyond the threshold we set
	The LED will turn on. Turning the LED on however will increase the value of light detected by the photoresistor
	This will therefore cause the LED to switch on and off rapidly which in bigger night light could cause damage.
	The solution is to use hysteresis. This requires two thresholds, one which is used when the LED is active and one
	When the LED in inactive. The threshold deciding when to turn the light on when the LED is inactive will be greater than when the LED is active.
	This is because when the LED is active, the photoresistor will detect a high amount of light.

	TODO Task 3. Night Light with hysteresis 
		Make a night light that has different switching levels for turning on and turning off.
		Implemented
*/

const int photoPin = 0;
const int redLed = 7;

//Low value = High amounts of Light
const int lightOffThreshold = 400; //The value the photoresistor has to at least be before turning the LED on
const int lightOnThreshold = 500;
void setup()
{
	Serial.begin(9600);
	pinMode(redLed, OUTPUT);
}

// Add the main program code into the continuous loop() function
void loop()
{
	bool ledState = digitalRead(redLed);
	int	lightLevel = analogRead(photoPin);

#ifdef DEBUG
	Serial.print("Light Level: ");
	Serial.println(lightLevel);

#endif // DEBUG

	if (ledState == LOW)
	{
		if (lightLevel > lightOnThreshold)
		{
			digitalWrite(redLed, HIGH);
		}
	}
	else
	{
		if (lightLevel < lightOffThreshold)
		{
			digitalWrite(redLed, LOW);
		}
	}
	delay(1000);
}
