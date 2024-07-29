#include <Encoder.h>
#include <PID_v1.h>

// Define los pines del botón, motor y encoders
const int buttonPin = 21;
const int Motor1 = 8;
const int Motor2 = 7;
const int EncoderA = 49;
const int EncoderB = 53;

// Crea un objeto Encoder
Encoder myEncoder(EncoderA, EncoderB);

// Variables para el PID
double Setpoint, Input, Output;
double Kp = 2, Ki = 5, Kd = 1;  // Constantes PID

// Crea un objeto PID
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

// Función que se llama cuando se presiona el botón
void handleButtonPress() {
  detachInterrupt(digitalPinToInterrupt(buttonPin));
  myEncoder.write(0);  // Reinicia el contador del encoder
  Setpoint = 45;  // Establece un nuevo setpoint de 45 grados
  attachInterrupt(digitalPinToInterrupt(buttonPin), handleButtonPress, FALLING);
}

void setup() {
  // Inicializa la comunicación serial
  Serial.begin(9600);

  // Configura los pines del botón y motor
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(Motor1, OUTPUT);
  pinMode(Motor2, OUTPUT);

  // Adjunta una interrupción al pin del botón
  attachInterrupt(digitalPinToInterrupt(buttonPin), handleButtonPress, FALLING);

  // Configura el PID
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(-255, 255);

  // Establece el setpoint inicial
  Setpoint = 0;

  // Imprime un mensaje de inicio
  Serial.println("Sistema iniciado. Pulsa el botón.");
}

void loop() {
  // Lee el valor actual del encoder
  Input = myEncoder.read() * (360.0 / 360.0);  // Ajusta el divisor según el número de pulsos por revolución de tu encoder

  // Ejecuta el cálculo del PID
  myPID.Compute();

  // Controla el motor en base al output del PID
  if (Output > 0) {
    analogWrite(Motor1, Output);
    analogWrite(Motor2, 0);
  } else {
    analogWrite(Motor1, 0);
    analogWrite(Motor2, -Output);
  }

  // Imprime el valor del encoder y del setpoint
  Serial.print("Encoder: ");
  Serial.print(Input);
  Serial.print(" Setpoint: ");
  Serial.println(Setpoint);

  // Espera un poco antes de la siguiente iteración
  delay(100);
}
