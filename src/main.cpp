#include <Arduino.h>
const int pino1 = 11;
const int pino2= 10;
const int pino3 = 9;
const int pinoD0 = 12;
const int pinoA0 = A3;
const int time = 50;
void setup() {
  Serial.begin(9600);
  pinMode(pino1, OUTPUT);
  pinMode(pino2, OUTPUT);
  pinMode(pino3, OUTPUT);
  pinMode(pinoD0, INPUT);
  pinMode(pinoA0, INPUT);
}

void contador() {
  static int cont = 0;
  Serial.println(cont);
  cont ++;
  if (cont > 100) {
    cont = 0;
  }
}

void leitorIntensidade() {
static int dados;
dados = analogRead(pinoA0);
Serial.println(dados);
}

void detectorPalmas() {
  static int dados = 0;
  static int led = 0;
  Serial.println(led);
  dados = digitalRead(pinoD0);
  if (dados == 1) {
    if (led == 1) {
      led--;
      delay(200);
    }
    else {
      led++;
      delay(200);
    }
  }
  if (led == 0) {
    digitalWrite(pino1, 0);
  }
  else {
    digitalWrite(pino1, 1);
  }
}

void loop() {
  // contador();
  leitorIntensidade();
  detectorPalmas();
  // delay(200);
  // digitalWrite(pino1, 1);
  // delay(time);
  // digitalWrite(pino1, 0);
  // delay(time);
  // digitalWrite(pino2, 1);
  // delay(time);
  // digitalWrite(pino2, 0);
  // delay(time);
  // digitalWrite(pino3, 1);
  // delay(time);
  // digitalWrite(pino3, 0);
  // delay(time);
  //  digitalWrite(pino1, 1);
  // delay(time);
  // digitalWrite(pino1, 0);
  // delay(time);
  // digitalWrite(pino2, 1);
  // delay(time);
  // digitalWrite(pino2, 0);
  // delay(time);
}