//Initialize Servos
#include <Servo.h>
Servo servoA1; 
Servo servoA2;
Servo servoB1; 
Servo servoB2;
Servo servoC1; 
Servo servoC2;
Servo servoD1; 
Servo servoD2;

int rcPin = 13;
unsigned long duration;

//0=Backward 1=Forwards
int stepDirection = 0;
char legToMove = 'A';

int stepsToMove = 1;

//0=Back 1=Centered 2=Forward
int legApos = 1;
int legBpos = 1;
int legCpos = 1;
int legDpos = 1;

int servoA1pos = 0;
int servoA2pos = 90;
int servoB1pos = 0;
int servoB2pos = 90;
int servoC1pos = 0;
int servoC2pos = 90;
int servoD1pos = 0;
int servoD2pos = 90;


void setup()
{
  
  Serial.begin(9600);
  
  //Setup RC Input Pin
  pinMode(13, INPUT);
  
  // Attach Digital IO Pins
  servoA1.attach(4); // servo on digital pin 4
  servoA2.attach(5); // servo on digital pin 5
  servoA1.attach(6); // servo on digital pin 6
  servoA2.attach(7); // servo on digital pin 7
  servoA1.attach(8); // servo on digital pin 8
  servoA2.attach(9); // servo on digital pin 9
  servoA1.attach(10); // servo on digital pin 10
  servoA2.attach(11); // servo on digital pin 11

  Serial.println("Setting Servo's to Default Locations");
  servoA1.write(servoA1pos);
  servoA2.write(servoA2pos);
  servoB1.write(servoB1pos);
  servoB2.write(servoB2pos);
  servoC1.write(servoC1pos);
  servoC2.write(servoC2pos);
  servoD1.write(servoD1pos);
  servoD2.write(servoD2pos);
  
}
 
 
 
void stepLeg(int stepDirection, char legToMove)
{
int stepSize;
  
  if (stepDirection = 0)
   {
     stepSize = 1;
   }
   else
   {
     stepSize =-1;
   }
    
  switch (legToMove) {
    case 'A':
    {
      Serial.println("Lifting Leg A");
      while (servoA1pos < 179);
      {
      servoA1.write(servoA1pos++);
      delay(1);
      }

      Serial.println("Move Leg A");
      while (servoA2pos != 1|179); // While the servo is not at either ends of its extension
      {
        servoA2pos = servoA2pos+stepSize;
        Serial.print("Setting Servo to ");
        Serial.println(servoA2pos);
        servoA2.write(servoA2pos);
        delay(1);
      }
      Serial.println("Lower Leg A");
      while (servoA1pos > 1 );
      {
        servoA1.write(servoA1pos--);
        delay(1);
      }
    }
    if (stepDirection = 0)
       {
         legApos = 0;
       }
       else
       {
         legApos = 2;
       }
    break;

    case 'B':
    {
      Serial.println("Lifting Leg B");
      while (servoB1pos < 179);
      {
      servoA1.write(servoB1pos++);
      delay(1);
      }

      Serial.println("Move Leg B");
      while (servoB2pos != 1|179); // While the servo is not at either ends of its extension
      {
        servoB2pos = servoB2pos+stepSize;
        Serial.print("Setting Servo to ");
        Serial.println(servoB2pos);
        servoB2.write(servoB2pos);
        delay(1);
      }
      Serial.println("Lower Leg B");
      while (servoB1pos > 1 );
      {
        servoB1.write(servoB1pos--);
        delay(1);
      }
    }
    if (stepDirection = 0)
       {
         legApos = 0;
       }
       else
       {
         legApos = 2;
       }
    break;
    
    case 'C':
    {
      Serial.println("Lifting Leg C");
      while (servoC1pos < 179);
      {
      servoC1.write(servoC1pos++);
      delay(1);
      }

      Serial.println("Move Leg C");
      while (servoC2pos != 1|179); // While the servo is not at either ends of its extension
      {
        servoC2pos = servoC2pos+stepSize;
        Serial.print("Setting Servo to ");
        Serial.println(servoC2pos);
        servoC2.write(servoC2pos);
        delay(1);
      }
      Serial.println("Lower Leg C");
      while (servoC1pos > 1 );
      {
        servoA1.write(servoC1pos--);
        delay(1);
      }
    }
    legBpos = 2;
    break;

    case 'D':
    {
      Serial.println("Lifting Leg D");
      while (servoD1pos < 179);
      {
      servoD1.write(servoD1pos++);
      delay(1);
      }

      Serial.println("Move Leg D");
      while (servoD2pos != 1|179); // While the servo is not at either ends of its extension
      {
        servoD2pos = servoD2pos+stepSize;
        Serial.print("Setting Servo to ");
        Serial.println(servoD2pos);
        servoD2.write(servoD2pos);
        delay(1);
      }
      Serial.println("Lower Leg D");
      while (servoD1pos > 1 );
      {
        servoD1.write(servoD1pos--);
        delay(1);
      }
    }
    if (stepDirection = 0)
       {
         legApos = 0;
       }
       else
       {
         legApos = 2;
       }
    break;
  }
}


void stepForward()
{
 while ( stepsToMove > 0 );
 {
  Serial.print("Steps to Move: ");
  Serial.println(stepsToMove);
  stepLeg(1, 'A'); //Direction Forward, Leg A
  stepLeg(1, 'D'); //Direction Forward, Leg D
  stepLeg(1, 'B'); //Direction Forward, Leg B
  stepLeg(1, 'C'); //Direction Forward, Leg C
  stepsToMove=stepsToMove-1;
 }
}

void loop()
{
  duration = pulseIn(rcPin, HIGH); 
 
  if ( duration > 1550 )
  {
    Serial.println("GO");
    stepsToMove=stepsToMove+1;
    stepForward() ;
    delay(1);
  }
}
