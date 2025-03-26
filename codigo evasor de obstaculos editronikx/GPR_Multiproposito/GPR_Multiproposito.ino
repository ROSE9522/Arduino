//#include <SoftwareSerial.h>
int sensorizq2 = 5;
int Stateizq2 = 0;
int sensorder2 = 4;
int Stateder2 = 0;
int sensorizq1 = 7;
int Stateizq1 = 0;
int sensorder1 = 6;
int Stateder1 = 0;
int sensorizq = 8;
int Stateizq = 0;
int sensorder = 9;
int Stateder = 0;
int ledPin0 =  A0; 
int ledPin1 =  A1; 
int ledPin2 =  A2; 
int ledPin3 =  A3; 
int powerinfrarojo = 12;
int powerinfrarojo1 = 10;
int powerinfrarojo2 = 11;
int kk = 0; 

int estado = 'g'; 
int tt = 0; 

int a = 0;
int velocidad = 0;

void setup() {

 Serial.begin(9600);
pinMode(sensorizq2, INPUT);
pinMode(sensorder2, INPUT);
pinMode(sensorizq1, INPUT);
pinMode(sensorder1, INPUT);
pinMode(sensorizq, INPUT);
pinMode(sensorder, INPUT);
pinMode(ledPin0, OUTPUT);
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(powerinfrarojo, OUTPUT);
pinMode(powerinfrarojo1, OUTPUT);
pinMode(powerinfrarojo2, OUTPUT);

 digitalWrite(powerinfrarojo,LOW);
 digitalWrite(powerinfrarojo1,LOW);
 digitalWrite(powerinfrarojo2,LOW);

velocidad = 150;
 
}

void loop() {

if(Serial.available()>0){    
      estado = Serial.read();  
  }
   if(estado == 'a' || estado == 'b' || estado == 'c' ){  
     tt = 0;        
  }
  if(estado == 'd'){  
     tt = 1;        
  }
   if(tt == 1){  
    remoto();        
  }
   if(estado=='a'){           
   linea();  
  }
  if(estado=='b'){           
   luz(); 
  }
  if(estado=='c'){          
   ebasor(); 
  }
  
}


void  linea() {
 kk = 0;
 digitalWrite(powerinfrarojo,HIGH);
 digitalWrite(powerinfrarojo1,LOW);
 digitalWrite(powerinfrarojo2,LOW);
 Stateizq = digitalRead(sensorizq);
 Stateder = digitalRead(sensorder);

if(Stateizq == 1 && Stateder == 1)
{
analogWrite(ledPin0,0);
analogWrite(ledPin1,velocidad);
analogWrite(ledPin2,0);
analogWrite(ledPin3,velocidad);
}
else if (a == 1)
{
analogWrite(ledPin0,0);
analogWrite(ledPin1,velocidad);
analogWrite(ledPin2,velocidad);
analogWrite(ledPin3,0);
}
else if (a == 2)
{
analogWrite(ledPin0,velocidad);
analogWrite(ledPin1,0);
analogWrite(ledPin2,0);
analogWrite(ledPin3,velocidad);
}
if(Stateizq == 0 && Stateder == 1)
{
analogWrite(ledPin0,0);
analogWrite(ledPin1,velocidad);
analogWrite(ledPin2,velocidad);
analogWrite(ledPin3,0);
 a = 1;
}
if(Stateizq == 1 && Stateder == 0)
{
analogWrite(ledPin0,velocidad);
analogWrite(ledPin1,0);
analogWrite(ledPin2,0);
analogWrite(ledPin3,velocidad);

 a = 2;
}

}

void  luz() {
 kk = 0; 
 digitalWrite(powerinfrarojo,LOW);
 digitalWrite(powerinfrarojo1,HIGH);
 digitalWrite(powerinfrarojo2,LOW);

 Stateizq1 = digitalRead(sensorizq1);
 Stateder1 = digitalRead(sensorder1);

if(Stateizq1 == 1  && Stateder1 == 1)
{
analogWrite(ledPin0,0);
analogWrite(ledPin1,0);
analogWrite(ledPin2,0);
analogWrite(ledPin3,0);
}
if(Stateizq1 == 0  && Stateder1 == 0)
{
analogWrite(ledPin0,0);
analogWrite(ledPin1,velocidad);
analogWrite(ledPin2,0);
analogWrite(ledPin3,velocidad);
}
if(Stateizq1 == 0 && Stateder1 == 1)
{
analogWrite(ledPin0,velocidad);
analogWrite(ledPin1,0);
analogWrite(ledPin2,0);
analogWrite(ledPin3,velocidad);
 a = 1;
}
if(Stateizq1 == 1 && Stateder1 == 0)
{
analogWrite(ledPin0,0);
analogWrite(ledPin1,velocidad);
analogWrite(ledPin2,velocidad);
analogWrite(ledPin3,0);

 a = 2;
}
}

void  ebasor() {
 kk = 0;
 digitalWrite(powerinfrarojo,LOW);
 digitalWrite(powerinfrarojo1,LOW);
 digitalWrite(powerinfrarojo2,HIGH);
 
 Stateizq2 = digitalRead(sensorizq2);
 Stateder2 = digitalRead(sensorder2);
if(Stateizq2 == 1 && Stateder2 == 1)
{
analogWrite(ledPin0,0);
analogWrite(ledPin1,velocidad);
analogWrite(ledPin2,0);
analogWrite(ledPin3,velocidad); 
}
if(Stateizq2 == 0 && Stateder2 == 1)
{
analogWrite(ledPin0,0);
analogWrite(ledPin1,0);
analogWrite(ledPin2,velocidad);
analogWrite(ledPin3,0);
delay(700);
}
if(Stateizq2 == 1 && Stateder2 == 0)
{
analogWrite(ledPin0,velocidad);
analogWrite(ledPin1,0);
analogWrite(ledPin2,0);
analogWrite(ledPin3,0);
delay(700);
}
}

void  remoto() {

 digitalWrite(powerinfrarojo,LOW);
 digitalWrite(powerinfrarojo1,LOW);
 digitalWrite(powerinfrarojo2,LOW);

  if(kk == 0){
analogWrite(ledPin0,0);
analogWrite(ledPin1,0);
analogWrite(ledPin2,0);
analogWrite(ledPin3,0);
  }
  kk = 1;
  
  if(estado == '1'){
analogWrite(ledPin0,0);
analogWrite(ledPin1,velocidad);
analogWrite(ledPin2,0);
analogWrite(ledPin3,velocidad); 
  }   
   if(estado == '2'){
analogWrite(ledPin0,0);
analogWrite(ledPin1,velocidad);
analogWrite(ledPin2,velocidad);
analogWrite(ledPin3,0);
  } 
   if(estado == '3'){
analogWrite(ledPin0,0);
analogWrite(ledPin1,0);
analogWrite(ledPin2,0);
analogWrite(ledPin3,0);
  } 
   if(estado == '4'){
analogWrite(ledPin0,velocidad);
analogWrite(ledPin1,0);
analogWrite(ledPin2,0);
analogWrite(ledPin3,velocidad);
  } 
   if(estado == '5'){
analogWrite(ledPin0,velocidad);
analogWrite(ledPin1,0);
analogWrite(ledPin2,velocidad);
analogWrite(ledPin3,0); 
  } 
  
}

