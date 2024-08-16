#include <avr/io.h>
#include <avr/interrupt.h>
#include <Wire.h>

const int GY_US42_I2C_ADDR = 0x70; // Dirección I2C del GY-US42

const int Fc1 = 19;
const int Fc2 = 18;
const int M11 = 8;
const int M12 = 7;
const int M21 = 9;
const int M22 = 10;
int a=0;
int Home = 0;
int codo;
int base;
int sensor = 2;
unsigned long tiempo;
int flag;

volatile uint8_t toggle_state = 0;

// Configuración del Timer1
void setup() {
    // Configuración inicial
  tiempo = millis();
    Wire.begin();
    Serial.begin(9600);
    pinMode(sensor, INPUT);
    pinMode(Fc1, INPUT_PULLUP);
    pinMode(Fc2, INPUT_PULLUP); // Corregido Fc2
    pinMode(M11, OUTPUT);
    pinMode(M12, OUTPUT);
    pinMode(M21, OUTPUT);
    pinMode(M22, OUTPUT);
  
    codo = digitalRead(Fc1);
    base = digitalRead(Fc2);

 

    // Configura las interrupciones para los finales de carrera
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
    digitalWrite(M12, LOW); // Detiene el motor correspondiente
}

void handleButtonPress2() {
    detachInterrupt(digitalPinToInterrupt(Fc2));
    digitalWrite(M21, LOW);
    digitalWrite(M22, LOW); // Detiene el motor correspondiente
}
boolean distancias (){
      // Mide la distancia utilizando el sensor ultrasónico
    Wire.beginTransmission(GY_US42_I2C_ADDR);
    Wire.write(0x51); // Comando para leer distancia en centímetros
    Wire.endTransmission();
  
    delay(100); // Espera para que el sensor procese el comando
  
    Wire.requestFrom(GY_US42_I2C_ADDR, 2); // Solicita 2 bytes del sensor
  
    int highByte = Wire.read();
    int lowByte = Wire.read();
    int valor=  (highByte << 8) + lowByte; // Convierte los dos bytes a una distancia
if (valor > 100 && valor < 200) {
    return true;
    }else
     digitalWrite(M11, LOW);
     digitalWrite(M12, LOW);
     digitalWrite(M21, LOW);
     digitalWrite(M22, LOW);
     Serial.println("motores detenidos");
    return false;
}
void loop() {
  //  Serial.print("Distancia: ");
 //   int distance=distancias(); 
 //   Serial.print(distance);
 //   Serial.println(" cm");
  
      codo = digitalRead(Fc1);
    base = digitalRead(Fc2);
    flag=distancias();

    if (millis() - tiempo > 100 && Home == 0 && flag == 1) {
        Serial.print("Entre");
        tiempo = millis();
//codo=0;
//base=0;

        if (codo == HIGH && base == HIGH) {
            digitalWrite(M11, HIGH);
            digitalWrite(M12, LOW);
            digitalWrite(M21, HIGH);
            digitalWrite(M22, LOW);
            Serial.println("motores moviendose");
        } else if (codo == HIGH && base == LOW) {
            digitalWrite(M11, HIGH);
            digitalWrite(M12, LOW);
            digitalWrite(M21, LOW);
            digitalWrite(M22, LOW);
            Serial.println("codo moviendose");
        } else if (codo == LOW && base == HIGH) {
            digitalWrite(M11, LOW);
            digitalWrite(M12, LOW);
            digitalWrite(M21, HIGH);
            digitalWrite(M22, LOW);
             Serial.println("base moviendose");
        } else if (codo == LOW && base == LOW) {
            digitalWrite(M11, LOW);
            digitalWrite(M12, LOW);
            digitalWrite(M21, LOW);
            digitalWrite(M22, LOW);
            Home = 1;
          Serial.println("motores detenido");
        }
    }

   // Serial.println(Home); 

    if (Home == 1 && millis()-tiempo>500 && flag==1) {
        // Secuencia de movimientos predefinida
        tiempo=millis();
        a=a+1;
        Serial.println("Coreo");
        Serial.println(a);
        switch(a){
        case 4:
               digitalWrite(M11, LOW);
               digitalWrite(M12, HIGH);
              break;
        case 6:
              digitalWrite(M21, LOW);
              digitalWrite(M22, HIGH);
              break;
        case 8:
              digitalWrite(M21, LOW);
              digitalWrite(M22, LOW);
              digitalWrite(M11, LOW);
              digitalWrite(M12, LOW);
        break; 
        case 9:
        digitalWrite(M21, HIGH);
        digitalWrite(M22, LOW); 
        break;        
        case 10:
        digitalWrite(M11, HIGH);
        digitalWrite(M12, LOW); 
        break;        
        case 11:
        digitalWrite(M21, LOW);
        digitalWrite(M22, LOW);
        digitalWrite(M11, LOW);
        digitalWrite(M12, LOW);
        break;
        case 12:
        digitalWrite(M11, LOW);
        digitalWrite(M12, HIGH);
        break;        
        case 13:
        digitalWrite(M21, LOW);
        digitalWrite(M22, HIGH);
        break;
        case 14:
        digitalWrite(M11, LOW);
        digitalWrite(M12, LOW);
        digitalWrite(M21, LOW);
        digitalWrite(M22, LOW);
        break;                 
        case 15:
        digitalWrite(M21, HIGH);
        digitalWrite(M22, LOW);
        break;
        case 16:
        digitalWrite(M11, LOW);
        digitalWrite(M12, HIGH);
         break;
        case 17:
        digitalWrite(M11, LOW);
        digitalWrite(M12, LOW);
        digitalWrite(M21, LOW);
        digitalWrite(M22, LOW);
        break;
        case 18:
        digitalWrite(M21, LOW);
        digitalWrite(M22, HIGH);
        break;
        case 19:
        digitalWrite(M21, LOW);
        digitalWrite(M22, LOW);
        break;
        case 20:
        digitalWrite(M21, HIGH);
        digitalWrite(M22, LOW);
        break;
        case 21:
        digitalWrite(M11, HIGH);
        digitalWrite(M12, LOW);
        break;
        case 22:
        digitalWrite(M11, LOW);
        digitalWrite(M12, LOW);
        digitalWrite(M21, LOW);
        digitalWrite(M22, LOW);
        a=0;
         break;                       
        case 23:
        
        // Reactivar las interrupciones para los finales de carrera

        attachInterrupt(digitalPinToInterrupt(Fc1), handleButtonPress, FALLING);
        attachInterrupt(digitalPinToInterrupt(Fc2), handleButtonPress2, FALLING);
        Home = 0;
        break;  
        }
            
    }
}
