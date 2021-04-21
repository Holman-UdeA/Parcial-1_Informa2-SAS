int SER = 2;
int SRCLK = 3;
int RCLK = 4;

void setup()
{
  pinMode(SER, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);
  
  digitalWrite(SER, 1);
  DisplaceAndShow();
  digitalWrite(SER, 1);
  DisplaceAndShow();
  digitalWrite(SER, 1);
  DisplaceAndShow();
  digitalWrite(SER, 1);
  DisplaceAndShow();
  digitalWrite(SER, 1);
  DisplaceAndShow();
  digitalWrite(SER, 1);
  DisplaceAndShow();
  digitalWrite(SER, 1);
  DisplaceAndShow();
  digitalWrite(SER, 1);
  DisplaceAndShow();
  digitalWrite(SER, 0);
  DisplaceAndShow();
  digitalWrite(SER, 0);
  DisplaceAndShow();
  digitalWrite(SER, 0);
  DisplaceAndShow();
  digitalWrite(SER, 0);
  DisplaceAndShow();
  digitalWrite(SER, 0);
  DisplaceAndShow();
  digitalWrite(SER, 0);
  DisplaceAndShow();
  digitalWrite(SER, 0);
  DisplaceAndShow();
  digitalWrite(SER, 0);
  DisplaceAndShow();
  
}

void loop()
{
  
}
void DisplaceAndShow()
{
  digitalWrite(SRCLK, 0);
  digitalWrite(SRCLK, 1);
  digitalWrite(SRCLK, 0);
  
  digitalWrite(RCLK, 0);
  digitalWrite(RCLK, 1);
  digitalWrite(RCLK, 0);
  
  delay(500);
}
