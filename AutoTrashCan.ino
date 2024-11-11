
#include <Servo.h>   //servo library
Servo servo;     
int trigPin = 8;    
int echoPin = 9;   
int servoPin = 6;
int buzzer = 10;
long duration, dist, average;   
long aver[3];   //array for average


void setup() {       
    Serial.begin(9600);
    servo.attach(servoPin);  
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT);  
    pinMode(buzzer, OUTPUT); 
    servo.write(0);         //close cap on power on
    delay(100);
    servo.detach(); 
} 

void measure() {  
 digitalWrite(trigPin, LOW);
 delayMicroseconds(5);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(15);
 digitalWrite(trigPin, LOW);
 pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
dist = (duration/2) / 29.1;    //obtain distance
}
void loop() { 
  for (int i=0;i<=2;i++) {   //average distance
    measure();               
   aver[i]=dist;            
    delay(10);              //delay between measurements
  }
 dist=(aver[0]+aver[1]+aver[2])/3;    

if ( dist < 50 ) {
//Change distance as per your need
 servo.attach(servoPin);
  delay(1);
 servo.write(0);  
 delay(3000);       
 servo.write(80);    
 delay(1000);
 servo.detach(); 
 digitalWrite(buzzer, HIGH);
 delay(1000);     
}else{
  digitalWrite(buzzer, LOW);
  delay(1000);
}
Serial.println(dist);
}

