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
	}
	else
	{
		digitalWrite(redLed, LOW);
	}
	delay(1000);
}
