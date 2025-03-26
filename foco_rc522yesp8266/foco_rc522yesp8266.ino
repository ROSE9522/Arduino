
#include <SPI.h>
#include <MFRC522.h> 
#define SS_PIN 4  //--> SDA / SS is connected to pinout D2
#define RST_PIN 5  //--> RST is connected to pinout D1
MFRC522 mfrc522(SS_PIN, RST_PIN);  


//RFID RC522(SDA_DIO, RESET_DIO);

#define USERS 2
byte Usuario1[5] = {{0x11,0xEE,0xD5,0x2E,},{0x5B,0x84,0x57,0x0,0x88}};
                            
//char* names[USERS]={"Alex7 Tutoriales","Invitado"}; 

int LedRojo=10;
int LedVerde=9;
int Rele=16;

void setup()
{ 
  //Wire.begin();

  Serial.begin(9600);
  /* Enable the SPI interface */
  SPI.begin(); 
  /* Initialise the RFID reader */
  //RC522.init();
  mfrc522.PCD_Init();
Serial.println("Approach your reader card...");
Serial.println();

  pinMode(LedRojo, OUTPUT);  //Inicializacion de pines
  pinMode(LedVerde, OUTPUT);
  pinMode(Rele, OUTPUT);
  digitalWrite(LedRojo, LOW);
  digitalWrite(LedVerde, LOW);
  digitalWrite(Rele, LOW);

}

void loop()
{

  if (! mfrc522.PICC_IsNewCardPresent()){
  return;/* Card Exist? */
  }
  if ( ! mfrc522.PICC_ReadCardSerial())  {   // si no puede obtener datos de la tarjeta
    return;           // retorna al loop esperando por otra tarjeta
  }
    Serial.print("UID:");       // muestra texto UID:
    for (byte i = 0; i < mfrc522.uid.size; i++) { // bucle recorre de a un byte por vez el UID
      if (mfrc522.uid.uidByte[i] < 0x10){   // si el byte leido es menor a 0x10
        Serial.print(" 0");       // imprime espacio en blanco y numero cero
        }
        else{           // sino
          Serial.print(" ");        // imprime un espacio en blanco
          }
          Serial.print(mfrc522.uid.uidByte[i], HEX);    // imprime el byte del UID leido en hexadecimal
          LecturaUID[i]=mfrc522.uid.uidByte[i];     // almacena en array el byte del UID leido      
          }
          
          Serial.print("\t");   

    //----------------------------------------------
     if(comparaUID(LecturaUID, Usuario1))
    { 
      Serial.println("Acceso: Autorizado");
      digitalWrite(LedRojo, LOW);
      digitalWrite(LedVerde, HIGH);
      digitalWrite(Rele, HIGH);
      delay(1000);
      digitalWrite(LedRojo, LOW);
      digitalWrite(LedVerde, LOW);
      digitalWrite(Rele, LOW);
    }
    else
    {
      Serial.println("Acceso: Denegado");
      digitalWrite(LedRojo, HIGH);
      digitalWrite(LedVerde, LOW);
      digitalWrite(Rele, LOW);
      delay(1000);
      digitalWrite(LedRojo, LOW);
      digitalWrite(LedVerde, LOW);
      digitalWrite(Rele, LOW);
          
    }
    Serial.println();
    Serial.println();
  }

  delay(20);
  
}

boolean comparaUID(byte lectura[],byte usuario[]) // funcion comparaUID
{
  for (byte i=0; i < mfrc522.uid.size; i++){    // bucle recorre de a un byte por vez el UID
  if(lectura[i] != usuario[i])        // si byte de UID leido es distinto a usuario
    return(false);          // retorna falso
  }
  return(true);           // si los 4 bytes coinciden retorna verdadero
}




bool checkData(byte* arrayA, byte* arrayB, int length) //compare two Array
{
  for (int index = 0; index < length; index++)
  {
    if (arrayA[index] != arrayB[index]) return false;
  }
  return true;
}
