#include <Encoder.h>

// Definición de pines
const int buttonPin1 = 21;
const int Motor1 = 8;
const int Motor2 = 7;
const int EncoderB = 51;
const int EncoderA = 53;
const int Motor3 = 9;
const int Motor4 = 10;
const int buttonPin2 = 20;
const int encoderC = 49;
const int encoderD = 47;

// Variables para almacenar los contadores
volatile int counter1 = 0;
volatile int counter2 = 0;

// Crea objetos Encoder
Encoder myEncoder1(EncoderA, EncoderB);
Encoder myEncoder2(encoderC, encoderD);

// Variables para almacenar las posiciones iniciales de los encoders
long initialEncoderPosition1 = 0;
long initialEncoderPosition2 = 0;

// Función de interrupción para el primer botón
void handleButtonPress1() {
    counter1++;
}

// Función de interrupción para el segundo botón
void handleButtonPress2() {
    counter2++;
}

void setup() {
    // Inicializa la comunicación serial
    Serial.begin(9600);

    // Configura los pines de entrada y salida
    pinMode(buttonPin1, INPUT_PULLUP);
    pinMode(buttonPin2, INPUT_PULLUP);
    pinMode(Motor1, OUTPUT);
    pinMode(Motor2, OUTPUT);
    pinMode(Motor3, OUTPUT);
    pinMode(Motor4, OUTPUT);

    // Adjunta las interrupciones a los botones
    attachInterrupt(digitalPinToInterrupt(buttonPin1), handleButtonPress1, FALLING);
    attachInterrupt(digitalPinToInterrupt(buttonPin2), handleButtonPress2, FALLING);

    // Mensaje de inicio
    Serial.println("Sistema iniciado. Pulsa el botón.");

    // Guarda las posiciones iniciales de los encoders
    initialEncoderPosition1 = myEncoder1.read();
    initialEncoderPosition2 = myEncoder2.read();
}

void loop() {
    // Lee las posiciones actuales de los encoders
    long encoderPosition1 = myEncoder1.read();
    long encoderPosition2 = myEncoder2.read();

    // Imprime las posiciones de los encoders
    Serial.print("Encoder 1 Position: ");
    Serial.println(encoderPosition1);
    Serial.print("Encoder 2 Position: ");
    Serial.println(encoderPosition2);

    // Controla los motores según los contadores
    controlMotors();

    // Ejecuta los movimientos
    Movimiento_CODO();
    Movimiento_BASE();

    // Espera un poco antes de la siguiente iteración
    delay(100);
}

// Función para controlar los motores
void controlMotors() {
    if (counter1 == 0) {
        digitalWrite(Motor1, HIGH);
        digitalWrite(Motor2, LOW);
        Serial.print("Contador 1: ");
        Serial.println(counter1);
    } else {
        digitalWrite(Motor1, LOW);
        digitalWrite(Motor2, LOW);
    }

    if (counter2 == 0) {
        digitalWrite(Motor3, HIGH);
        digitalWrite(Motor4, LOW);
        Serial.print("Contador 2: ");
        Serial.println(counter2);
    } else {
        digitalWrite(Motor3, LOW);
        digitalWrite(Motor4, LOW);
    }
}

// Función para el movimiento del codo
void Movimiento_CODO() {
    digitalWrite(Motor1, LOW);
    digitalWrite(Motor2, HIGH);
    delay(2000);
    digitalWrite(Motor1, LOW);
    digitalWrite(Motor2, LOW);
    delay(1000);
    digitalWrite(Motor1, HIGH);
    digitalWrite(Motor2, LOW);
    delay(2000);
    digitalWrite(Motor1, LOW);
    digitalWrite(Motor2, LOW);
    delay(2000);
}

// Función para el movimiento de la base
void Movimiento_BASE() {
    long initialPosition = myEncoder2.read();

    // Mueve la base hacia un lado
    digitalWrite(Motor3, HIGH);
    digitalWrite(Motor4, LOW);
    while (abs(myEncoder2.read() - initialPosition) < 700) {
        // Continúa moviendo hasta alcanzar la posición deseada
    }
    digitalWrite(Motor3, LOW);
    digitalWrite(Motor4, LOW);
    delay(1000);

    // Mueve la base hacia el otro lado
    digitalWrite(Motor3, LOW);
    digitalWrite(Motor4, HIGH);
    while (abs(myEncoder2.read() - initialPosition) < 1100) {
        // Continúa moviendo hasta alcanzar la posición deseada
    }
    digitalWrite(Motor3, LOW);
    digitalWrite(Motor4, LOW);
    delay(1000);

    // Vuelve a la posición inicial
    digitalWrite(Motor3, HIGH);
    digitalWrite(Motor4, LOW);
    while (abs(myEncoder2.read() - initialEncoderPosition2) > 10) {
        // Continúa moviendo hasta alcanzar la posición inicial
    }
    digitalWrite(Motor3, LOW);
    digitalWrite(Motor4, LOW);
}
