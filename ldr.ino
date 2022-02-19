int ledPins[] = {2, 3, 11, 12};
boolean ledStates[] = {true, true, true, true}; int brightness = 0;
int fadeAmount = 1; int ledTotal = sizeof(ledPins) / sizeof(int); int sensor1Pin = A0;
int sensor1Val;



void setup() {
for (int i = 0; i < ledTotal; i++) {
pinMode(ledPins[i], OUTPUT);
Serial.begin(9600);
}
}
void loop() {
sensor1Val = analogRead(sensor1Pin);
delay (50);
Serial.print("sensor value:");
Serial.println(sensor1Val);



for (int i = 0; i < ledTotal; i++) {
if (sensor1Val < 140)
{
digitalWrite(ledPins[i], LOW);

} else {
digitalWrite(ledPins[i], HIGH); // sets the digital pin 13 on

digitalWrite(ledPins[i], ledStates[i]);
}
}
}
