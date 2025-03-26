#include <Servo.h>
Servo miservo;
int pos;
int puenteHazul = 11;
int puenteHverde = 10;
int amarillo = 6;
int blanco = 7;
int azul = 4;
int rojo = 5;
unsigned long pulso;
float distancia;
float derecha;
float izquierda;
int trig = 3;
int echo = 2;
int duracion = 0;
void setup() {
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);
  miservo.attach(9);
  Serial.begin(9600);
  pinMode(puenteHazul, OUTPUT);
  pinMode(puenteHverde, OUTPUT);
  pinMode (amarillo , OUTPUT);
  pinMode (blanco, OUTPUT);
  pinMode (azul, OUTPUT);
  pinMode (rojo, OUTPUT);
  digitalWrite(puenteHazul, LOW);
  digitalWrite(puenteHverde, LOW);
  // put your setup code here, to run once:

}

void loop() 
{

  digitalWrite(trig, HIGH);
  delayMicroseconds(100);
  digitalWrite(trig, LOW);

  duracion = pulseIn( echo,HIGH);
  distancia = (duracion/2)/28.5;
  Serial.println(distancia);
  delay(100);

  
if (distancia < 35)

  {
  digitalWrite(amarillo, LOW);
  digitalWrite(blanco, LOW);
  digitalWrite(puenteHazul, LOW);
  digitalWrite(puenteHverde, LOW);
  digitalWrite(azul, LOW);
  digitalWrite(rojo,LOW );
  
  miservo.write(pos = 0);  
  digitalWrite(trig, HIGH);
  delayMicroseconds(100);
  digitalWrite(trig, LOW);
  duracion =pulseIn(echo,HIGH);
  derecha = (duracion/2)/28.5;
  delay(1000 + derecha);
  Serial.print("derecha =");
  Serial.print(derecha);
    
  miservo.write(pos = 180);
  digitalWrite(trig, HIGH);
  delayMicroseconds(100);
  digitalWrite(trig, LOW);
  duracion =pulseIn(echo,HIGH);
  izquierda = (duracion/2)/28.5;
  delay(1000 + izquierda);
  Serial.print(", izquierda =");
  Serial.println(izquierda);
  
  

  miservo.write(pos = 90);  
  digitalWrite(trig, HIGH);
  delayMicroseconds(100);
  digitalWrite(trig, LOW);
  duracion =pulseIn(echo,HIGH);
  distancia = (duracion/2)/28.5;
  delay(1000); 
  
  digitalWrite(amarillo, HIGH);
  digitalWrite(blanco, LOW);
  digitalWrite(puenteHazul, HIGH);
  digitalWrite(puenteHverde, HIGH);
  digitalWrite(azul, HIGH);
  digitalWrite(rojo,LOW );
  delay(400);

if ( derecha > izquierda)
{
  digitalWrite(amarillo, HIGH);
  digitalWrite(blanco, LOW);
  digitalWrite(puenteHazul, HIGH);
  digitalWrite(puenteHverde,HIGH);
  digitalWrite(azul, LOW);
  digitalWrite(rojo, HIGH);
  delay(400); 
  }
else 
{ 
  digitalWrite(amarillo, LOW);
  digitalWrite(blanco, HIGH);
  digitalWrite(puenteHazul, HIGH);
  digitalWrite(puenteHverde,HIGH);
  digitalWrite(azul, HIGH);
  digitalWrite(rojo, LOW);
  delay(400); 
  }   
  }
else 
  {
  miservo.write(pos = 90);  
  digitalWrite(trig, HIGH);
  delayMicroseconds(100);
  digitalWrite(trig, LOW);
  duracion =pulseIn(echo,HIGH);
  distancia = (duracion/2)/28.5;  
  digitalWrite(amarillo, LOW);
  digitalWrite(blanco, HIGH);
  digitalWrite(puenteHazul, HIGH);
  digitalWrite(puenteHverde,HIGH);
  digitalWrite(azul, LOW);
  digitalWrite(rojo,HIGH);
  delay(1000); 
  }
  
  
  
  // put your main code here, to run repeatedly:

}
