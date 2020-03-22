#include <LiquidCrystal.h>

const int V0_PIN = 11;
const int RS_PIN = 10;
const int E_PIN = 9;
const int DB4_PIN = 2;
const int DB5_PIN = 3;
const int DB6_PIN = 4;
const int DB7_PIN = 5;

const int WAIT_TIME = 1000;

LiquidCrystal LCD(RS_PIN, E_PIN, DB4_PIN, DB5_PIN, DB6_PIN, DB7_PIN);

void setup()
{
    pinMode(V0_PIN, OUTPUT);
    LCD.begin(16, 2);
    LCD.setCursor(0, 0);    // Print from upper left
    LCD.print("My Timer: ");
    analogWrite(V0_PIN, 0);
}

void loop()
{
	for (int i=0;i<10;i++)
    {
        LCD.setCursor(0, 1);
        LCD.print("                ");
        LCD.setCursor(i, 1);    // Print from second row
        LCD.print(i);     
        delay(WAIT_TIME);
    }
}
