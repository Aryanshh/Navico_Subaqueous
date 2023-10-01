  #include<Servo.h>
#include <Arduino.h>

#define trigPin 8                 //ultra
#define echoPin 9                 
#define ON 1
#define OFF 0
#define ledPin 6
#define sensorPin 


long duration;
int distance ;
int vibration_Sensor = A0;        //Vibration sensor 
int LED = 13;
int readSensor ();

int present_condition = 0;
int previous_condition = 0;

Servo myservo;

int calculateDistance()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  return distance;
}

void setup()
{
  pinMode(trigPin , OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(11);
  Serial.begin(9600);

  pinMode(vibration_Sensor, INPUT);
            pinMode(LED, OUTPUT); 

  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop()
{
 int i ;
 for (i=15; i<=165; i++)
 {
  myservo.write(i);
  delay(15);
  calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
 }
 for(i=165; i>=15; i--)
 {
  myservo.write(i);
  delay(15);
  calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  
 }

{
 digitalWrite(LED, ON);
            delay(250);
            digitalWrite(LED, OFF);
            delay(250);
            digitalWrite(LED, ON);
            delay(250);
            digitalWrite(LED, OFF);
            delay(250);



  readSensor();{
  unsigned int sensorValue = analogRead(sensorPin);  
  unsigned int outputValue = map(sensorValue, 0, 1023, 0, 255); 
  if (outputValue > 65)
    analogWrite(ledPin, outputValue); 
  else
    digitalWrite(ledPin, LOW);
  return outputValue;

  Serial.print("Analog output: ");
  Serial.println(readSensor());
  delay(500);

  
}

 
}

}
