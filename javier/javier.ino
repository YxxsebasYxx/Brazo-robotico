const int Fc1 = 21;
const int Fc2 = 20;
const int M11 =  8;
const int M12 = 7;
const int M21= 9;
const int M22= 10;
int Home = 0;

unsigned long tiempo = millis();



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Fc1, INPUT_PULLUP);
  pinMode(Fc1, INPUT_PULLUP);
  pinMode(M11, OUTPUT);
  pinMode(M12, OUTPUT);
  pinMode(M21, OUTPUT);
  pinMode(M22, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(Fc1), handleButtonPress, FALLING);
  attachInterrupt(digitalPinToInterrupt(Fc2), handleButtonPress2, FALLING);
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

 int codo = digitalRead(Fc1);
 int base = digitalRead(Fc2);
  if(millis()-tiempo<100 && Home==0){
    tiempo = millis();
    if(codo == HIGH && base == HIGH){
      digitalWrite(M11, HIGH);
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
      }
    }
    if(Home == 1){
      digitalWrite(M11,LOW);
  digitalWrite(M12,HIGH);
  delay(2000);
  digitalWrite(M11,LOW);
  digitalWrite(M12,LOW);
  digitalWrite(M11,HIGH);
  digitalWrite(M12,LOW);
  delay(1000);
   digitalWrite(M11,LOW);
  digitalWrite(M12,LOW);
  delay(2500);
  digitalWrite(M21,LOW);
  digitalWrite(M22,HIGH);
  delay(2000);
  digitalWrite(M21,LOW);
  digitalWrite(M22,LOW);
  delay(1000);
  digitalWrite(M21,LOW);
  digitalWrite(M22,HIGH);
  delay(2000);
  digitalWrite(M21,LOW);
  digitalWrite(M22,LOW);
      
     attachInterrupt(digitalPinToInterrupt(Fc1), handleButtonPress, FALLING);
     attachInterrupt(digitalPinToInterrupt(Fc2), handleButtonPress2, FALLING);
     Home = 0;
    }
}
