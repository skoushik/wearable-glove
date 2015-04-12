#include <Wire.h>
#include <MMA7660.h>

const int numReadings = 10;

int readingsX[numReadings];

int index = 0;
int totalX = 0;
int averageX = 0;

int readingsY[numReadings];

int totalY = 0;
int averageY = 0;


  int count = 0;
  int sumx = 0;
  int sumy = 0;

void setup()
{
  Serial.begin(9600);
  MMA7660.init();
  
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
  {
    readingsX[thisReading] = 0;          
    readingsY[thisReading] = 0;
  }
}

void loop()
{
  int x,y,z;
  delay(100); // There will be new values every 100ms
  MMA7660.getValues(&x,&y,&z);
  
  /*totalX = totalX - readingsX[index];
  totalY = totalY - readingsY[index];
  
  readingsX[index] = x;
  readingsY[index] = y;
  index++;
  
  if (index >= numReadings)
    index = 0;
  averageX = totalX / numReadings;
  Serial.print ("averageX: ");
  Serial.print (averageX);
  
  averageY = totalY / numReadings;
  
    Serial.print ("averageY: ");
  Serial.println (averageY);*/

  if( count == 10 )
  {
    count = 11;
    Serial.println("average X : ");
    Serial.println(sumx/count);
    Serial.println("average Y : ");
    Serial.println(sumy/count);    
    sumx = 0;
    sumy = 0;
  }
  else if( count < 10 )
  {
    sumx += x;
    sumy += y;
    count++;
  
  }
  else
  {
    if ((sumx + x) > (sumx + 30)  && (sumy + y) < (sumy + 20))
    {
      Serial.println("r");
    }
    else if (((sumx + x) < (sumy - 30)) && ((sumy + y) < (sumy + 20)))
    {
      Serial.println("l");
    }
    else if((sumy + y) < (sumy- 10) && (sumx+ x) < (sumx+20))
    {
      Serial.println("u");
    }
    else if((sumy+y) > (sumy+20) && (sumx+x) < (sumx + 10))
    {
      Serial.println("d");
    }
  }
  
//  if(x > 10 && x < 20)
//  {
//    Serial.print("right");
//  }
//  else if( x < 55 && x > 45 )
//  {
//    Serial.print("left");
//  }
//  else if( y > 5 && y < 25 )
//  {
//    Serial.print("forward"); 
//  }
//  else if ( y < 55 && y > 45 )
//  Serial.print("x: ");
//  Serial.print(x);
//  Serial.print(" y: ");
//  Serial.print(y);
//  Serial.print(" z: ");
//  Serial.println(z);

}
