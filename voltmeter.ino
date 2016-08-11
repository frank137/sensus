float input_voltage = 0.00;
int x = 0;
float sum = 0.0;
float av;
void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
 // analogReference(EXTERNAL); // use AREF for reference voltage
}


void loop(){
  analogReadResolution(12);
  sum = 0;
  for (x = 0; x<150; x ++)
  {
  
    //Conversion formula for voltage
    int analog_value = 0;
    
    analog_value = analogRead(A0);
    input_voltage = (analog_value * 1.585) / 4096.00;
  
    //Serial.print("v= ");
    //Serial.println(input_voltage,4);
    sum = sum+input_voltage;
    delay(10);
  }
  av = sum/x;
  Serial.print("Avarage is: ");
  Serial.println(av,3);
  Serial.println("Number of iteration is: ");
  Serial.println(x);
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  //exit(0);
}
