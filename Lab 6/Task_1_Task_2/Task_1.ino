//TODO Task 1 Alter the code so that the stepper motors rotation slows down.
//TODO Task 2 Alter the code to make the motor speed up, find out if there is a speed limit.  

//Both these tasks can be completed by altering the motorSpeed variable.
//In the program, the motorSpeed variable provides a delay before the next coil in the stepper motor is magnetised
const int motorPin1 = 8; //IN1
const int motorPin2 = 9; //IN2
const int motorPin3 = 10; //IN3
const int motorPin4 = 11; //IN4

const int motorSpeed = 1500; 
const int countsPerRev = 512; //Number of steps per full revolution
int count = 0;

//These values indicate which coils are magnetised thereby pulling the rotor towards the next coil
//The first element magnetises the first coil, the second magnetises coil 1 and coil 2
//Both these coils have the same magnetic field and so pull the rotor to be the same distance from coil 1 and coil 2
//The third element finally demagnetises the first coil but keeps the second magnetised
//This pulls the rotor to the second coil. This process continues around the rotor

int lookup[8] = { B1000, B1100, B0100, B0110, B0010, B0011, B0001, B1001 };

void setup()
{
	pinMode(motorPin1, OUTPUT);
	pinMode(motorPin2, OUTPUT);
	pinMode(motorPin3, OUTPUT);
	pinMode(motorPin4, OUTPUT);
}

// Add the main program code into the continuous loop() function
void loop()
{
	if (count < countsPerRev)
	{
		clockwise();
	}
	else if (count == countsPerRev * 2)
	{
		count = 0;
	}
	else
	{
		anticlockwise();
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