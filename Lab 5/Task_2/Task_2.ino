const int pinA = 2; //pin 11 on display
const int pinB = 3; //pin 7 on display
const int pinC = 4; //pin 4 on display
const int pinD = 5; //pin 2 on display
const int pinE = 6; //pin 1 on display
const int pinF = 7; //pin 10 on display
const int pinG = 8; //pin 5 on display 

const int D1 = 9; //pin 12 on display
const int D2 = 10; //pin 9 on display
const int D3 = 11; //pin 8 on display
const int D4 = 12; //pin 6 on display

const int timeDelay = 1000;

const int pinLookup[] =
{
	pinA, pinB, pinC, pinD, pinE, pinF, pinG
};

int lookup[10][8] =
{
	{1,1,1,1,1,1,0},		//0
	{0,1,1,0,0,0,0},		//1
	{1,1,0,1,1,0,1},		//2
	{1,1,1,1,0,0,1},		//3
	{0,1,1,0,0,1,1},		//4
	{1,0,1,1,0,1,1},		//5
	{1,0,1,1,1,1,1},		//6
	{1,1,1,0,0,0,0},		//7
	{1,1,1,1,1,1,1},		//8
	{1,1,1,1,0,1,1},		//9
};

void setup()
{
	for (int i = 0; i < 7; ++i)
	{
		pinMode(pinLookup[i], OUTPUT);
	}

	pinMode(D1, OUTPUT);
	pinMode(D2, OUTPUT);
	pinMode(D3, OUTPUT);
	pinMode(D4, OUTPUT);
}


int count = 0;
void loop()
{
	if (count > 9)
	{
		count = 0;
	}

	digitalWrite(D1, LOW);
	digitalWrite(D2, LOW);
	digitalWrite(D3, LOW);
	digitalWrite(D4, LOW);

	displayNumber(count);
	delay(1000);

	digitalWrite(D1, LOW);
	digitalWrite(D2, HIGH);
	digitalWrite(D3, HIGH);
	digitalWrite(D4, HIGH);
	
	displayNumber(count);
	delay(100);

	//digitalWrite(D1, HIGH);
	//digitalWrite(D2, LOW);
	//digitalWrite(D3, HIGH);
	//digitalWrite(D4, HIGH);

	//displayNumber(count);
	//delay(100);

	//digitalWrite(D1, HIGH);
	//digitalWrite(D2, HIGH);
	//digitalWrite(D3, LOW);
	//digitalWrite(D4, HIGH);

	//displayNumber(count);
	//delay(100);

	//digitalWrite(D1, HIGH);
	//digitalWrite(D2, HIGH);
	//digitalWrite(D3, HIGH);
	//digitalWrite(D4, LOW);

	//displayNumber(count);
	//delay(100);
	count++;
}

void displayNumber(int number)
{
	for (int j = 0; j < 7; ++j)
	{
		digitalWrite(pinLookup[j], lookup[number][j]);
	}
}
