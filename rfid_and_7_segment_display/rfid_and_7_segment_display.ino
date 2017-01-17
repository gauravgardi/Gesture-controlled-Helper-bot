int rdiftx = 1;
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
int a = 2;  //For displaying segment "a"

int b = 3;  //For displaying segment "b"
int c = 4;  //For displaying segment "c"
int d = 5;  //For displaying segment "d"
int e = 6;  //For displaying segment "e"
int f = 8;  //For displaying segment "f"
int g = 9;  //For displaying segment "g"

void setup() {    
  pinMode(a, OUTPUT);  //A
  pinMode(b, OUTPUT);  //B
  pinMode(c, OUTPUT);  //C
  pinMode(d, OUTPUT);  //D
  pinMode(e, OUTPUT);  //E
  pinMode(f, OUTPUT);  //F
  pinMode(g, OUTPUT);  //G
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
 String s="";
  while(Serial.available()>0)
  {
    char ch = Serial.read();
     s+=ch;
  }
  if(s.equals(s1))
  {
    displayDigit(1);
    delay(1000);
    turnOff();
  }
  else if(s.equals(s2))
  {
    displayDigit(2);
    delay(1000);
    turnOff();
  }
}
     
