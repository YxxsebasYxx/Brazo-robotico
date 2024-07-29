#include <Encoder.h>
// Define el pin del botón
const int buttonPin = 21;
const int Motor1 =  8;
const int Motor2 = 7;
const int EncoderB = 51;
const int EncoderA = 53;

// Variable para almacenar el contador
volatile int counter = 0;
// Crea un objeto Encoder
Encoder myEncoder(EncoderA, EncoderB);
long encoderPosition = 0;
// Variable para almacenar la posición del encoder

// Función que se llama cuando se presiona el botón

// Función que se llama cuando ocurre una interrupción
void handleButtonPress() {
    detachInterrupt(digitalPinToInterrupt(buttonPin));
  //noInterrupts();
  counter++;
  //EIFR |= (1 << INTF0); // Limpia la bandera de interrupción para INT0
 // interrupts();

}

void setup() {
  // Inicializa la comunicación serial
  Serial.begin(9600);

  // Configura el pin del botón como entrada
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(Motor1, OUTPUT);
  pinMode(Motor2, OUTPUT);

  // Adjunta una interrupción al pin del botón
  // El número de interrupción es 0 para el pin 2 en la mayoría de los Arduinos
  // La interrupción se dispara en el cambio de nivel bajo a alto (RISING)
attachInterrupt(digitalPinToInterrupt(buttonPin), handleButtonPress, FALLING);
  while (counter == 0){
    digitalWrite(Motor1,HIGH);
    digitalWrite(Motor2,LOW);
    Serial.print("Contador: ");
    Serial.println(counter);
  
    
  }
  digitalWrite(Motor1,LOW);
  digitalWrite(Motor2,LOW);
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

  // Espera un segundo
}