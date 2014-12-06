
  const int motorSpeed = 60; //default speed for motors (in range 0-255) //A Speed of <= 50 did not generate enough power to allow consistent turning...60 works. 
  const int motorPinA = 3, dirPinA = 12, dirPinB = 13, motorPinB = 11; //assigns motor control pins
  const int frontSensorPinTrigger = 5, frontSensorPinEcho = 4; //assigns front sensor control pins
  const int sideSensorPinTrigger = 7, sideSensorPinEcho = 6; //assigns side sensor control pins
  long rawDistanceFront, distanceFront, rawDistanceSide, distanceSide; //variables for sensor values

void setup() {
  Serial.begin(9600); //sets up serial port
  pinMode(motorPinA, OUTPUT); //sets up first motor
  pinMode(motorPinB, OUTPUT); //second motor
  pinMode(dirPinA, OUTPUT); //set both DirPins as OUTPUT
  pinMode(dirPinB, OUTPUT);
  pinMode(frontSensorPinTrigger, OUTPUT); //sets up front sensor
  pinMode(frontSensorPinEcho, INPUT); //front sensor feedback
  pinMode(sideSensorPinTrigger, OUTPUT); //sets up side sensor
  pinMode(sideSensorPinEcho, INPUT); //side sensor feedback
}

void loop() {
  digitalWrite(dirPinB, HIGH); //for some reason, it only works on HIGH
  analogWrite(motorPinA, motorSpeed); //DirPinB and both MotorPins set like this allows for both wheels to move with left wheel reversed. Change DirPin for reversal of right wheel movement.
  analogWrite(motorPinB, motorSpeed);
}
