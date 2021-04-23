/*						Manual.

Al iniciar simulación, por el monitor serial se le desplegara
un menú el cual le mostrara que numero debe ingresar según lo
que desee ejecutar, en el caso 1 el sistema automáticamente
comprobara el estado de los leds y le mostrara el mensaje 
"verificando condición de los leds", para el segundo caso debe
ingresar el estado de cada fila de la matriz led representado 
por un numero binario de 8 bits, el estado de cada led estará 
representado por un '1'(prendido) o '0'(Apagado), las filas se 
encuentran numeradas de la 1 a la 8, siendo 1 la fila superior;
Por ejemplo, para encender solo el primer led de la primera fila
el valor a ingresar será "10000000", el programa le pedirá estos 
valores por filas y le mostrara a que fila pertenece el patrón a 
ingresar y también le dirá cuando el patrón se ingresó exitosamente,
debido a que Tinkercad modifica el tiempo de ejecución real, 
solo ingrese los valores cuando el sistema se lo pida; el caso 3 
se encuentra comentado ya que no tuve tiempo para terminar de implementarlo.
*/

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
  /*int **MatrizPatron;
  int NFilas, NColumnas = 8;
  long long int ValueColumna = 0;
    
  cout<<"Ingrese la cantidad de patrones que desea: "; cin >> NFilas; cout << endl;
    
  MatrizPatron = new int*[NFilas]; //Memoria dinamica.
  for(int i=0; i<NFilas; i++){
  	MatrizPatron[i] = new int[NColumnas];
  } 
 
  for(int i=0; i<NFilas; i++){
    for(int j=0; j<NColumnas; j++){
      cout << "Ingrese el valor de la posicion: " << i << j << " :"; cin >> ValueColumna; cout << endl;
      *(*(MatrizPatron+i)+j) = ValueColumna;
    }
  }

  for(int i=0; i<NFilas; i++){
    for(int j=0; j<NColumnas; j++){
      cout << MatrizPatron[i][j] << " ";
    }
    cout << endl;
  }*/
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
