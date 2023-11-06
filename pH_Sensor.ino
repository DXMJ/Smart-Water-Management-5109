const int SensorPin = 34;         
unsigned long int avgValue;  
float b;
int buf[10],temp;

void setup()
{
  //pinMode(3,OUTPUT);  
    Serial.begin(115200);  
    Serial.println("Ready");    
}  

void loop()
{
  for(int i=0;i<10;i++)      
  { 
    buf[i]=analogRead(SensorPin);
    delay(10);
  }
  for(int i=0;i<9;i++)        
  {
    for(int j=i+1;j<10;j++)
    {
      if(buf[i]>buf[j])
      {
        temp=buf[i];
        buf[i]=buf[j];
        buf[j]=temp;
      }
    }
  }
  avgValue=0;
  for(int i=2;i<8;i++)                      
    avgValue+=buf[i];
  float phValue=(float)avgValue*3.3/4095/6; 
  phValue=5+phValue;  
 
  //convert the millivolt into pH value
  Serial.print("    pH:");  
  Serial.print(phValue,2);
  Serial.println(" ");
  delay(1000); 
}
