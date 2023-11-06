const int sensorPin = 34;   

float volt;
float ntu;
 
void setup()
{
  Serial.begin(115200);
  delay(1000);
}
 
void loop()
{
    
    volt = 0;
    for(int i=0; i<800; i++)                              
    {
        volt += ((float)analogRead(sensorPin)/4095)*3.3;    
    }
    volt = volt/800;                                     
    volt = round_to_dp(volt,1);                          
    volt=volt+2.85;
    
    if(volt < 2.5)
    {                                      
      ntu = 3000;                                               
    }
    else
    {                                                
      ntu = -1120.4*(volt*volt)+5742.3*volt-4353.8;      
     ntu=ntu+580.56;
    }
    
    Serial.println("Voltage="+String(volt)+" V --------> Turbidity="+String(ntu)+" NTU");  
    delay(3000);                                                                           
    
       
}
 
float round_to_dp( float in_value, int decimal_place )    
{
  float multiplier = powf( 10.0f, decimal_place );
  in_value = roundf( in_value * multiplier ) / multiplier;
  return in_value;
}
