#include <Wire.h>

const int GY_US42_I2C_ADDR = 0x70; // Dirección I2C del GY-US42
const int Fc1 = 19;
const int Fc2 = 18;
const int M11 = 8;
const int M12 = 7;
const int M21 = 9;
const int M22 = 10;

int Home = 0;
int codo;
int base;
unsigned long tiempo = millis();
int distancia;
int flag = 0;

void setup() {
  Serial.begin(9600); // Inicia la comunicación serie a 9600 baudios
  Wire.begin(); // Inicia la biblioteca Wire

  pinMode(Fc1, INPUT_PULLUP);
  pinMode(Fc2, INPUT_PULLUP);
  pinMode(M11, OUTPUT);
  pinMode(M12, OUTPUT);
  pinMode(M21, OUTPUT);
  pinMode(M22, OUTPUT);

  codo = digitalRead(Fc1);
  base = digitalRead(Fc2);

  if (codo == HIGH) { 
    attachInterrupt(digitalPinToInterrupt(Fc1), handleButtonPress, FALLING);
  }

  if (base == HIGH) {
    attachInterrupt(digitalPinToInterrupt(Fc2), handleButtonPress2, FALLING);
  }
}

void handleButtonPress() {
  detachInterrupt(digitalPinToInterrupt(Fc1));
  digitalWrite(M11, LOW);
  digitalWrite(M12, LOW); // En caso de error asignarle el valor de 1 o 0
}

void handleButtonPress2() {
  detachInterrupt(digitalPinToInterrupt(Fc2));
  digitalWrite(M21, LOW);
  digitalWrite(M22, LOW);
}

int leerDistancia() {
  Wire.beginTransmission(GY_US42_I2C_ADDR);
  Wire.write(0x51); // Comando para leer distancia en centímetros
  Wire.endTransmission();
  delay(100); // Espera para que el sensor procese el comando
  
  Wire.requestFrom(GY_US42_I2C_ADDR, 2); // Solicita 2 bytes del sensor
  
  if (Wire.available() == 2) {
    int highByte = Wire.read();
    int lowByte = Wire.read();
    return (highByte << 8) + lowByte; // Convierte los dos bytes a una distancia
  }
  
  return -1; // En caso de error, retorna -1
}

void Stop() {
  flag = 0;
  digitalWrite(M11, LOW);
  digitalWrite(M12, LOW);
  digitalWrite(M21, LOW);
  digitalWrite(M22, LOW);
  attachInterrupt(digitalPinToInterrupt(Fc1), handleButtonPress, FALLING);
  attachInterrupt(digitalPinToInterrupt(Fc2), handleButtonPress2, FALLING);
}

void controlarMotores() {
  distancia = leerDistancia();

  tiempo = millis();
  codo = digitalRead(Fc1);
  base = digitalRead(Fc2);

  if (distancia > 100 && distancia < 200) {
    flag = 1;
  }

  if (millis() - tiempo < 100 && Home == 0 && flag == 1) {
    tiempo = millis();
    if (codo == HIGH && base == HIGH) {
      digitalWrite(M11, HIGH);
      digitalWrite(M12, LOW);
      digitalWrite(M21, HIGH);
      digitalWrite(M22, LOW);
    }
    if (codo == HIGH && base == LOW) {
      digitalWrite(M11, HIGH);
      digitalWrite(M12, LOW);
      digitalWrite(M21, LOW);
      digitalWrite(M22, LOW);
    }
    if (codo == LOW && base == HIGH) {
      digitalWrite(M11, LOW);
      digitalWrite(M12, LOW);
      digitalWrite(M21, HIGH);
      digitalWrite(M22, LOW);
    }
    if (codo == LOW && base == LOW) {
      digitalWrite(M11, LOW);
      digitalWrite(M12, LOW);
      digitalWrite(M21, LOW);
      digitalWrite(M22, LOW);
      Home = 1;
    }
  }
}

void ejecutarSecuencia() {
  if (Home == 1 && flag == 1) {
    delay(2000);   
    digitalWrite(M11, LOW);
    digitalWrite(M12, HIGH);
    delay(1800);
    digitalWrite(M11, LOW);
    digitalWrite(M12, LOW);
    delay(1000);
    digitalWrite(M11, HIGH);
    digitalWrite(M12, LOW);
    delay(1000);
    digitalWrite(M11, LOW);
    digitalWrite(M12, LOW);
    delay(200);
    digitalWrite(M21, LOW);
    digitalWrite(M22, HIGH);
    delay(2000);
    digitalWrite(M21, LOW);
    digitalWrite(M22, LOW);
    delay(1000);
    digitalWrite(M21, HIGH);
    digitalWrite(M22, LOW);
    delay(2000);
    digitalWrite(M21, LOW);
    digitalWrite(M22, LOW);

    attachInterrupt(digitalPinToInterrupt(Fc1), handleButtonPress, FALLING);
    attachInterrupt(digitalPinToInterrupt(Fc2), handleButtonPress2, FALLING);
    Home = 0;
    flag = 0;
  }
}

void loop() {
  controlarMotores();
  ejecutarSecuencia();
  controlarMotores();
  delay(10000);
}
