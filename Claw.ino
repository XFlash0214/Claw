#include <Servo.h>

// ── Tune these after physical assembly ──────────────────────────────────────
const int SERVO_PIN   = 9;
const int SERVO_PIN_2 = 11;
const int OPEN_DEG   = 0;   // degrees when claw is fully open
const int CLOSE_DEG  = 180;  // degrees when claw is fully closed
// ────────────────────────────────────────────────────────────────────────────

Servo claw;
Servo claw2;

// Replace this stub with your chosen control method (potentiometer, serial,
// Bluetooth, etc.) when you're ready.
int getCommand() {
  return OPEN_DEG;  // placeholder: always open
}

void setup() {
  claw.attach(SERVO_PIN);
  claw2.attach(SERVO_PIN_2);
  Serial.begin(9600);
  Serial.println("Claw ready. Pins: " + String(SERVO_PIN) + ", " + String(SERVO_PIN_2));
}

void loop() {
  // Basic open/close sweep so you can verify wiring immediately.
  // Comment this block out once electronics are confirmed and replace with
  // getCommand() logic.
  Serial.println("Opening...");
  claw.write(OPEN_DEG);
  claw2.write(OPEN_DEG);
  delay(1000);

  Serial.println("Closing...");
  claw.write(CLOSE_DEG);
  claw2.write(CLOSE_DEG);
  delay(1000);
}
