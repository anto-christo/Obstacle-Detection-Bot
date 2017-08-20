#define Lp 7 //left pin of positive motor
#define Ln 4 // left negative
#define El 5 // Enable pin of left motor
#define Rp 8 //right motor positive pin
#define Rn 12 //pin no of right negative motor
#define Er 6 //Enable pin of right motor. if it is 0 right motor is always off
#define led 13
#define obsSensor 2

int i=0;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(obsSensor,INPUT);
  pinMode(Lp,OUTPUT);
  pinMode(Ln,OUTPUT);
  pinMode(El,OUTPUT);
  pinMode(Er,OUTPUT);
  pinMode(Rp,OUTPUT);
  pinMode(Rn,OUTPUT);
  pinMode(led,OUTPUT);
  
  digitalWrite(El,HIGH);
  digitalWrite(Er,HIGH);
}

void loop() 
{

  // put your main code here, to run repeatedly:
  if(digitalRead(obsSensor))
  { 
    if(i==0)
    {
      MotorControl(0,0); //(left,right)
      Serial.println("stop");
      delay(50);
      MotorControl(2,1);
      Serial.println("left");
      delay(365);
      i++;
      MotorControl(0,0); //(left,right)
      Serial.println("stop");
      delay(50);
    }
    else if(i==1)
    {
       MotorControl(0,0); //(left,right)
       Serial.println("stop");
       delay(50);
       MotorControl(1,2);
       Serial.println("right");
       delay(365);
       i++;    
       MotorControl(0,0); //(left,right)
       Serial.println("stop");
       delay(50);
    }
    else if(i==2)
    {
       MotorControl(0,0); //(left,right)
       Serial.println("stop");
       delay(50);
       MotorControl(2,1);
       Serial.println("left");
       delay(365);
       i++;    
       MotorControl(0,0); //(left,right)
       Serial.println("stop");
       delay(50);
    }
    else if(i==3)
    {
      MotorControl(0,0); //(left,right)
      Serial.println("stop");
      delay(50);
      MotorControl(2,1);
      Serial.println("left");
      delay(365);
      i++;
      MotorControl(0,0); //(left,right)
      Serial.println("stop");
      delay(50);
    }
    else if(i==4)
    {
      MotorControl(0,0); //(left,right)
      Serial.println("stop");
      delay(50);
      MotorControl(1,2);
      Serial.println("right");
      delay(365);
      i++;
      MotorControl(0,0); //(left,right)
      Serial.println("stop");
      delay(50);
    }
     /*
     digitalWrite(led,LOW);
     MotorControl(0,0); //(left,right)
     Serial.println("stop");
     delay(0);
     
     
     MotorControl(2,2); 
     Serial.println("reverse");
     delay(0);
     
     MotorControl(1,2);
     Serial.println("right");
     delay(300);
    
     MotorControl(2,1);
     Serial.println("left");
     delay(300);
     */
  }
  else
  {
    digitalWrite(led,HIGH);
    MotorControl(1,1);
    Serial.println("straight");
  }
  
}

void MotorControl(int driveL,int driveR)
{
  switch(driveL)
  {
    case 0: 
      digitalWrite(Ln,LOW);
      digitalWrite(Lp,LOW);
      break;
    case 1:
      digitalWrite(Ln,HIGH);
      digitalWrite(Lp,LOW);
      break;
    case 2:
      digitalWrite(Ln,LOW);
      digitalWrite(Lp,HIGH);
      break;
    default: 
      break;
  }
  
  switch(driveR)
  {
    case 0:
      digitalWrite(Rn,LOW);
      digitalWrite(Rp,LOW);
      break;
    case 1:
      digitalWrite(Rn,HIGH);
      digitalWrite(Rp,LOW);
      break;
    case 2:
      digitalWrite(Rn,LOW);
      digitalWrite(Rp,HIGH);
      break;
    default: 
      break;
  }
  
}


