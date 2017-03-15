#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensorPin = A0; // select the input pin for ldr
int sensorValue = 0;
int sv=0;
int flag=0;
int val=0;    //read from 
int pushbutton1=7; 
int pushbutton2=8 ;
int ledpin1=13;        
int ledpin2=10;    
unsigned long t_time=0,s_time,e_time,r_time;
unsigned long  interval=0;
int rounds=0,Random; 
unsigned long TimeinEach(int pushbutton,int led)
{//Serial.print("working");
  s_time=millis();
flag=0;
int n=0;
val=digitalRead(pushbutton);
while(val!=LOW)
{/*
if(n==0){*/
//lcd.print("go fast!");
/*n++;}
 else{
 lcd.clear();
lcd.print(rounds);}*/
  val=digitalRead(pushbutton);}
  
if(val==LOW)
{digitalWrite(led,LOW);
flag=1;
sv=analogRead(sensorPin);
}
while(sv>1000&&flag==1)
   {
   digitalWrite(led,LOW);
   sv=analogRead(sensorPin);
    }
e_time=millis();
//}
 r_time=e_time-s_time; 
 lcd.print(r_time);
 Serial.print(r_time);
 delay(1000);
 lcd.clear();
return r_time;}
//else{ return 0;}


void setup() {
pinMode(pushbutton1,INPUT);
pinMode(pushbutton2,INPUT);
pinMode(ledpin1,OUTPUT);                       //anolog inputs are to be defined not ldr one
pinMode(ledpin2,OUTPUT);
lcd.begin(16,2);
randomSeed(analogRead(A0));
Serial.begin(115200); //sets serial port for communication
}
void loop() {
    lcd.setCursor(0,0);
  lcd.print("let's begin!!!");
 Serial.print("let's begin!!!");
  
  delay(2000);
  lcd.clear();
while(rounds<10)
     {
Random=random(1,3);
Serial.print(Random);
//









lcd.print(Random);
if(Random==1)
{
  digitalWrite(ledpin1,HIGH);
 // Serial.print("glow");
//s_time=millis();
     lcd.print(rounds+1);
   Serial.print(rounds+1);
  t_time+=TimeinEach(pushbutton1,ledpin1);

//delay(500);
//lcd.print(r_time);
   //lcd.print(e_time-s_time);
delay(1000);
lcd.clear();
rounds++;
}
else 
{    digitalWrite(ledpin2,HIGH); 
//s_time=millis();
lcd.print(rounds+1);
   Serial.print(rounds+1);
t_time+=TimeinEach(pushbutton2,ledpin2);
//delay(500);
//lcd.print(r_time);
//lcd.print(e_time-s_time);
delay(1000);
lcd.clear();
rounds++;

}
     }
lcd.print("You did it!!!");
delay(1000);
lcd.clear();
lcd.print("your average");
delay(1000);
lcd.clear();
lcd.print(t_time/10.0);
Serial.print(t_time/10.0);
delay(1000);
lcd.clear();
delay(1000);
lcd.print("ALL THE BEST");
delay(2000);
     }

