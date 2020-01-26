const int buttonPinA0 = A0;
const int buttonPinA1 = A1;
const int ledPin3   = 3;
const int ledPin4   = 4;
const int ledPin5   = 5;
const int ledPin6   = 6;
const int ledPin7   = 7;
const int ledPin8   = 8;

int buttonStateL = 0;
int buttonStateR = 0;

void setup()
{
  DDRD = 0xFF;
  DDRB = 0xFF;
  PORTD= 0x01;
}

void loop()
{
  buttonStateL = digitalRead(buttonPinA0);
  buttonStateR = digitalRead(buttonPinA1);
  
  if(buttonStateL == LOW)//shift left
  {
    if(PORTD == 0x80)
    {
      PORTD = 0x01;

    } else {
      PORTD=PORTD<<1;
    }
    delay(500);
  }
  
  if(buttonStateR == LOW)//shift right
  {
    if(PORTD == 0x01)
    {
      PORTD = 0x80;

    } else{
      PORTD=PORTD>>1;
    }
    delay(500);
  }
}
