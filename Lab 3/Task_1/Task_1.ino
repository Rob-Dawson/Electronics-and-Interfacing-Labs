const int dialPin = 0;    //A0
const int btnPin = 6;     //D6
const int speakerPin = 7; //D7

int freq = 31;
const int length = 30;
const int gap = 20;

void setup() 
{
  //The Arduino Uno contains a number of inbuilt pullup resistors 
  //Instead of connecting an external pullup resistor to prevent debouncing, INPUT can be changed to INPUT_PULLUP
  pinMode(btnPin, INPUT); 
}

void loop() 
{
  int val = analogRead(dialPin);
  if(!digitalRead(btnPin))
  {
    if(val > 31)
    {
      freq = val;
    }
    
    tone(speakerPin, freq, length);
    delay(gap);
  }
}
