const int Fc1 = 2;
const int Fc2 = 3;
const int PIRPin = 4;  // Pin al que está conectado el sensor PIR
const int M11 = 8;
const int M12 = 7;
const int M21 = 9;
const int M22 = 10;
int Home = 0;
int pirState = LOW;  // Estado inicial del PIR
unsigned long tiempo = 0;
unsigned long interval = 100;

void setup() {
  Serial.begin(9600);

  pinMode(Fc1, INPUT_PULLUP);
  pinMode(Fc2, INPUT_PULLUP);
  pinMode(PIRPin, INPUT);  // Configura el PIR como entrada
  pinMode(M11, OUTPUT);
  pinMode(M12, OUTPUT);
  pinMode(M21, OUTPUT);
  pinMode(M22, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(Fc1), handleButtonPress, FALLING);
  attachInterrupt(digitalPinToInterrupt(Fc2), handleButtonPress2, FALLING);

  Serial.println("Esperando detección de movimiento...");
}

void handleButtonPress() {
  detachInterrupt(digitalPinToInterrupt(Fc1));
  detenerMotor(M11, M12);
}

void handleButtonPress2() {
  detachInterrupt(digitalPinToInterrupt(Fc2));
  detenerMotor(M21, M22);
}

void detenerMotor(int motor1, int motor2) {
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
}

void moverMotor(int motor1, int motor2, int tiempo, bool reverse = false) {
  if (reverse) {
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
  } else {
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
  }
  delay(tiempo);
  detenerMotor(motor1, motor2);
}

void loop() {
  int codo = digitalRead(Fc1);
  int base = digitalRead(Fc2);
  int pirVal = digitalRead(PIRPin);  // Leer el estado del PIR

  if (pirVal == HIGH && pirState == LOW) {
    // El PIR ha detectado movimiento
    Serial.println("¡Movimiento detectado por el PIR!");
    pirState = HIGH;
    tiempo = millis();  // Resetear el temporizador

    // Iniciar secuencia de movimiento
    if (codo == HIGH && base == HIGH && Home == 0) {
      moverMotor(M11, M12, 0);  // Mover motor 1 hacia adelante
      moverMotor(M21, M22, 0);  // Mover motor 2 hacia adelante
    }

    if (codo == LOW && base == LOW && Home == 0) {
      detenerMotor(M11, M12);
      detenerMotor(M21, M22);
      Home = 1;
    }
  }

  if (Home == 1) {
    realizarSecuencia();
    regresarAPosicionInicial();
    reactivarInterrupciones();
    Home = 0;
    pirState = LOW;  // Resetear el estado del PIR para la siguiente detección
  }
}

<<<<<<< HEAD
void Movimiento(){
  delay(1500);
  digitalWrite(Motor1,LOW);
  digitalWrite(Motor2,HIGH);
  delay(2000);
  digitalWrite(Motor1,LOW);
  digitalWrite(Motor2,LOW);
=======
void realizarSecuencia() {
  moverMotor(M11, M12, 1000);
  moverMotor(M11, M12, 1000);
  delay(500);
  moverMotor(M21, M22, 1000);
  delay(500);
  moverMotor(M21, M22, 1000);
}

void regresarAPosicionInicial() {
  moverMotor(M11, M12, 1000, true);  // Mover motor 1 en reversa
  moverMotor(M11, M12, 1000, true);
  delay(1500);
  moverMotor(M21, M22, 1000, true);  // Mover motor 2 en reversa
>>>>>>> 84597710e1844bff2b20529980e00f3fbe48cdfa
  delay(1000);
  moverMotor(M21, M22, 1000, true);
  delay(1000);
  moverMotor(M11,M12,1000,true);
}

void reactivarInterrupciones() {
  attachInterrupt(digitalPinToInterrupt(Fc1), handleButtonPress, FALLING);
  attachInterrupt(digitalPinToInterrupt(Fc2), handleButtonPress2, FALLING);
}