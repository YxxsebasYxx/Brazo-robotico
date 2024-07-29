#include <Encoder.h>

// Define los pines a los que están conectados los canales A y B del encoder
const int pinA = 4; // Canal A del encoder
const int pinB = 7; // Canal B del encoder

const int initial = 25000;



// Crea una instancia del objeto Encoder
Encoder encoder(pinA, pinB);

// Variable para almacenar la posición del encoder


void setup() {
  // Inicializa la comunicación serial
  Serial.begin(9600);
 

  pinMode(pinA,INPUT);
  pinMode(pinB,INPUT);


}

void loop() {
   
  long encoderPos = 0;
  // Lee la posición actual del encoder
  encoderPos = encoder.read();

  // Imprime la posición del encoder en el monitor serial
    Serial.print("Posición del encoder: ");
    
   Serial.println(encoderPos);

}
