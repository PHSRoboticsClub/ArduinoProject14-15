#define trigPin 13
#define echoPin 12
 
void setup() {
   Serial.begin (9600);
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   
 }
 
void loop() {
   long duration, distance; // define as long int
   //digitalWrite(trigPin, LOW);  // set trigger low
   //delayMicroseconds(2); // shrt delay .002 sec
   digitalWrite(trigPin, HIGH); //set trigger hi
 
   delayMicroseconds(10); // short delay
   digitalWrite(trigPin, LOW); //set trigger low
   duration = pulseIn(echoPin, HIGH); //read echo pin
   distance = (duration/2) / 29.1; // convert to cm
   if (distance < 4) {  // This is where the decisions happens
     
 }
   else {
     
   }
   if (distance >= 200 || distance <= 0){
     Serial.println("Out of range");
   }
   else {
     Serial.print(distance);
     Serial.println(" cm");
   }
   delay(500);
}
