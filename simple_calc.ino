#include<LiquidCrystal_I2C.h>
#include<wire.h>
float num1;
float num2;
float answer;

String op;
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  // put your setup code here, to run once:

  lcd.init();
  lcd.backlight();
     Serial.begin(9600);
     
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(0,0);
lcd.print("input 1st num");
while (Serial.available()==0){}
num1 =Serial.parseFloat();

while(Serial.available()>0){
  Serial.read();
}


lcd.clear();
lcd.setCursor(0,0);
lcd.print("input 2nd num");
while (Serial.available()==0){
  
}
num2 =Serial.parseFloat();


while(Serial.available()>0){
  Serial.read();
}


lcd.clear();
lcd.setCursor(0,0);
lcd.print("input operator(+-*/)");


while(Serial.available()==0){
  
}
op = Serial.readString();

op.trim();

if(op=="+"){
  answer =num1+num2;
}

if(op=="-"){
  answer =num1-num2;
}

if(op=="*"){
  answer =num1*num2;
}

if(op=="/"){
  answer =num1/num2;
}

lcd.clear();
lcd.setCursor(0,0);
lcd.print(num1);
lcd.print(op);
lcd.print(num2);
lcd.print("=");
lcd.print(answer);
lcd.setCursor(0,1);
lcd.print("than ku");
delay(5000);
lcd.clear();

}
