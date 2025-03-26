int led= 13;
int ojo = 8;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(led,OUTPUT);
pinMode(ojo,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead(ojo)== HIGH)
{
  digitalWrite(led,1);
  Serial.print(digital(ojo));
  Serial.println("LED ENCENDIDO");
  delay(1000);
  }
  else
  
  {
  digitalWrite(led,0);
  Serial.println("LED APAGADO");
  delay(1000);
    }
}
