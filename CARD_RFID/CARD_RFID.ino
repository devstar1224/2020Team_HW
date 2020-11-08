#include <SPI.h>
#include <MFRC522.h>
#define RST_PIN   9
#define SS_PIN    8

MFRC522 rc522(SS_PIN, RST_PIN);

int sg90 = 6;
int i=0;

void setup(){
  Serial.begin(9600);
  SPI.begin();
  rc522.PCD_Init();                      
}

void loop(){   

  if ( !rc522.PICC_IsNewCardPresent() || !rc522.PICC_ReadCardSerial() ) { 
    delay(500);
    return;
  }
  
  int result = 0;
  for (byte i = 0; i < 4; i++) {
    result += rc522.uid.uidByte[i];
  }
  Serial.println(result);
  delay(600);
}
