//MISSION: approach wall, stop, turn 90 degrees, proceed forward (parallel to wall)

const int motorPinA = 3, motorPinB = 11; //assigns motor control pins
const int sensorPinTrigger = 7, sensorPinEcho = 6; //assigns sensor control pins
long rawDistance, distance;

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

void checkForObstacle() { //mostly ripped from Ultrasonic file
  //if sensor value <= certain value, stop to avoid collision
  digitalWrite(sensorPinTrigger, HIGH);
  delayMicroseconds(10); // short delay
  digitalWrite(sensorPinTrigger, LOW); //set trigger low
  rawDistance = pulseIn(sensorPinEcho, HIGH); //read echo pin
  distance = (rawDistance/2) / 29.1; // convert to cm
}

void turnClockwise90() {
  //turn right wheel back, left wheel forward
}
