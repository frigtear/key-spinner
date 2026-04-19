#include <Arduino.h>
#include <ESP32Servo.h>

#define SERVO_PIN 27
#define MOVE_SPEED 3
#define SERIAL_BAUD 115200
#define PERIOD 50
#define DELAY 50

#define GO_LEFT_PIN 26
#define GO_RIGHT_PIN 25
#define GO_

Servo myServo;

int target_location = 90;

void setup() {
  Serial.begin(SERIAL_BAUD);
  myServo.setPeriodHertz(PERIOD);
  myServo.attach(SERVO_PIN, 500, 2500);

  pinMode(GO_LEFT_PIN, INPUT_PULLUP);
  pinMode(GO_RIGHT_PIN, INPUT_PULLUP);

  myServo.write(target_location);
}

void loop() {
  if (digitalRead(GO_LEFT_PIN) == LOW && target_location < 180) {
    target_location += MOVE_SPEED;
  }

  if (digitalRead(GO_RIGHT_PIN) == LOW && target_location > 0) {
    target_location -= MOVE_SPEED;
  }

  Serial.println(target_location);
  myServo.write(target_location);
  delay(DELAY);
}