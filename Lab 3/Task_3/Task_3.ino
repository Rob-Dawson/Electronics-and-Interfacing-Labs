const int dialPin = 0;    //A0
const int btnPin = 6;     //D6
const int speakerPin = 7; //D7

int freq = 31;
const int length = 30;

bool btnState = false;
bool previousBtnState = false;

void setup()
{
  //The Arduino Uno contains a number of inbuilt pullup resistors 
  //Instead of connecting an external pullup resistor to prevent debouncing, INPUT can be changed to INPUT_PULLUP
  pinMode(btnPin, INPUT);
}

void loop()
{
  int val = analogRead(dialPin);
  btnState = digitalRead(btnPin);

  if (btnState != previousBtnState)
  {
    previousBtnState = btnState;
    if (!btnState)
    {
      if (val > 31)
      {
        freq = val;
      }
      
      for (freq = 31; freq < 2000; freq += 200)
      {
        tone(speakerPin, freq, length);
        delay(length + 1);
      }

      for (freq = 2000; freq > 31; freq -= 200)
      {
        tone(speakerPin, freq, length);
        delay(length + 1);
      }
    }
  }
}
