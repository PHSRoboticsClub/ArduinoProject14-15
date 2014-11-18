//The following should allow for one motor to spin in reverse.
const int motorPin = 11;
const int dirPin = 13; //dirPin for Left Wheel
void setup()
{

pinMode(motorPin, OUTPUT);
pinMode(dirPin, OUTPUT); 

Serial.begin(9600);
}
void loop()
{

// motorOnThenOff();
// motorOnThenOffWithSpeed();
// motorAcceleration();
serialSpeed();
}
// This function turns the motor on and off 

void motorOnThenOff()
{
int onTime = 3000; // milliseconds to turn the motor on
int offTime = 3000; // milliseconds to turn the motor off
digitalWrite(motorPin, HIGH); // turn the motor on (full speed)
delay(onTime); // delay for onTime milliseconds
digitalWrite(motorPin, LOW); // turn the motor off
delay(offTime); // delay for offTime milliseconds
}
// This function alternates between two speeds.

void motorOnThenOffWithSpeed()
{
int Speed1 = 200; // between 0 (stopped) and 255 (full speed)
int Time1 = 3000; // milliseconds for speed 1
int Speed2 = 50; // between 0 (stopped) and 255 (full speed)
int Time2 = 3000; // milliseconds to turn the motor off
analogWrite(motorPin, Speed1); // turns the motor On
delay(Time1); // delay for onTime milliseconds
analogWrite(motorPin, Speed2); // turns the motor Off
delay(Time2); // delay for offTime milliseconds
}
// This function slowly accelerates the motor to full speed,
// then back down to zero.
void motorAcceleration()
{
int speed;
int delayTime = 20; // milliseconds between each speed step
// accelerate the motor
for(speed = 0; speed <= 255; speed++)
{
analogWrite(motorPin,speed); // set the new speed
delay(delayTime); // delay between speed steps
}
// decelerate the motor
for(speed = 255; speed >= 0; speed--)
{
analogWrite(motorPin,speed); // set the new speed
delay(delayTime); // delay between speed steps
}
}
// This function will let you type a speed into the serial
// monitor window. The valid range is 0 to 255.
void serialSpeed()
{
int speed;
digitalWrite(dirPin, HIGH); // turn the motor on (full speed)
Serial.println("Type a speed (0-255) into the box above,");
Serial.println("then click [send] or press [return]");
Serial.println(); // Print a blank line

while(true) // "true" is always true, so this will loop forever.
{

while (Serial.available() > 0)
{

speed = Serial.parseInt();
// Because analogWrite() only works with numbers from
// 0 to 255, be sure the input is in that range:
speed = constrain(speed, 0, 255);

Serial.print("Setting speed to ");
Serial.println(speed);

analogWrite(motorPin, speed);
}
}
}
