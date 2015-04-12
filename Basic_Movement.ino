void setup()
{
  Serial.begin(9600);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(13,OUTPUT);
  analogWrite(9,100);
  analogWrite(10,100); 
}

void forward()
{
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
}

void backward()
{
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
}

void turn_left()
{
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
}

void turn_right()
{
  
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
}
void loop()
{
  //char data = Serial.read();
  /*switch(data)
  {
    case 'w' : delay(500); forward(); break;
    case 's' : delay(500); backward(); break;
    case 'a' : delay(500); turn_left(); break;
    case 'd' : delay(500); turn_right(); break; 
    case 'x' : delay(500); digitalWrite(6,LOW); digitalWrite(7,LOW);
                           digitalWrite(4,LOW); digitalWrite(5,LOW); break;   
  } */
  if(Serial.available())
  {
    char x = Serial.read();
    Serial.println(x);
    if( x == 'u' )
    {
      delay(500);
      forward();      
    }
    switch(x)
    {
      case 'l': turn_left(); break;
      case 'r' : turn_right(); break;
      case 'u' : forward(); break;
      case 'd' : backward(); break;
  }
  }
}
  
  

