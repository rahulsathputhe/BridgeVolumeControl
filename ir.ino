#define irSensorPin 5       // IR sensor on this pin

int irRead(int readPin); //function prototype

void setup()
{
  pinMode(irSensorPin, INPUT);
  Serial.begin(9600); 
  
  Serial.println("Program Starting"); 
  delay(100); 
}

void loop()
{  
  int count=0;
  while(1) //when 1 is returned the loop breaks and the function ends
  {
      if(irRead(irSensorPin)==0){
          doSomething(&count);
      }
    
      delay(1000);
  }
  
}
int irRead(int readPin)
{
  int halfPeriod = 13;
  int cycles = 38; 
  int i;
  
  for (i=0; i <=cycles; i++)
  {
    delayMicroseconds(halfPeriod);
    delayMicroseconds(halfPeriod - 1);        
  }
  return digitalRead(readPin);
}
int doSomething(int *count){
    int read;
  *count=*count+1;
    read = *count;
    Serial.println(*count);
}
