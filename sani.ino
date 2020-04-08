#include <Ultrasonic.h>
#include <Servo.h>

Servo myservo1;
Servo myservo2;
Ultrasonic ultrasonic(2, 3);

int pos = 0;
int distance;

void setup() {
  myservo1.attach(9);  
  myservo2.attach(5);
  myservo1.write(30);            
  myservo2.write(30);
  Serial.begin(9600);
}

void loop() {
  distance = ultrasonic.read();
  Serial.println(distance);
  if(distance<=20)
  {
    Serial.println("start");
    for (pos = 30; pos <= 180; pos += 3)
    {
    myservo1.write(pos);
    myservo2.write(pos);
    delay(15); 
    }
   for (pos = 180; pos >= 30; pos -= 3)
   {
     myservo1.write(pos); 
     myservo2.write(pos);
     delay(15);  
  }
  }
  delay(10); 
}
