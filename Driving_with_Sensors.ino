//MISSION: approach wall, stop, turn 90 degrees, proceed forward (parallel to wall)

const int motorPinA = 3, motorPinB = 11; //assigns motor control pins
const int sideSensorPinTrigger = 7, sideSensorPinEcho = 6; //assigns side sensor control pins
const int frontSensorPinTrigger = 5, frontSensorPinEcho = 4; //assigns front sensor control pins
long rawDistance, distance;

void setup() {
  Serial.begin(9600); //sets up serial port
  pinMode(motorPinA, OUTPUT); //sets up first motor
  pinMode(motorPinB, OUTPUT); //second motor
  pinMode(frontSensorPinTrigger, OUTPUT); //sets up sensor
  pinMode(frontSensorPinEcho, INPUT); //sets up sensor feedback
  //2nd sensor needed?
}

void loop() {
  //drive forward
  checkForObstacle();
  //turnClockwise90()
}

void checkForObstacle() { //mostly ripped from Ultrasonic file
  //if sensor value <= certain value, stop to avoid collision
  digitalWrite(frontSensorPinTrigger, HIGH);
  delayMicroseconds(10); // short delay
  digitalWrite(frontSensorPinTrigger, LOW); //set trigger low
  rawDistance = pulseIn(frontSensorPinEcho, HIGH); //read echo pin
  distance = (rawDistance/2) / 29.1; // convert to cm
  Serial.print(distance);
  Serial.println("cm");
}

void turnClockwise90() {
  //turn right wheel back, left wheel forward
}
