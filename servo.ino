#include <Servo.h>

///////////////////servoA//////////////////////
Servo servoA;
int servoPinA = 16;
int buttonReadA = 4;

////////////////////servoB////////////////////
Servo servoB;  
int servoPinB = 19; //~
int buttonReadB = 3;

////////////////////servoC////////////////////
Servo servoC;  
int servoPinC = 17; //~
int buttonReadC = 5;

////////////////////servoD////////////////////
Servo servoD;  
int servoPinD = 14; //~
int buttonReadD = 6;

///////////////////servoE////////////////////
Servo servoE;
int servoPinE = 9;
int buttonReadE = 2;


////////////////angleA+E/////////////
int angle = 90;   // initial angle  for servo
int angleStep = 5;
const int minAngle = 0;
const int maxAngle = 180;

////////////////angleB/////////////
int angleB = 90;   // initial angle  for servo
int angleStepB = 5;
const int minAngleB = 0;
const int maxAngleB = 180;

////////////////angleC/////////////
int angleC = 90;   // initial angle  for servo
int angleStepC = 5;
const int minAngleC = 0;
const int maxAngleC = 180;

////////////////angleD/////////////
int angleD = 90;   // initial angle  for servo
int angleStepD = 5;
const int minAngleD = 0;
const int maxAngleD = 180;



////////////clockA///////////
long previousTime = 0;
long intvTime = 100;

////////////clockB///////////
long previousTimeB = 0;
long intvTimeB = 100;

////////////clockC///////////
long previousTimeC = 0;
long intvTimeC = 100;

////////////clockD///////////
long previousTimeD = 0;
long intvTimeD = 100;



int buttonPushedA = 0;
int buttonPushedB = 0;
int buttonPushedC = 0;
int buttonPushedD = 0;
int buttonPushedE = 0;

/////////////////////////////////////

void setup() {
  
  Serial.begin(9600);          //  setup serial

  ////////////servoA
  servoA.attach(servoPinA);  // attaches the servo on pin 3 to the servo object
  pinMode(buttonReadA, INPUT);

  ////////////servoB
  servoB.attach(servoPinB);  // attaches the servo on pin 3 to the servo object
  pinMode(buttonReadB, INPUT);

  ////////////servoC
  servoC.attach(servoPinC);  // attaches the servo on pin 3 to the servo object
  pinMode(buttonReadC, INPUT);
  
  ////////////servoD
  servoD.attach(servoPinD);  // attaches the servo on pin 3 to the servo object
  pinMode(buttonReadD, INPUT);
    
  ////////////servoE
  servoE.attach(servoPinE);  // attaches the servo on pin 3 to the servo object
  pinMode(buttonReadE, INPUT);


  Serial.println("AND gate input received");
}

void loop() {
  
    Serial.print("A:");
    Serial.println(digitalRead(buttonReadA));
    Serial.print("B:");
    Serial.println(digitalRead(buttonReadB));
    Serial.print("C:");
    Serial.println(digitalRead(buttonReadC));
    Serial.print("D:");
    Serial.println(digitalRead(buttonReadD));
    Serial.print("E:");
    Serial.println(digitalRead(buttonReadE));
    

///////////////////A servo////////////////////////
  if (digitalRead(buttonReadA) == HIGH) {
    buttonPushedA = 1;
  }

  if ( buttonPushedA && millis() - previousTime >= intvTime) {
    // change the angle for next time through the loop:
    angle = angle + angleStep;

    // reverse the direction of the moving at the ends of the angle:
    if (angle <= minAngle || angle >= maxAngle) {
      angleStep = -angleStep;
      buttonPushedA = 0;
    }
    previousTime = millis();
    servoA.write(angle); // move the servo to desired angle

    }


///////////////////B servo////////////////////////
  if (digitalRead(buttonReadB) == HIGH) {
    buttonPushedB = 1;
  }

  if ( buttonPushedB && millis() - previousTimeB >= intvTimeB) {
    // change the angle for next time through the loop:
    angleB = angleB + angleStepB;

    // reverse the direction of the moving at the ends of the angle:
    if (angleB <= minAngleB || angleB >= maxAngleB) {
      angleStepB = -angleStepB;
      buttonPushedB = 0;
    }
    previousTimeB = millis();
    servoB.write(angleB); // move the servo to desired angle

    }


///////////////////C servo////////////////////////
  if (digitalRead(buttonReadC) == HIGH) {
    buttonPushedC = 1;
  }

  if ( buttonPushedC && millis() - previousTimeC >= intvTimeC) {
    // change the angle for next time through the loop:
    angleC = angleC + angleStepC;



    // reverse the direction of the moving at the ends of the angle:
    if (angleC <= minAngleC || angleC >= maxAngleC) {
      angleStepC = -angleStepC;
      buttonPushedC = 0;
    }
    previousTimeC = millis();
    servoC.write(angleC); // move the servo to desired angle

    }
    

///////////////////D servo////////////////////////
  if (digitalRead(buttonReadD) == HIGH) {
    buttonPushedD = 1;
  }

  if ( buttonPushedD && millis() - previousTimeD >= intvTimeD) {
    // change the angle for next time through the loop:
    angleD = angleD + angleStepD;

    // reverse the direction of the moving at the ends of the angle:
    if (angleD <= minAngleD || angleD >= maxAngleD) {
      angleStepD = -angleStepD;
      buttonPushedD = 0;
    }
    previousTimeD = millis();
    servoD.write(angleD); // move the servo to desired angle

    }


   
///////////////////E servo////////////////////////
  if (digitalRead(buttonReadE) == HIGH) {
    buttonPushedE = 1;
  }

  if ( buttonPushedE && millis() - previousTime >= intvTime) {
    // change the angle for next time through the loop:
    angle = angle + angleStep;

    // reverse the direction of the moving at the ends of the angle:
    if (angle <= minAngle || angle >= maxAngle) {
      angleStep = -angleStep;
      buttonPushedE = 0;
    }
    previousTime = millis();
    servoE.write(angle); // move the servo to desired angle

  }
}
