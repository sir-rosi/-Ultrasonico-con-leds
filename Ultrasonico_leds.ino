/*
   ################
   #   Lab15125   #
   ################
modificado por: Matias Rossi Toledo
Inicio declaracion funcion readUltrasonicDistance y demas variables
*/
int rojo=4;// -------|
int amarillo=7;//----| Se crearon estas variables para facilitar la lectura del codigo
int verde=8;// ------|
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Inicializar LOW para limpiar trigger por 2 microsegundos
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Inicializar trigger en HIGH por 8 microsegundos para comenzar
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(8);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // lectura de pin echo con el retorno de la señal
  return pulseIn(echoPin, HIGH);
}
/*
Fin declaracion funcion readUltrasonicDistance
*/


/*
Inicio funcion setup
*/
void setup()
{
  pinMode(rojo,OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);// se considera una velocidad estandar de 9600 baudios
}
/*
Fin funcion setup
*/


/*
Inicio funcion loop
*/
void loop()
{
  float distancia = 0.01723 * readUltrasonicDistance(2, 2);// se cambia de tipo int a tipo float
  Serial.print("medicion [cm]: ");
  Serial.println(distancia);//para calibrar
  if((distancia <= 336) && (distancia >= 200)) // se considera distancia maxima 336 en vez de 333
    digitalWrite(verde,HIGH);
  } 
  else {
    digitalWrite(verde,LOW);
  }
  if((distancia < 200) && (distancia >= 100)) {
    digitalWrite(amarillo,HIGH);
  } 
  else {
    digitalWrite(amarillo,LOW);
  }
  if(distancia < 100) {
    digitalWrite(rojo,HIGH);
  } 
  else {
    digitalWrite(rojo,LOW);
  }
   

  delay(10); // Delay a little bit to improve simulation performance
}
/*
Inicio funcion loop
*/

/*
 #######################
 #   Fin de programa   #
 #######################
*/
