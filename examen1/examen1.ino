int led1=2;
int led2=0;
int led3=4;
void setup() {
// put your setup code here, to run once:
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
}
void loop() {
// put your main code here, to run repeatedly:
digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(led3,LOW);
delay(600);
// MENOR
digitalWrite(led1,HIGH);
digitalWrite(led2,LOW);
digitalWrite(led3,LOW);
delay(600);
digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(led3,LOW);
delay(600);
//IGUAL
digitalWrite(led1,HIGH);
digitalWrite(led2,HIGH);

delay(600);
digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(led3,LOW);
delay(600);
//MAYOR
digitalWrite(led1,HIGH);
digitalWrite(led2,HIGH);
digitalWrite(led3,HIGH);

delay(600);

}
