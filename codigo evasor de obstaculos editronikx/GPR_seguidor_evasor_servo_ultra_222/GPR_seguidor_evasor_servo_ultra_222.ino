#include <Servo.h>
Servo myservo; 

#define ECHO 2       // Pin para recibir el pulso de eco
#define TRIGGER 3     // Pin para enviar el pulso de disparo
//codigo realizado por ing edison viveros
//pasto colombia

int obstamax =14;
int obstamin= 2;
int i=0;

//int sensorizq2 = 5;
//int Stateizq2 = 0;
//int sensorder2 = 4;//
//int Stateder2 = 0;
//int sensorizq1 = 7;
//int Stateizq1 = 0;
//int sensorder1 = 6;
//int Stateder1 = 0;
//int sensorizq = 8;//sensor derecha debajo del carro
//int Stateizq = 0;
//int sensorder = 9;//sensor izquierada debajo del carro
//int Stateder = 0;
int ledPin0 =  16; 
int ledPin1 =  5; 
int ledPin2 =  4; 
int ledPin3 =  0; 
//int powerinfrarojo = 12;//infrarrojo debajo del carro
//int powerinfrarojo1 = 10;
//int powerinfrarojo2 = 11;
//int kk = 0; 
//int dato1=0;
//int dato2=0;
//int dato3=0;

//int estado =0; 
//int tt = 0; 
int duracion;
int distancia;
int CMD;
int CMC;
int CMI;
int CM;

int angizq= 150;
int angdere= 30;
int angcent=90;
int a = 0;
int velocidad =245;

void setup()
{

myservo.attach(13);
  pinMode(ECHO, INPUT);
  pinMode(TRIGGER, OUTPUT);
//pinMode(sensorizq2, INPUT);
//pinMode(sensorder2, INPUT);
//pinMode(sensorizq1, INPUT);
//pinMode(sensorder1, INPUT);
//pinMode(sensorizq, INPUT);//infrarrojo debajo del carro
//pinMode(sensorder, INPUT);// sensor debajo del carro
pinMode(ledPin0, OUTPUT);
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
//pinMode(powerinfrarojo, OUTPUT);//infrarrojo debajo del carro
//pinMode(powerinfrarojo1, OUTPUT);
//pinMode(powerinfrarojo2, OUTPUT);

// digitalWrite(powerinfrarojo,HIGH);//PRENDO INFRARROJO
// digitalWrite(powerinfrarojo1,LOW);
 //digitalWrite(powerinfrarojo2,LOW);
myservo.write(angcent);
delay(3000);
motor_stop();
}

void loop() 
{

        leer_obstaculo();// lee distancia y almacena obstaculo
       
}

int DISTACM()//funcion que regresa un valor entero de la distancia para su comparacion
{
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW); 
  duracion = pulseIn(ECHO, HIGH); //Medición del ancho de pulso recibido en el pin Echo
  distancia =  (float (duracion))/53;
  delay(5);
  
  return distancia;
  
  
}
////////////////////////////////////////////////
void motor_stop()
{
  analogWrite(ledPin0,0);//motor parado
  analogWrite(ledPin1,0);
  analogWrite(ledPin2,0);
  analogWrite(ledPin3,0);
}
/////////////////////////////////////////////////
void motor_atras()
{
   analogWrite(ledPin0,0);//atras
   analogWrite(ledPin1,velocidad);
   analogWrite(ledPin2,0);
   analogWrite(ledPin3,velocidad);
}
////////////////////////////////////////////////
void motor_adelante()
{
   analogWrite(ledPin0,velocidad);//adelante
   analogWrite(ledPin1,0);
   analogWrite(ledPin2,velocidad);
   analogWrite(ledPin3,0);
}
//////////////////////////////////
void motor_izquierda()//gerena un pequeño tiempo girando debe parar
{
        analogWrite(ledPin0,0);
        analogWrite(ledPin1,velocidad);
        analogWrite(ledPin2,velocidad);
        analogWrite(ledPin3,0);
   
  
}
//////////////////////////////////
void motor_derecha()//gerena un pequeño tiempo girando debe parar
{
 
        analogWrite(ledPin0,velocidad);
        analogWrite(ledPin1,0);
        analogWrite(ledPin2,0);
        analogWrite(ledPin3,velocidad);
    
}
//////////////////////////////////
void leer_obstaculo()
{
 //// leera 2 POSICIONES DERECHA E IZQUIERDA
 /////poscicion uno
 // motor_stop();//parar los motores
 CM = DISTACM();//lee la funcion de leer los centimetros
 
if(CM <= obstamax && CM >=obstamin )//verifica si hay obstaculos menos a 14 cm
        {
        /////poscicion dos
         motor_stop();
         myservo.write(angdere);//servomotor derecha
         delay(1000);
         CMD = DISTACM();//lee la funcion de leer los centimetros
         myservo.write(angizq);//servomotor derecha
         delay(1000);
         CMI = DISTACM();//lee la funcion de leer los centimetros
         
          if(CMI > CMD)//HAY OBSTA EN DERECHA
          {
           myservo.write(angcent);//servomotor en 180 grados izquierda
           delay(1000);
           motor_izquierda();
           delay(500);
           
          }
          if(CMI < CMD)//OBSTA IZQ
          {
           myservo.write(angcent);//servomotor en 180 grados izquierda
           delay(1000);
           motor_derecha();
           delay(500);
          }
        }
//////////////////////////////////////

  else 
   {
      // myservo.write(angcent);//servomotor en 180 grados izquierda
       motor_adelante();

   }
  }
 
