//MISSION: approach obstacle, stop without a collision, turn 90 degrees, then proceed forward

const int motorSpeed = 100; //default speed for motors (in range 0-255)
const int motorPinA = 3, motorPinB = 11; //assigns motor control pins
const int dirPinA = 12, dirPinB = 13; //assigns motor direction pins
const int frontSensorPinTrigger = 5, frontSensorPinEcho = 4; //assigns front sensor control pins
const int sideSensorPinTrigger = 7, sideSensorPinEcho = 6; //assigns side sensor control pins
long rawDistanceFront, distanceFront, rawDistanceSide, distanceSide; //variables for sensor values

void setup() {
  Serial.begin(9600); //sets up serial port
  pinMode(motorPinA, OUTPUT); //sets up right motor
  pinMode(dirPinA, OUTPUT);
  pinMode(motorPinB, OUTPUT); //left motor
  pinMode(dirPinB, OUTPUT);
  pinMode(frontSensorPinTrigger, OUTPUT); //sets up front sensor
  pinMode(frontSensorPinEcho, INPUT); //front sensor feedback
  pinMode(sideSensorPinTrigger, OUTPUT); //sets up side sensor
  pinMode(sideSensorPinEcho, INPUT); //side sensor feedback
}

void loop() {
  digitalWrite(dirPinA, HIGH); //set right motor forward
  digitalWrite(dirPinB, HIGH); //set left motor forward
  analogWrite(motorPinA, motorSpeed);
  analogWrite(motorPinB, motorSpeed);
  checkForObstacle();
}

void checkForObstacle() {
  //if sensor value <= certain value, stop to avoid collision
  digitalWrite(frontSensorPinTrigger, HIGH); //send a ping with front sensor
  delayMicroseconds(10); // short delay
  digitalWrite(frontSensorPinTrigger, LOW); //set trigger low
  rawDistanceFront = pulseIn(frontSensorPinEcho, HIGH); //read echo pin
  distanceFront = (rawDistanceFront/2) / 29.1; // convert to cm
  
  if (distanceFront <= 20) {
    digitalWrite(motorPinA, LOW); //stop motor A
    digitalWrite(motorPinB, LOW); //stop motor B
    delay(100);
    turn90Degrees(); //now that we're stopped, turn to avoid the obstacle
  }
}

void turn90Degrees() {
  //check for an obstacle on the left
  digitalWrite(sideSensorPinTrigger, HIGH); //send a ping with side sensor
  delayMicroseconds(10); // short delay
  digitalWrite(sideSensorPinTrigger, LOW); //set trigger low
  rawDistanceSide = pulseIn(sideSensorPinEcho, HIGH); //read echo pin
  distanceSide = (rawDistanceSide/2) / 29.1; // convert to cm

  if (distanceSide <= 20) {
        Serial.println("HOLY S*** THERE'S SOMETHING ON THE LEFT! TURN RIGHT!");
	//turn right
        digitalWrite(dirPinA, LOW); //runs right motor backward
        digitalWrite(dirPinB, HIGH); //runs left motor forward
        analogWrite(motorPinA, motorSpeed);
        analogWrite(motorPinB, motorSpeed);
        delay(500);
  } else {
	Serial.println("Nothing on the left, turning that way.");
	//turn left
        digitalWrite(dirPinA, HIGH); //runs right motor forward
        digitalWrite(dirPinB, LOW); //runs left motor backward
        analogWrite(motorPinA, motorSpeed);
        analogWrite(motorPinB, motorSpeed);
        delay(500);
  }
}
