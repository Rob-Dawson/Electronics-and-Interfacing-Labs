//TODO Task 3 Alter the code so that motor rotates and stops at a random position after at least one full rotation.
const int motorPin1 = 8; //IN1
const int motorPin2 = 9; //IN2
const int motorPin3 = 10; //IN3
const int motorPin4 = 11; //IN4

const int motorSpeed = 1500;
int countsPerRev = 512; //Number of steps per full revolution
int count = 0;

int lookup[8] = { B1000, B1100, B0100, B0110, B0010, B0011, B0001, B1001 };



void setup()
{
	Serial.begin(9600);
	pinMode(motorPin1, OUTPUT);
	pinMode(motorPin2, OUTPUT);
	pinMode(motorPin3, OUTPUT);
	pinMode(motorPin4, OUTPUT);
}

// Add the main program code into the continuous loop() function
void loop()
{
#ifdef DEBUG
	Serial.println("Count ");
	Serial.print(count);
	Serial.println("countsPerRev: ");
	Serial.print(countsPerRev);
#endif // DEBUG

	if (count < countsPerRev)
	{
		clockwise();
	}

	else
	{
		countsPerRev = random(1, 1000);
		digitalWrite(motorPin1, LOW);
		digitalWrite(motorPin2, LOW);
		digitalWrite(motorPin3, LOW);
		digitalWrite(motorPin4, LOW);
		count = 0;
		delay(1000);
	}
	count++;
}


void clockwise()
{
	for (int i = 7; i >= 0; --i)
	{
		setOutput(i);
		delayMicroseconds(motorSpeed);
	}
}

void anticlockwise()
{
	for (int i = 0; i < 8; ++i)
	{
		setOutput(i);
		delayMicroseconds(motorSpeed);
	}
}

void setOutput(int out)
{
	digitalWrite(motorPin1, bitRead(lookup[out], 0));
	digitalWrite(motorPin2, bitRead(lookup[out], 1));
	digitalWrite(motorPin3, bitRead(lookup[out], 2));
	digitalWrite(motorPin4, bitRead(lookup[out], 3));
}