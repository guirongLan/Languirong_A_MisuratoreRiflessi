int button = 10 ;
int led = 12 ;
int buzzer = 11;
int rosso = 9 ;
int verde = 8 ;

int tempo = 0;
int tempodue = 0;
int ms = 0;
int msdue = 0;
//include lcd
#include <LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
pinMode(button,INPUT);
pinMode(led,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(verde,OUTPUT);
pinMode(rosso,OUTPUT);
lcd.begin(16,2);
}
void programma()
{
    lcd.clear();
    lcd.print("sei pronto?");
    lcd.setCursor(0,1);
    lcd.print("clica bottone");
    while(digitalRead(button)==LOW)
    {}
    lcd.clear();
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
      lcd.print("Led:");
      lcd.print(ms);
      lcd.print("ms");
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
      lcd.setCursor(0,1);
      lcd.print("Buzzer:");
      lcd.print(msdue);
      lcd.print("ms");
  }
  delay(2000);
  if(ms+msdue<2000)
  {
    digitalWrite(verde,HIGH);
    lcd.clear();
    lcd.print("sei passato");
   }
   else
   {
    digitalWrite(rosso,HIGH);
    lcd.clear();
    lcd.print("non sei passato");
    }
    delay(5000);
    digitalWrite(verde,LOW);
    digitalWrite(rosso,LOW);
}
void loop() {
  // put your main code here, to run repeatedly:
randomSeed(analogRead(0));//dichiaro random
tempo = random(2000,5000);//numero di random da 300 a 800
tempodue = random(2000,5000);//numero di random da 300 a 800
programma();
}
