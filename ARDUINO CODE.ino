int outputpin=9; 
void setup()
{
  pinMode(outputpin, OUTPUT); 
  TCCR1A=_BV(COM1A1)|_BV(COM1B1); 
  TCCR1B=_BV(WGM13)|_BV(CS11); 
}

void loop()
{
  float count=10000;
  float readinput=0;
  
  while(1)
  {
    ICR1=count;
    OCR1A=int(count/2);
    count=10000;
    readinput=analogRead(A0);
    readinput=(readinput/0.0113);
    count=count+readinput;
    
    if(count>=100000)
      {
        count=10000;
      }
      delay(1000);
    }
}
