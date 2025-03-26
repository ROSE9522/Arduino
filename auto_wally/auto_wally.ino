/*         
Proyecto: Carro Evasor de Obstaculos
Autor: Daniel Lopez
Whatsapp: 77401376
*/

#include <Servo.h>

Servo servo1;


#include <NewPing.h>

#define TRIGGER_PIN  3     // Pin Trigger Ultrasonido
#define ECHO_PIN     2     // Pin Echo Ultrasonido
#define MAX_DISTANCE 400    // Distancia maxima (limite 400-500cm)

int distancia=0;            // Variable donde se guarda el valor de la distancia
const int motor1A=6;       // motor1A en el pin 11
const int motor2A=7;       // motor2A en el pin 10
const int motor1B=4;       // motor1B en el pin 9
const int motor2B=5 ;       // motor2B en el pin 8
boolean giro=false;

NewPing medirDistancia(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // Funcion de la libreria para poder medir la distancia

void setup() {
  
  Serial.begin(9600);        // Inicializa la comunicacion serial
  pinMode(motor1A,OUTPUT);   // Inicializa el pin motor1A como salida
  pinMode(motor2A,OUTPUT);   // Inicializa el pin motor2A como salida
  pinMode(motor1B,OUTPUT);   // Inicializa el pin motor1B como salida
  pinMode(motor2B,OUTPUT);   // Inicializa el pin motor2B como salida
  
}
void loop() {
  
  delay(50);                              // Retardo de 50ms para poder tomar datos (20 pings/sec)
  distancia = medirDistancia.ping_cm();   // Guardar el valor de la distancia
  Serial.print("Distancia: ");
  Serial.print(distancia);                // Imprimir la distancia
  Serial.println("cm");

  if(distancia <= 10){          // En caso de que encuentre un obstaculo

    if(giro==false){            // Realizara un giro a la derecha

      // Detener motores
      digitalWrite(motor1A,LOW);
      digitalWrite(motor2A,LOW);
      digitalWrite(motor1B,LOW);
      digitalWrite(motor2B,LOW);
      delay(1000);

      // Movimiento Retroceder
      digitalWrite(motor1A,LOW);
      digitalWrite(motor2A,HIGH);
      digitalWrite(motor1B,LOW);
      digitalWrite(motor2B,HIGH);
      delay(1000); 
      
      // Movimiento Derecha
      digitalWrite(motor1A,LOW);
      digitalWrite(motor2A,HIGH);
      digitalWrite(motor1B,HIGH);
      digitalWrite(motor2B,LOW);
      delay(1000);
      
      giro=true;
    }
    
    if(giro==true){            // Realizara un giro a la izquierda
      
      // Detener motores
      digitalWrite(motor1A,LOW);
      digitalWrite(motor2A,LOW);
      digitalWrite(motor1B,LOW);
      digitalWrite(motor2B,LOW);
      delay(1000);

      // Movimiento Retroceder
      digitalWrite(motor1A,LOW);
      digitalWrite(motor2A,HIGH);
      digitalWrite(motor1B,LOW);
      digitalWrite(motor2B,HIGH);
      delay(1000); 
      
      // Movimiento Izquierda
      digitalWrite(motor1A,HIGH);
      digitalWrite(motor2A,LOW);
      digitalWrite(motor1B,LOW);
      digitalWrite(motor2B,HIGH);
      delay(1000);
      
      giro=false;   
    }  
  }
  
  if(distancia > 20){       // Si no hay objeto en el camino, continua su camino
     // Movimiento Adelante
     digitalWrite(motor1A,HIGH);
     digitalWrite(motor2A,LOW);
     digitalWrite(motor1B,HIGH);
     digitalWrite(motor2B,LOW);     
  }
} //Fin Loop
