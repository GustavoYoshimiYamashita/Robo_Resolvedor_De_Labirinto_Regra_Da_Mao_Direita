//Portas sensor Ultrassonico
const uint8_t trig_pin1Direita = 7;
const uint8_t echo_pin1Direita = 6;
const uint8_t trig_pin1Frente = 5;
const uint8_t echo_pin1Frente = 4;
double distanceNORTE;
double distanceLESTE;

//Variaveis PID
//incluindo as bibliotecas necessarias
#include <MPU6050_tockn.h>
#include <Wire.h>
// DEFINIÇÕES
#define MPU6050_ADDR         0x68 // ENDEREÇO QUANDO O PINO AD0 ESTIVER LIGADO AO GND

#define DEBUG
// INSTANCIANDO OBJETOS
MPU6050 mpu6050(Wire);

// DECLARAÇÃO DE VARIÁVEIS
float anguloX;
float anguloY;
float anguloZ;

// Entrada dos motores
#define pinMot1A 3
#define pinMot2A 9
#define pinMot1B 10
#define pinMot2B 11
double propA;
double propB;


float    diferenca,
         kp = 0.3, //0.5
         ki = 0.0001, //0.0005
         kd = 30.0, // 10.0
         proporcional,
         integral,
         derivativo,
         PID,
         ideal_value = 0,
         ultimaMedida;

//O - 4 /L - 2/ S - 3/ N - 1
int direcao = 8;
int distanciaPercorrida;

void setup() {
  Serial.begin(9600);
  //Sensor ultrassonico
  pinMode(trig_pin1Frente, OUTPUT);
  pinMode(echo_pin1Frente, INPUT);
  digitalWrite(trig_pin1Frente, LOW);
  pinMode(trig_pin1Direita, OUTPUT);
  pinMode(echo_pin1Direita, INPUT);
  digitalWrite(trig_pin1Direita, LOW);
  //Motores
  pinMode(pinMot1A, OUTPUT);
  pinMode(pinMot1B, OUTPUT);
  pinMode(pinMot2A, OUTPUT);
  pinMode(pinMot2B, OUTPUT);
  //Comunicação MPU6050
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(false);// MUDAR PARA "true" SE QUISER VISUALIZAR INFORMAÇÕES DE CALIBRAÇÃO NO MONITOR SERIAL

}
int teste =true;

void loop() {
  //leituraUltrassonico();
  //andarReto();
  direcao = 6;
  if(teste ==true){
    virarParaDireita();    
  }
  teste = false;
  andarReto();
}
