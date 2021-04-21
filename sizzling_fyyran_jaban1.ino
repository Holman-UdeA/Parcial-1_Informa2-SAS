int SER = 2;
int SRCLK = 3;
int RCLK = 4;

void setup()
{
  pinMode(SER, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);
}

void loop()
{
  H();
}

void DisplaceAndShow()
{
  digitalWrite(SRCLK, 0);
  digitalWrite(SRCLK, 1);
  digitalWrite(SRCLK, 0);
  
  digitalWrite(RCLK, 0);
  digitalWrite(RCLK, 1);
  digitalWrite(RCLK, 0);
}

void Corrido()
{
  digitalWrite(SRCLK, 0);
  digitalWrite(SRCLK, 1);
  digitalWrite(SRCLK, 0);
}

void H()
{
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 0);
  DisplaceAndShow();
  
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 1);
  DisplaceAndShow();
}

void O()
{
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 0);
  DisplaceAndShow();
  
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 1);
  Corrido();
  digitalWrite(SER, 0);
  Corrido();
  digitalWrite(SER, 0);
  DisplaceAndShow();
}
