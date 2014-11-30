const int motorPin = 3;


void setup()
{
  pinMode(motorPin, OUTPUT); // Set up the motor pin to be an output
  Serial.begin(9600); // Set up the serial port
}


void loop()
{
  // motorOnThenOff(); // This function turns the motor on and off like the blinking LED.
  // motorOnThenOffWithSpeed(); // This function alternates between two speeds.
  // motorAcceleration(); // This function slowly accelerates the motor to full speed then back down to zero.
     serialSpeed(); //This function allows input in the serial monitor (magnifying glass in upper right) to control the speed of the motor (in range 0-255)
}


void motorOnThenOff()
{
  int onTime = 3000;  // milliseconds to turn the motor on
  int offTime = 3000; // milliseconds to turn the motor off
  
  digitalWrite(motorPin, HIGH); // turn the motor on (full speed)
  delay(onTime);                // delay for onTime milliseconds
  digitalWrite(motorPin, LOW);  // turn the motor off
  delay(offTime);               // delay for offTime milliseconds
}


void motorOnThenOffWithSpeed()
{
  int Speed1 = 200;  // between 0 (stopped) and 255 (full speed)
  int Time1 = 3000;  // milliseconds for speed 1
  
  int Speed2 = 50;   // between 0 (stopped) and 255 (full speed)
  int Time2 = 3000;  // milliseconds to turn the motor off
  
  analogWrite(motorPin, Speed1);  // turns the motor On
  delay(Time1);                   // delay for onTime milliseconds
  analogWrite(motorPin, Speed2);  // turns the motor Off
  delay(Time2);                   // delay for offTime milliseconds
}


void motorAcceleration()
{
  int speed;
  int delayTime = 20; // milliseconds between each speed step
  
  // accelerate the motor

  for(speed = 0; speed <= 255; speed++)
  {
    analogWrite(motorPin,speed);	// set the new speed
    delay(delayTime);           	// delay between speed steps
  }
  
  // decelerate the motor

  for(speed = 255; speed >= 0; speed--)
  {
    analogWrite(motorPin,speed);	// set the new speed
    delay(delayTime);           	// delay between speed steps
  }
}


void serialSpeed()
{
  int speed;
  
  Serial.println("Type a speed (0-255) into the box above,");
  Serial.println("then click [send] or press [return]");
  Serial.println();  // Print a blank line

  while(true)  // "true" is always true, so this will loop forever.
  {
    // First we check to see if incoming data is available:
  
    while (Serial.available() > 0)
    {
      // If it is, we'll use parseInt() to pull out any numbers:
      
      speed = Serial.parseInt();
  
      // Because analogWrite() only works with numbers from
      // 0 to 255, we'll be sure the input is in that range:
  
      speed = constrain(speed, 0, 255);
      
      // We'll print out a message to let you know that the
      // number was received:
      
      Serial.print("Setting speed to ");
      Serial.println(speed);
  
      // And finally, we'll set the speed of the motor!
      
      analogWrite(motorPin, speed);
    }
  }
}



