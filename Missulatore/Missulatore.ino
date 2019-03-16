int button = 7 ;
int led = 6 ;
int buzzer = 8;

int tempo = 0;
int tempodue = 0;
int ms = 0;
int msdue = 0;
//include lcd
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  // put your setup code here, to run once:
pinMode(button,INPUT);
pinMode(led,OUTPUT);
pinMode(buzzer,OUTPUT);

Serial.begin(9600);//dico che c'e serial

randomSeed(analogRead(0));//dichiaro random
tempo = random(2000,5000);//numero di random da 300 a 800
tempodue = random(2000,5000);//numero di random da 300 a 800

Serial.println("questo è il tempo Random:");
Serial.println(tempo);
Serial.println(tempodue);
programma();
}
void programma()
{

    delay(tempo);
    digitalWrite(led,HIGH);
    while(digitalRead(button)==LOW)
    {
      ms++;
      delay(1);//corisponde 1 ms
    }
    if(digitalRead(button)==HIGH)
    {
      digitalWrite(led,LOW);
      Serial.println("riflessi");
      Serial.println(ms);
    }
  
    delay(tempodue);
    digitalWrite(buzzer,HIGH);
    while(digitalRead(button)==LOW)
    {
      msdue++;
      delay(1);//corisponde 1 ms
    }
    if(digitalRead(button)==HIGH)
    { 
      digitalWrite(buzzer,LOW);
      Serial.println("riflessi");
      Serial.println(msdue);

  }
}
void loop() {
  // put your main code here, to run repeatedly:
}
