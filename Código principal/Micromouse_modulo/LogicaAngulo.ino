void receberPosAngular() {
  mpu6050.update();
  // GUARDA NA MEMÓRIA OS VALORES ENVIADOS PELO GIROSCOPIO
  anguloZ = mpu6050.getAngleZ();
}
void virarParaDireita() {
  receberPosAngular();
  int ideal;
  if (direcao == 8) {
    ideal = 0;
  }
  if (direcao == 6) {
    ideal = 90;
  }
  if (direcao == 2) {
    ideal = 180;
  }
  if (direcao == 4) {
    ideal = 270;
  }
  while (anguloZ < ideal - 5) {
    Serial.print("AnguloZ: ");
    Serial.print(anguloZ);
    Serial.print(" ideal: ");
    Serial.println(ideal);
    receberPosAngular();
    analogWrite(pinMot2A, 150); //PID
    analogWrite(pinMot2B, 0);
    //esquerda
    analogWrite(pinMot1A, 0);
    //direita
    analogWrite(pinMot1B, 150);
  }
  analogWrite(pinMot2A, 0); //PID
  analogWrite(pinMot2B, 0);
  //esquerda
  analogWrite(pinMot1A, 0);
  //direita
  analogWrite(pinMot1B, 0);
}
