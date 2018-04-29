/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

const int buttonPin = 3;
const int ledbuttonPin = 6;
int ledPin = 8;
int buttonState = 0;
int ledbuttonState = 0;
int total = 0;
int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(buttonPin, INPUT);
  pinMode(ledbuttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  ledbuttonState = digitalRead(ledbuttonPin);
  if (buttonState == HIGH && pos < 10) {
    for (pos = 0; pos <= 55; pos += 1) { // goes from 0 degrees to 55 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(25);                       // waits 25ms for the servo to reach the position
    }
  } else if (buttonState == HIGH && pos > 55){
    for (pos = 55; pos >= 0; pos -= 1) { // goes from 55 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(25);                       // waits 25ms for the servo to reach the position
    }
  } else {
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(25);  
  }
  if (total > 1000) {
    total = 0;
  }
  if (ledbuttonState == HIGH) {
    total = total + 1;
    delay(1000);
  }
  if (total%2 == 0) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
  }
}
