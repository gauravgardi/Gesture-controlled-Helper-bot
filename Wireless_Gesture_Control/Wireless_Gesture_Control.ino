int ml_1 = 22;
int ml_2 = 23;
int mr_1 = 24;
int mr_2 = 25;
int mg_1 = 26;
int mg_2 = 27;
int ms_1 = 28;
int ms_2 = 29;
char motion,slide;
String rfid;
String s1 = "33009256887F";
String s2 = "33009665AE6E";
String s3 = "1A008DCFFAA2";
String s4 = "1A007345361A";
String s5 = "1A0072BDF124";
String s6 = "220084AEBFB7";
String s7 = "3300969DCBF3";
String s8 = "220084C5680B";
String s9 = "3300965A4AB5";
String s10 = "3300927964BC";
String s11 = "33009773FF28";
String s12 = "330096CEEB80";
String sp1 = "340011CD739B";
String sp2 = "340011E323E5";
//7 segment display
int a = 30;  //For displaying segment "a"
int b = 31;  //For displaying segment "b"
int c = 32;  //For displaying segment "c"
int d = 33;  //For displaying segment "d"
int e = 34;  //For displaying segment "e"
int f = 35;  //For displaying segment "f"
int g = 36;  //For displaying segment "g"
void setup()
{
  pinMode(ml_1,OUTPUT);
  pinMode(ml_2,OUTPUT);
  pinMode(mr_1,OUTPUT);
  pinMode(mr_2,OUTPUT);
  pinMode(mg_1,OUTPUT);
  pinMode(mg_2,OUTPUT);
  pinMode(ms_1,OUTPUT);
  pinMode(ms_2,OUTPUT);
  pinMode(a, OUTPUT);  //A
  pinMode(b, OUTPUT);  //B
  pinMode(c, OUTPUT);  //C
  pinMode(d, OUTPUT);  //D
  pinMode(e, OUTPUT);  //E
  pinMode(f, OUTPUT);  //F
  pinMode(g, OUTPUT);  //G
  Serial1.begin(9600);//bluetooth for motion
  Serial2.begin(9600);//bluetooth for slidding
  Serial3.begin(9600);//rfid reader
  Serial.begin(9600);
}
void displayDigit(int digit)
{
 //Conditions for displaying segment a
 if(digit!=1 && digit != 4)
 digitalWrite(a,HIGH);
 
 //Conditions for displaying segment b
 if(digit != 5 && digit != 6)
 digitalWrite(b,HIGH);
 
 //Conditions for displaying segment c
 if(digit !=2)
 digitalWrite(c,HIGH);
 
 //Conditions for displaying segment d
 if(digit != 1 && digit !=4 && digit !=7)
 digitalWrite(d,HIGH);
 
 //Conditions for displaying segment e 
 if(digit == 2 || digit ==6 || digit == 8 || digit==0)
 digitalWrite(e,HIGH);
 
 //Conditions for displaying segment f
 if(digit != 1 && digit !=2 && digit!=3 && digit !=7)
 digitalWrite(f,HIGH);
 if (digit!=0 && digit!=1 && digit !=7)
 digitalWrite(g,HIGH);
 
}
void turnOff()
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}

void loop()
{
   while(Serial1.available()>0)
  {
    delay(5); //delay added to stabilize things
    motion = Serial1.read();
    if(motion == 's')
    break;
  }
  if(motion=='f')
  {
    digitalWrite(ml_1,HIGH);
    digitalWrite(ml_2,LOW);
    digitalWrite(mr_1,LOW);
    digitalWrite(mr_2,HIGH);
  }
  else if(motion=='b')
  {
    digitalWrite(ml_1,LOW);
    digitalWrite(ml_2,HIGH);
    digitalWrite(mr_1,HIGH);
    digitalWrite(mr_2,LOW);
  }
  else if(motion == 'l')
  {
    digitalWrite(ml_1,LOW);
    digitalWrite(ml_2,HIGH);
    digitalWrite(mr_1,LOW);
    digitalWrite(mr_2,HIGH);
  }
  else if(motion == 'r')
  {
    digitalWrite(ml_1,HIGH);
    digitalWrite(ml_2,LOW);
    digitalWrite(mr_1,HIGH);
    digitalWrite(mr_2,LOW);
  }
  else if(motion == 'h')
  {
    digitalWrite(ml_1,HIGH);
    digitalWrite(ml_2,LOW);
    digitalWrite(mr_1,LOW);
    digitalWrite(mr_2,LOW);
  }
  else if(motion == 'a')
  {
    digitalWrite(ml_1,LOW);
    digitalWrite(ml_2,LOW);
    digitalWrite(mr_1,LOW);
    digitalWrite(mr_2,HIGH);
  }
  else if(motion == 'd')
  {
    digitalWrite(ml_1,LOW);
    digitalWrite(ml_2,HIGH);
    digitalWrite(mr_1,LOW);
    digitalWrite(mr_2,LOW);
  }
  else if(motion == 'c')
  {
    digitalWrite(ml_1,LOW);
    digitalWrite(ml_2,LOW);
    digitalWrite(mr_1,HIGH);
    digitalWrite(mr_2,LOW);
  }
  else
  {
    digitalWrite(ml_1,LOW);
    digitalWrite(ml_2,LOW);
    digitalWrite(mr_1,LOW);
    digitalWrite(mr_2,LOW);
  }
    
  while(Serial2.available()>0)
  {
    delay(5);//delay added to  stabilize things
    slide = Serial2.read();
    if(slide == 's')
    break;
  }
  if(slide == 'u')
  {
    digitalWrite(ms_1,HIGH);
    digitalWrite(ms_2,LOW);
  }
  else if(slide == 'd')
  {
    digitalWrite(ms_1,LOW);
    digitalWrite(ms_2,HIGH);
  }
  else if(slide == 'g')
  {
    digitalWrite(mg_1,HIGH);
    digitalWrite(mg_2,LOW);
  }
  else if(slide == 'n')
  {
    digitalWrite(ms_1,LOW);
    digitalWrite(ms_2,HIGH);
  }
 else
 {
    digitalWrite(ms_1,LOW);
    digitalWrite(ms_2,LOW);
    digitalWrite(mg_1,LOW);
    digitalWrite(mg_2,LOW);
 }
   
  while(Serial3.available()>0)
  {
    delay(5);
    char x = Serial3.read();
    rfid+=x;
  }
  Serial.println("RFID:");
  Serial.println(rfid);
  displayDigit(1);
  delay(1000);
  turnOff();
  /*if(rfid.equalsIgnoreCase(s1))
  {
    displayDigit(1);
    delay(1000);
    turnOff();
  }
  
  if(rfid.equalsIgnoreCase(s2))
  {
    displayDigit(2);
    delay(1000);
    turnOff();
  }
  if(rfid.equalsIgnoreCase(s3))
  {
    displayDigit(3);
    delay(1000);
    turnOff();
  }*/
  rfid = "";
  //delay(1000);
}

  
    
    
  
