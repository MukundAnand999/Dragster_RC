#include<Servo.h>
Servo myservo;
int speed_mode=0;
void setup(){
Serial.begin(9600);
pinMode(5,OUTPUT);
pinMode(3,OUTPUT);
myservo.attach(6);
myservo.write(90);
}
void bot_movement(int x){

  switch(x)
{
  case'F':   if(speed_mode==10)
  {
    // analogWrite(5,255); analogWrite(6,255);
          digitalWrite(5,HIGH);
          digitalWrite(3,LOW);
  }
          if(speed_mode==0)
                    {
                      analogWrite(5,0); analogWrite(3,0);
                    }
                     if(speed_mode>=1 && speed_mode<=4)
                    {
                      analogWrite(5,90); analogWrite(3,0);
                    }
                     if(speed_mode>=5 && speed_mode<=9)
                    {
                      analogWrite(5,180); analogWrite(3,0);
                    }
          myservo.write(90);
       break;
  case'B':   if(speed_mode==10)
  {
          digitalWrite(5,LOW);
          digitalWrite(3,HIGH);
  }
          if(speed_mode==0)
                    {
                      analogWrite(5,0); analogWrite(3,0);
                    }
                     if(speed_mode>=1 && speed_mode<=4)
                    {
                      analogWrite(5,0); analogWrite(3,90);
                    }
                     if(speed_mode>=5 && speed_mode<=9)
                    {
                      analogWrite(5,0); analogWrite(3,180);
                    }
        myservo.write(90);
       break;
  case'S':
          digitalWrite(5,LOW);
          digitalWrite(3,LOW);
        myservo.write(90);
       break;
  case'L':
          myservo.write(30);
          break;
  case'R':
          myservo.write(150);
          break;
  //F-left
  case'G':   if(speed_mode==10)
  {
            digitalWrite(5,HIGH);
            digitalWrite(3,LOW);
  }
            if(speed_mode==0)
                    {  
                      analogWrite(5,0); analogWrite(3,0);
                    }
                     if(speed_mode>=1 && speed_mode<=4)
                    {
                      analogWrite(5,90); analogWrite(3,0);
                    }
                     if(speed_mode>=5 && speed_mode<=9)
                    {
                      analogWrite(5,180); analogWrite(3,0);
                    }
       myservo.write(30);
       break;
  //F-right
  case'I':   if(speed_mode==10)
  {
            digitalWrite(5,HIGH);
          digitalWrite(3,LOW);
  }
    if(speed_mode==0)
                    {  
                      analogWrite(5,0); analogWrite(3,0);
                    }
                     if(speed_mode>=1 && speed_mode<=4)
                    {
                      analogWrite(5,90); analogWrite(3,0);
                    }
                     if(speed_mode>=5 && speed_mode<=9)
                    {
                      analogWrite(5,180); analogWrite(3,0);
                    }
       myservo.write(150);
       break;
  //B-left
  case'H': if(speed_mode==10)
  {
            digitalWrite(5,LOW);
            digitalWrite(3,HIGH);
  }      
            if(speed_mode==0)
                    {  
                      analogWrite(5,0); analogWrite(3,0);
                    }
                     if(speed_mode>=1 && speed_mode<=4)
                    {
                      analogWrite(5,0); analogWrite(3,90);
                    }
                     if(speed_mode>=5 && speed_mode<=9)
                    {
                      analogWrite(5,0); analogWrite(3,180);
                    }   
            
             myservo.write(30);
       break;
  //B-right
  case'J':  if(speed_mode==10)
  {
             digitalWrite(5,LOW);
             digitalWrite(3,HIGH);
  }
             if(speed_mode==0)
                    {  
                      analogWrite(5,0); analogWrite(3,0);
                    }
                     if(speed_mode>=1 && speed_mode<=4)
                    {
                      analogWrite(5,0); analogWrite(3,90);
                    }
                     if(speed_mode>=5 && speed_mode<=9)
                    {
                      analogWrite(5,0); analogWrite(3,180);
                    }
  
        myservo.write(150);
       break;

           case '0': speed_mode=0;break;
           case '1': speed_mode=1;break;
           case '2': speed_mode=2;break;
           case '3': speed_mode=3;break;
           case '4': speed_mode=4;break;
           case '5': speed_mode=5;break;
           case '6': speed_mode=6;break;
           case '7': speed_mode=7;break;
           case '8': speed_mode=8;break;
           case '9': speed_mode=9;break;
           case 'q': speed_mode=10;break;

          default: break;
}
}
void loop()
{
if(Serial.available()>0)
{
  char x = Serial.read();
  Serial.println(x);
  bot_movement(x);
}
}
