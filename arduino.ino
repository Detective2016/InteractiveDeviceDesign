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

const int buttonPin = 2;
int buttonState = 0;
int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH && pos < 10) {
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(25);                       // waits 15ms for the servo to reach the position
    }
  } else if (buttonState == HIGH && pos > 170){
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(25);                       // waits 15ms for the servo to reach the position
    }
  } else {
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(25);  
  }
}
