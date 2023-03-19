#include <NewPing.h>
#include <toneAC.h>
int buzz_it(unsigned long int frequency,  int intensity, unsigned long int milliseconds);
//buzzer in pins 9 and 10
//ultrasonic in pins 6,7 5v ground
NewPing sonar(6, 7, 400);
// for the untrasonic sensor
unsigned long int start_time = millis();
unsigned long int ping_time = 1000;

unsigned long int my_tone; 
unsigned long int sound_level; 
unsigned long int sound_length; 
void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  unsigned long int milliseconds = millis();
  unsigned long int ping_time = 1000;
  unsigned long int current_time = millis();
  start_time = current_time;
  int cm = sonar.ping_cm();
  double inches = cm / 2.54;
  int feet = inches / 12;
      
      //noTone(buzzer_port);
      Serial.print(feet);
      Serial.print("\n");
      // loop_time is the time between each pulse
      unsigned long int loop_time = 100;
      unsigned long int first_time = millis();
      unsigned long int start_loop = millis();
      unsigned long int freq;
      int intense;
      unsigned long int beep_ms;
      if (feet > 10)
      {
        toneAC(0);        
      }
      else if (feet == 10)
      {
        freq = 400;
        intense = 10;
        beep_ms = 400;
        buzz_it(freq, intense, beep_ms);
        //delay(96);
      }
      else if (feet == 9)
      {
        int i;
        for (i = 0; i < 2; i++)
        {
          freq = 400;
          intense = 10;
          beep_ms = 300;
          buzz_it(freq, intense, beep_ms);
          delay(100);
        }
      }
      else if (feet == 8)
      {
        int i;
        for (i = 0; i < 3; i++)
        {
          freq = 400;
          intense = 10;
          beep_ms = 200;
          buzz_it(freq, intense, beep_ms);
          delay(80);
        }
      }
      else if (feet == 7)
      {
        int i;
        for (i = 0; i < 4; i++)
        {
          freq = 400;
          intense = 10;
          beep_ms = 150;
          buzz_it(freq, intense, beep_ms);
          delay(72);
        }
      }
      else if (feet == 6)
      {
        int i;
        for (i = 0; i < 5; i++)
        {
          freq = 400;
          intense = 10;
          beep_ms = 120;
          buzz_it(freq, intense, beep_ms);
          delay(64);
        }
      }
      else if (feet == 5)
      {
        int i;
        for (i = 0; i < 6; i++)
        {
          freq = 400;
          intense = 10;
          beep_ms = 100;
          buzz_it(freq, intense, beep_ms);
          delay(56);
        }
      }

      else if (feet == 4)
      {
        int i;
        for (i = 0; i < 7; i++)
        {
          freq = 400;
          intense = 10;
          beep_ms = 88;
          buzz_it(freq, intense, beep_ms);
          delay(48);
        }
      }
      else if (feet == 3)
      {
        Serial.print("correctfunction");
        int i;
        for (i = 0; i < 8; i++)
        {
          freq = 400;
          intense = 10;
          beep_ms = 75;
          buzz_it(freq, intense, beep_ms);
          delay(40);
        }
      }
      else if (feet < 3)
      {
        freq = 400;
        intense = 10;
        beep_ms = 1000;
        buzz_it(freq, intense, beep_ms);
      }
      delay(500);
}

int buzz_it(unsigned long int frequency, int intensity, unsigned long int milliseconds)
{
  toneAC(frequency, intensity, milliseconds);
  return 0;
}
