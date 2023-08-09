#include <SoftwareSerial.h>
#define analog A0
#define power 7
int buzz=11;

SoftwareSerial mySerial(9, 10);

void setup()
{
  mySerial.begin(9600);   
  Serial.begin(9600);    
  delay(100);
 pinMode(power,OUTPUT);
 pinMode(buzz,OUTPUT);
}


void sendSMS(){
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1 second
  mySerial.println("AT+CMGS=\"+917904848964\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Water level maximum.Cutoff water supply.");// The SMS text you want to send
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module
  delay(1000);
}

void loop(){
  digitalWrite(power,HIGH);
  delay(100);
  int value=analogRead(analog);
  digitalWrite(power,LOW);
  Serial.println(value);
  if(value>=400){
    sendSMS();
    delay(100);
  }
  if(value<=350 && value >=150){

    tone(buzz,500);
    delay(5000);
    noTone(buzz);
    mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1 second
  mySerial.println("AT+CMGS=\"+917904848964\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Water level medium");// The SMS text you want to send
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module
  delay(1000);
    
  }

  if(value<=150){
    mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1 second
  mySerial.println("AT+CMGS=\"+917904848964\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Water level low");// The SMS text you want to send
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module
  delay(1000);
  }
  
}
