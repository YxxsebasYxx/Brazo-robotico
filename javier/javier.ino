#include <Wire.h>
const int GY_US42_I2C_ADDR = 0x70; // Dirección I2C del GY-US42

const int Fc1 = 19;
const int Fc2 = 18;
const int M11 =  8;
const int M12 = 7;
const int M21= 9;
const int M22= 10;
int Home = 0;
int codo ;
int base ;
int sensor = 2;   
unsigned long tiempo = millis();
int flag;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  pinMode(sensor,INPUT);
  pinMode(Fc1, INPUT_PULLUP);
  pinMode(Fc1, INPUT_PULLUP);
  pinMode(M11, OUTPUT);
  pinMode(M12, OUTPUT);
  pinMode(M21, OUTPUT);
  pinMode(M22, OUTPUT);
 codo = digitalRead(Fc1);
 base = digitalRead(Fc2);


 if (codo==HIGH){ 
  attachInterrupt(digitalPinToInterrupt(Fc1), handleButtonPress, FALLING);
 }
 if (base==HIGH){
  attachInterrupt(digitalPinToInterrupt(Fc2), handleButtonPress2, FALLING);
 }
}
void handleButtonPress() {
    detachInterrupt(digitalPinToInterrupt(Fc1));
    digitalWrite(M11, LOW);
    digitalWrite(M12, LOW); //en caso de error asignarle el valor de 1 o 0
}
void handleButtonPress2(){
    detachInterrupt(digitalPinToInterrupt(Fc2));
    digitalWrite(M21, LOW);
    digitalWrite(M22, LOW);
}
void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(GY_US42_I2C_ADDR);
  Wire.write(0x51); // Comando para leer distancia en centímetros
  Wire.endTransmission();
  delay(100); // Espera para que el sensor procese el comando
  
  Wire.requestFrom(GY_US42_I2C_ADDR, 2); // Solicita 2 bytes del sensor
  
    int highByte = Wire.read();
    int lowByte = Wire.read();
    int distance = (highByte << 8) + lowByte; // Convierte los dos bytes a una distancia
    Serial.print("Distancia: ");
    Serial.print(distance);
    Serial.println(" cm");
  

tiempo=millis();
 codo = digitalRead(Fc1);
 base = digitalRead(Fc2);
  if (distance >100 && distance < 200){
    flag=1;
    }
  if(millis()-tiempo<100 && Home==0 && flag==1){
    Serial.print("entre");
    tiempo = millis();
    if(codo == HIGH && base == HIGH){
      digitalWrite(M11, HIGH);
      digitalWrite(M12, LOW);
      digitalWrite(M21, HIGH);
      digitalWrite(M22, LOW);
      }
     if(codo == HIGH && base == LOW){
      digitalWrite(M11, HIGH);
      digitalWrite(M12, LOW);
      digitalWrite(M21, LOW);
      digitalWrite(M22, LOW);
      }
      if(codo == LOW && base == HIGH){
      digitalWrite(M11, LOW);
      digitalWrite(M12, LOW);
      digitalWrite(M21, HIGH);
      digitalWrite(M22, LOW);
      }
   if(codo == LOW && base == LOW){
      digitalWrite(M11, LOW);
      digitalWrite(M12, LOW);
      digitalWrite(M21, LOW);
      digitalWrite(M22, LOW);
      Home = 1;
      flag=0;
      }
    }
    Serial.println(Home); 
    if (Home == 1 ){
     
      
      /*
      
      digitalWrite(M11,LOW);
      digitalWrite(M12,HIGH); // CODO ARRIBA
     
      digitalWrite(M11,LOW);
      digitalWrite(M12,LOW);  //APAGA CODO
      
      digitalWrite(M11,HIGH);
      digitalWrite(M12,LOW); //CODO ABAJO
      
      digitalWrite(M21,LOW);
      digitalWrite(M22,HIGH);//BASE DERECHA
      
      digitalWrite(M21,LOW);
      digitalWrite(M22,LOW);// APAGA BASE
      
      digitalWrite(M21,HIGH);
      digitalWrite(M22,LOW); //BASE IZQUIERDA
      */

      
      delay(2000);
      digitalWrite(M11,LOW);
      digitalWrite(M12,HIGH);
      delay(1000);
      digitalWrite(M21,LOW);
      digitalWrite(M22,HIGH);
      delay(1000);
      digitalWrite(M21,LOW);
      digitalWrite(M22,LOW);
      digitalWrite(M11,LOW);
      digitalWrite(M12,LOW);
      delay(600);
      digitalWrite(M21,HIGH);
      digitalWrite(M22,LOW); 
      delay(500);
      digitalWrite(M11,HIGH);
      digitalWrite(M12,LOW); 
      delay(800);
      digitalWrite(M21,LOW);
      digitalWrite(M22,LOW);
      digitalWrite(M11,LOW);
      digitalWrite(M12,LOW);
      delay(500);  
      digitalWrite(M11,LOW);
      digitalWrite(M12,HIGH);
      delay(500);
      digitalWrite(M21,LOW);
      digitalWrite(M22,HIGH);
      delay(1000);
      digitalWrite(M11,LOW);
      digitalWrite(M12,LOW);
      digitalWrite(M21,LOW);
      digitalWrite(M22,LOW);
      delay(500);
      digitalWrite(M21,HIGH);
      digitalWrite(M22,LOW);
      delay(700);
      digitalWrite(M11,LOW);
      digitalWrite(M12,HIGH);
      delay(500);
      digitalWrite(M11,LOW);
      digitalWrite(M12,LOW);
      digitalWrite(M21,LOW);
      digitalWrite(M22,LOW);
      delay(200);
      digitalWrite(M21,LOW);
      digitalWrite(M22,HIGH);
      delay(1500);
      digitalWrite(M21,LOW);
      digitalWrite(M22,LOW);
      delay(100);
      digitalWrite(M21,HIGH);
      digitalWrite(M22,LOW);
      delay(500);
      digitalWrite(M11,HIGH);
      digitalWrite(M12,LOW);
      delay(2000);
      digitalWrite(M11,LOW);
      digitalWrite(M12,LOW);
      digitalWrite(M21,LOW);
      digitalWrite(M22,LOW);
      delay(5000);
      
       
     attachInterrupt(digitalPinToInterrupt(Fc1), handleButtonPress, FALLING);
     attachInterrupt(digitalPinToInterrupt(Fc2), handleButtonPress2, FALLING);
     Home = 0;
    }
}
