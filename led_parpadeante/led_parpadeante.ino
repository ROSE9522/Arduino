
int T = 1000; //En dónde dice 1000 poner el tiempo entre parpadeos deseados 

void setup() {
  
  pinMode(13, OUTPUT);
}


void loop() {
  digitalWrite(13, HIGH);   
  delay(T);             
  digitalWrite(13, LOW);  
  delay(T);              
}
