   //EVASOR DE OBSTACULOS
#include <Servo.h> 
Servo myservo;  
const int Trigger = 3; 
const int Echo = 2;
void setup() {  
  pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT); 
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT); 
  myservo.attach(9); 
  pinMode(Trigger, OUTPUT); //pin como salida  
  pinMode(Echo, INPUT);  //pin como entrada 
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0 
  Serial.begin(9600);  
}
 
void loop() {   
  long t; //tiempo que demora en llegar el eco
  long d; //distancia en centimetros 
  long dizq;// distancia izquierda  
  long dder;// distancia derecha 
 
  digitalWrite(Trigger, HIGH);  
  delayMicroseconds(10);          //Enviamos un pulso de 10us  
  digitalWrite(Trigger, LOW); 
 
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso 
  d = t / 59;           //escalamos el tiempo a una distancia en cm 
 
  Serial.print("Distancia: ");  
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");  
  Serial.println(); 
  delay(50);          //Hacemos una pausa de 50ms   
  if (d <= 15) {    
    atras();  
    delay(300); 
     detener();   
     delay(1000); 
 
    myservo.write(175);  
    delay(500); 
    digitalWrite(Trigger, HIGH); 
    delayMicroseconds(10);          //Enviamos un pulso de 10us  
    digitalWrite(Trigger, LOW); 
 
    t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso 
    dizq = t / 59;           //obtenemos distancia izquierda 
 
    myservo.write(10);   
    delay(500);   
    digitalWrite(Trigger, HIGH); 
    delayMicroseconds(10);          //Enviamos un pulso de 10us   
    digitalWrite(Trigger, LOW); 
 
    t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso   
    dder = t / 59;           //obtenemos distancia derecha   
    myservo.write(90);    
    detener();    
    delay(500); 
    if (dizq > dder)   
    {  
      izquierda();     
      delay(500);   
      }
      else 
      {   
        derecha(); 
        delay(500); 
        } 
 
  }   
  adelante(); 
  }
  void adelante() {  
    digitalWrite(6, HIGH); 
    digitalWrite(7, LOW); 
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    } 
    void izquierda() {  
      digitalWrite(6, LOW);  
      digitalWrite(7, HIGH); 
      digitalWrite(4, HIGH);  
      digitalWrite(5, LOW); 
      } 
      void derecha() {  
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);  
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        }
        void atras() {   
          digitalWrite(6, LOW);  
          digitalWrite(7, HIGH);  
          digitalWrite(4, LOW);
          digitalWrite(5, HIGH); 
          }
          void detener() {   
            digitalWrite(6, LOW);
            digitalWrite(7, LOW);   
            digitalWrite(4, LOW); 
            digitalWrite(5, LOW); 
            }
