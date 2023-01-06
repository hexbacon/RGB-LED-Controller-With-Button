#include <Arduino.h>
// Variables
const int analog_wr[3] = {A3, A6, A2};
const int digital_in[3] = {2, 6, 8};
const int analog_ip = A7;
int array_colors[3] = {0, 0, 0};
void changeColor();

void setup() 
{
  // Set all pin and start serial comm
  for(int index(0); index < 3; index++)
  {
    pinMode(analog_wr[index], OUTPUT);
    pinMode(digital_in[index], INPUT_PULLUP);
  }
  pinMode(analog_ip, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  // While running
  while(true)
  {
    // Check if button is pressed
    for(int index(0); index < 3; index++)
    {
      if (digitalRead(digital_in[index]) == LOW)
      {
        // If pressed, read potentiometer value
        int val = analogRead(analog_ip);
        array_colors[index] = map(val, 0, 1024, 0, 255);
        changeColor();
        delay(50);
      }
    }
    delay(10);
  }
}

void changeColor()
{
  for(int index(0); index < 3; index++)
  {
    analogWrite(analog_wr[index], array_colors[index]);
  }
  return;
}