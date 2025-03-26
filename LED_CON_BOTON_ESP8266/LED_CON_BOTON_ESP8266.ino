int pulsador =5;
int led=4;
int estado=0;   //BANDERA
void setup() {
  // put your setup code here, to run once:
   pinMode(pulsador,INPUT);
   pinMode(led,OUTPUT);
   Serial.begin(115200);
   digitalWrite(led,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  
 
  if(digitalRead(pulsador)==1)
  {
    estado=1-estado;
    delay(200);
    }
  if(estado==1)
  {
     digitalWrite(led,0);
     Serial.println("Led encendido");
     
    }
    else{
       digitalWrite(led,1);
       Serial.println("Led apagado");
      }
  }
  
