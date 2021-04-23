int SER = 2;
int SRCLK = 3;
int RCLK = 4;

long long int FilaPrueba;

int FilasOn[8][8] = {};
int NumFila = 0;
int Contador =0;
  
void setup()
{
  Serial.begin(9600);
  pinMode(SER, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);
  
  //Serial.println("Ingrese un 1 cuando desee iniciar.");
}

void loop()
{
  if(Serial.available() > 0){
    FilaPrueba = Serial.parseInt();
    for(int i=7; i>=0; i--){
      FilasOn[Contador][i] = FilaPrueba%10;
      FilaPrueba /= 10;
      Serial.print(FilasOn[Contador][i]);
    }
    Contador++;
    Serial.println("\nSerial ingresado con exito.");
  }
  
  if(Contador == 8){
    AlgoritmoDeOrdenamiento(NumFila);
  	NumFila++; 
  	if(NumFila == 8){
      NumFila = 0;
  	} 
  }
}

void DisplaceAndShow()
{
  Corrido();
  Show();
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
  for(int i=7; i>=0; i--){
    digitalWrite(SER, FilasOn[((Fila-7)*-1)][i]);
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
