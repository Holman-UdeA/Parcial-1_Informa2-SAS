int SER = 2;

int SCLRK = 4; //Primer pulso

int RCLK = 3; //Segundo pulso



void setup()

{
  
   pinMode  (SER, OUTPUT);
  
   pinMode (RCLK, OUTPUT);

   pinMode(SCLRK, OUTPUT);
  
  
   digitalWrite(SER, 1);
 
  
Pulso(SCLRK);

   Pulso(RCLK);

   delay(500);

  
 digitalWrite(SER, 0);

  
 Pulso(SCLRK);
  Pulso(RCLK);

   delay(500);
  
  digitalWrite(SER, 1);

  
 Pulso(SCLRK);

   Pulso(RCLK);

}



void loop()

{
  

}


void Pulso(int NumPulso)

{
  
   digitalWrite(NumPulso, 0);

   digitalWrite(NumPulso, 1);

   digitalWrite(NumPulso, 0);

}