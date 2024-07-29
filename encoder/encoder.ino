#include <Encoder.h>

// Define los pines a los que están conectados el A y B del encoder
#define ENCODER_PIN_A 39
#define ENCODER_PIN_B 41

// Crea una instancia del encoder
Encoder myEncoder(ENCODER_PIN_A, ENCODER_PIN_B);

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando...");
}

void loop() {
  // Lee la posición actual del encoder
  long position = myEncoder.read();

  // Imprime la posición en el monitor serial
  Serial.print("Posición: ");
  Serial.println(position);

  // Espera un poco antes de la próxima lectura
  delay(100);
}
