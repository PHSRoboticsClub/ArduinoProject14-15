//MISSION: approach wall and stop without a collision. NEXT: turn 90 degrees, proceed forward (parallel to wall)

  const int motorSpeed = 50; //default speed for motors (in range 0-255)
  const int motorPinA = 3, motorPinB = 11; //assigns motor control pins
  const int frontSensorPinTrigger = 5, frontSensorPinEcho = 4; //assigns front sensor control pins
  const int sideSensorPinTrigger = 7, sideSensorPinEcho = 6; //assigns side sensor control pins
  long rawDistanceFront, distanceFront, rawDistanceSide, distanceSide; //variables for sensor values

void setup() {
  Serial.begin(9600); //sets up serial port
  pinMode(motorPinA, OUTPUT); //sets up first motor
  pinMode(motorPinB, OUTPUT); //second motor
  pinMode(frontSensorPinTrigger, OUTPUT); //sets up front sensor
  pinMode(frontSensorPinEcho, INPUT); //front sensor feedback
  pinMode(sideSensorPinTrigger, OUTPUT); //sets up side sensor
  pinMode(sideSensorPinEcho, INPUT); //side sensor feedback
}

void loop() {
  analogWrite(motorPinA, motorSpeed);
  analogWrite(motorPinB, motorSpeed);
  checkForObstacle();
}

void checkForObstacle() { //mostly ripped from Ultrasonic file
  //if sensor value <= certain value, stop to avoid collision
  digitalWrite(frontSensorPinTrigger, HIGH);
  delayMicroseconds(10); // short delay
  digitalWrite(frontSensorPinTrigger, LOW); //set trigger low
  rawDistanceFront = pulseIn(frontSensorPinEcho, HIGH); //read echo pin
  distanceFront = (rawDistanceFront/2) / 29.1; // convert to cm
  Serial.print(distanceFront);
  Serial.println("cm");
  
  if (distanceFront <= 20) {
    digitalWrite(motorPinA, LOW); //stop motor A
    digitalWrite(motorPinB, LOW); //stop motor B
    delay(100);
    turn90Degrees(); //now that we're stopped, turn to avoid the obstacle
    }
}

void turn90Degrees() {
  //check for obstacle with side sensor
  digitalWrite(sideSensorPinTrigger, HIGH);
  delayMicroseconds(10); // short delay
  digitalWrite(sideSensorPinTrigger, LOW); //set trigger low
  rawDistanceSide = pulseIn(sideSensorPinEcho, HIGH); //read echo pin
  distanceSide = (rawDistanceSide/2) / 29.1; // convert to cm
  
  if (distanceSide <= 20) { //check for a wall on the left
	Serial.println("HOLY S*** THERE'S SOMETHING ON THE LEFT! TURN RIGHT!");
	//turn right
        analogWrite(motorPinB, motorSpeed);
        delay(500);
        //use millis() to calculate elapsed time for delay before loop() drives forward
  } else {
	//Serial.print(distanceSide);
	Serial.println("Nothing on the left, turning that way.");
	//turn left
        analogWrite(motorPinA, motorSpeed);
        delay(500);
        //use millis() to calculate elapsed time for delay before loop() drives forward
  }
}
