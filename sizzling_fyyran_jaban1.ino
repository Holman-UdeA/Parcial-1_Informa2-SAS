int SER = 2;
int SRCLK = 3;
int RCLK = 4;

long long int FilaPrueba;

int FilasOn[8][8] = {}; //Arreglos.
int NumFila = 0;
int Contador =0;
int NEjec = 0;
int Opcion, Tam = 10;
char *S = new char[Tam]; //Memoria dinamica.
char W[10] = {'B','I','E','N','V','E','N','I','D','O'};
  
void setup()
{
  Serial.begin(9600);
  pinMode(SER, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);
  
  Menu();
}

void loop()
{
  while(NEjec == 0){
    if(Serial.available() > 0){
      Opcion = Serial.parseInt();
      NEjec++;
    }
  }
  switch(Opcion){
    case 1:
    Verificacion();
    if(NEjec == 1){
      Serial.println("Verificando condicion de los leds.");
      NEjec++;
    }
    break;
    case 2: 
    Imagen();
    case 3:
    Publik();
    break;
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

void Verificacion(){
  for(int i=0; i<16; i++){
    if(i<8){
      digitalWrite(SER, 1);
      Corrido();
    }
    else{
      digitalWrite(SER, 0);
      Corrido();
    }
  }
  Show();
}

void Imagen(){
  if(Contador == 0){
    Serial.println("Ingrese la configuracion de la primer linea de la matriz.");
    Serial.println("Recuerde que estan numeradas de arriba hacia abajo: ");
    while(!Serial.available() > 0){};
  }
  if(Serial.available() > 0){
    FilaPrueba = Serial.parseInt();
    for(int i=7; i>=0; i--){
      FilasOn[Contador][i] = FilaPrueba%10;
      FilaPrueba /= 10;
    }
    Contador++;
    Serial.println("\nSerial ingresado con exito.");
    if(Contador < 8){
      Serial.println("Ingrese la configuracion de la fila "); 
      Serial.print(Contador+1);
    }
    if(Contador == 8){
      Serial.println("Mostrando patron.");
    }
  }
  
  if(Contador == 8){
    AlgoritmoDeOrdenamiento(NumFila);
  	NumFila++; 
  	if(NumFila == 8){
      NumFila = 0;
  	} 
  }
}

void Publik(){
  
}

void Menu(){
  for(int i=0; i<Tam; i++){
    *(S+i) = *(W+i);
  }
  for(int i=0; i<Tam; i++){
    Serial.print(*(S+i));
  }
  Serial.print(". \n");
  Serial.println("\n1. Verificacion.");
  Serial.println("2. Mostrar patron ingresado por el usuario.(Imagen.)");
  Serial.println("3. Mostrar secuencia de patrones.(Publik.)");
  Serial.println("\nIngrese la opcion que desea ejecutar:");
}

void AlgoritmoDeOrdenamiento(int Fila)
{
  for(int i=7; i>=0; i--){
    digitalWrite(SER, *(*(FilasOn+((Fila-7)*-1))+i)); //Uso de punteros.
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
