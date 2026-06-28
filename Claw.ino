#include <Servo.h>

const int SERVO_PIN   = 9;
const int SERVO_PIN_2 = 11;

const int CLOSE_9  = 180;
const int CLOSE_11 = 0;
const int OPEN_9   = 165;
const int OPEN_11  = 15;

Servo claw;
Servo claw2;

void printAngles() {
  Serial.print("Pin 9 angle: ");
  Serial.print(claw.read());
  Serial.print(" deg  |  Pin 11 angle: ");
  Serial.print(claw2.read());
  Serial.println(" deg");
}

void setup() {
  claw.attach(SERVO_PIN);
  claw2.attach(SERVO_PIN_2);
  claw.write(CLOSE_9);
  claw2.write(CLOSE_11);
  Serial.begin(9600);
  Serial.println("Ready. Type 'o' to open, 'c' to close.");
  printAngles();
}

void loop() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();
    if (cmd == 'o') {
      claw.write(OPEN_9);
      claw2.write(OPEN_11);
      Serial.print("Opened  ->  ");
      printAngles();
    } else if (cmd == 'c') {
      claw.write(CLOSE_9);
      claw2.write(CLOSE_11);
      Serial.print("Closed  ->  ");
      printAngles();
    }
  }
}
