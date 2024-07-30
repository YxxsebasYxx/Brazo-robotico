#include <Encoder.h>
// Define el pin del botón
const int buttonPin1 = 21;
const int Motor1 =  8;
const int Motor2 = 7;
const int EncoderB = 51;
const int EncoderA = 53;
const int Motor3=9;
const int Motor4=10;
const int buttonPin2 = 20;
const int encoderC = 49;
const int encoderD = 47;

// Variable para almacenar el contador
volatile int counter1 = 0;
volatile int counter2 = 0;

// Crea un objeto Encoder
Encoder myEncoder(EncoderA, EncoderB);
long encoderPosition = 0;
// Variable para almacenar la posición del encoder

// Función que se llama cuando se presiona el botón

// Función que se llama cuando ocurre una interrupción
void handleButtonPress() {
    detachInterrupt(digitalPinToInterrupt(buttonPin1));
 counter1++;
}
void handleButtonPress2(){
    detachInterrupt(digitalPinToInterrupt(buttonPin2));
 counter2++;
}

 



void setup() {
  // Inicializa la comunicación serial
  Serial.begin(9600);

  // Configura el pin del botón como entrada
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(Motor1, OUTPUT);
  pinMode(Motor2, OUTPUT);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(Motor3, OUTPUT);
  pinMode(Motor4, OUTPUT);

  // Adjunta una interrupción al pin del botón
  // El número de interrupción es 0 para el pin 2 en la mayoría de los Arduinos
  // La interrupción se dispara en el cambio de nivel bajo a alto (RISING)
attachInterrupt(digitalPinToInterrupt(buttonPin1), handleButtonPress, FALLING);
attachInterrupt(digitalPinToInterrupt(buttonPin2), handleButtonPress2, FALLING);
  while (counter1 == 0){
    digitalWrite(Motor1,HIGH);
    digitalWrite(Motor2,LOW);
    Serial.print("Contador: ");
    Serial.println(counter1);
  }
  while (counter2 == 0){
    digitalWrite(Motor1,HIGH);
    digitalWrite(Motor2,LOW);
    Serial.print("Contador: ");
    Serial.println(counter2);
  }
  
  
if (counter1 !=0){  
  digitalWrite(Motor1,LOW);
  digitalWrite(Motor2,LOW);
}
if (counter2 !=0){  
  digitalWrite(Motor3,LOW);
  digitalWrite(Motor4,LOW);
}

  
  encoderPosition = 0;

  // Imprime un mensaje de inicio
  Serial.println("Sistema iniciado. Pulsa el botón.");
}

void loop() {
    // Lee el valor actual del encoder
  encoderPosition = myEncoder.read();

  // Imprime el valor del encoder
  Serial.print("Encoder Position: ");
  Serial.println(encoderPosition);

  // Espera un poco antes de la siguiente iteración
  delay(100);
Movimiento_CODO();
Movimiento_BASE();

  // Espera un segundo
}

void Movimiento_CODO(){
  digitalWrite(Motor1,LOW);
  digitalWrite(Motor2,HIGH);
  delay(2000);
  digitalWrite(Motor1,LOW);
  digitalWrite(Motor2,LOW);
  delay(1000);
  digitalWrite(Motor1,HIGH);
  digitalWrite(Motor2,LOW);
  delay(2000);
   digitalWrite(Motor1,LOW);
  digitalWrite(Motor2,LOW);
  delay(4000);
}
void Movimiento_BASE(){
  delay(4000); 
  digitalWrite(Motor3,HIGH);
  digitalWrite(Motor4,LOW);
  delay(2000);
  digitalWrite(Motor3,LOW);
  digitalWrite(Motor4,LOW);
  delay(1000);
  digitalWrite(Motor3,LOW);
  digitalWrite(Motor4,HIGH);
  delay(2000);
  digitalWrite(Motor3,LOW);
  digitalWrite(Motor4,LOW);
  delay(4000);
  }
  
  
  
