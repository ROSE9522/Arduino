
//¿Te gustaria aprender a aramar tu propio robot? 
//Ingresa ya a https://www.cursosmatlab.com/ y accede a los mejores cursos de Robótica y Programación.
// Creamos.la©Corporation

#include <NewPing.h>// Descarga la libreria "NewPing" arriba en la sección "Programa/Incluir Librería/Gestionar Libreria" si aun no la tienes.
#include <Servo.h> 

const int Trigger = 3; 
const int Echo = 2;
const int MAX_DISTANCE 200;
NewPing sonar(Trigger, Echo, MAX_DISTANCE); 
Servo myservo;   

boolean goesForward=false;
int distance = 100;
int speedSet = 0;

const int motorPin1  = 14;  
const int motorPin2  = 12;  
//Motor B
const int motorPin3  = 4; 
const int motorPin4  = 5;  

void setup() {

  myservo.attach(9);  
  myservo.write(115); 
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop() {
 int distanceR = 0;
 int distanceL =  0;
 delay(40);
 
 if(distance<=20)
 {
  moveStop();
  delay(100);
  moveBackward();
  delay(300);
  moveStop();
  delay(200);
  distanceR = lookRight();
  delay(200);
  distanceL = lookLeft();
  delay(200);

  if(distanceR>=distanceL)
  {
    turnRight();
    moveStop();
  }else
  {
    turnLeft();
    moveStop();
  }
 }else
 {
  moveForward();
 }
 distance = readPing();
}

int lookRight()
{
    myservo.write(50); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(115); 
    return distance;
}

int lookLeft()
{
    myservo.write(170); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(115); 
    return distance;
    delay(100);
}

int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}

void moveStop() {
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 0);
  } 
  
void moveForward() {


    analogWrite(motorPin1, 180);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 180);
    analogWrite(motorPin4, 0);  
  
}

void moveBackward() {
    
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 180);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 180);   
  
}  

void turnRight() {
    analogWrite(motorPin1, 180);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 180);    
    delay(2500);
 moveForward();      
  
} 
 
void turnLeft() {
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 180);   
    analogWrite(motorPin3, 180);
    analogWrite(motorPin4, 0);     
    delay(2500);
  moveForward();
}  
