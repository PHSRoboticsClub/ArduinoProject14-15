//MISSION: approach wall, stop, turn 90 degrees, proceed forward (parallel to wall)

const int motorPinA = 3, motorPinB = 11; //assigns motor control pins
const int sensorPinTrigger = 7, sensorPinEcho = 6; //assigns sensor control pins

void setup() {
  Serial.begin(9600); //sets up serial port
  pinMode(motorPinA, OUTPUT); //sets up first motor
  pinMode(motorPinB, OUTPUT); //second motor
  pinMode(sensorPinTrigger, OUTPUT); //sets up sensor
  pinMode(sensorPinEcho, INPUT); //sets up sensor feedback
  //2nd sensor needed?
}

void loop() {
  //drive forward
  //checkForObstacle()
  //turnClockwise90()
}

void checkForObstacle() {
  //if sensor value <= certain value, stop to avoid collision
}

void turnClockwise90() {
  //turn right wheel back, left wheel forward
}
