#include <TimerOne.h>

String LEDStatus = "OFF";
int BlueLED = 6;
int GreenLED = 7;

void setup()
{
	pinMode(BlueLED, OUTPUT);
	pinMode(GreenLED, OUTPUT);
    Timer1.initialize(250000);
    Timer1.attachInterrupt(blink);
}

void loop()
{
    digitalWrite(BlueLED, HIGH);
    delay(500);
    digitalWrite(BlueLED, LOW);
    delay(500);    
}

void blink()
{
    if (LEDStatus == "Off")
    {
        digitalWrite(GreenLED, HIGH);
        LEDStatus = "On";
    }
    else
    {
        digitalWrite(GreenLED, LOW);
        LEDStatus = "Off";
    }
}
