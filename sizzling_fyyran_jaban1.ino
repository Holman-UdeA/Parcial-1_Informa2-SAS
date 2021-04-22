int SER = 2;
int SRCLK = 3;
int RCLK = 4;

int FilasOn[8]= {10101010};
int NumFila = 0;
  
void setup()
{
  Serial.begin(9600);
  pinMode(SER, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);
}

void loop()
{
  AlgoritmoDeOrdenamiento(NumFila);
  NumFila++;
  if(NumFila == 7){
    NumFila = 0;
  }
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

void Show()
{
  digitalWrite(RCLK, 0);
  digitalWrite(RCLK, 1);
  digitalWrite(RCLK, 0);
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

void AlgoritmoDeOrdenamiento(int Fila)
{
  for(int i=0; i<8; i++){
    digitalWrite(SER, FilasOn[i]);
    Corrido();
  }
  for(int i=0; i<8; i++){
    if(i == Fila){
      digitalWrite(SER, 0);
    }
    else{
      digitalWrite(SER, 1);
    }
    Corrido();
  }
  Show();
}
