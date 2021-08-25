//O - 4/L - 6/ S - 2/ N - 8
float PIDangular(){
  mpu6050.update();
  if(direcao == 8){
    ideal_value = 0;
  }
  if(direcao == 6){
    ideal_value = 90;
  }
  if(direcao == 2){
    ideal_value = 180;
  }
  if(direcao == 4){
    ideal_value = 270;
  }
  



  // GUARDA NA MEMÓRIA OS VALORES ENVIADOS PELO GIROSCOPIO
  anguloZ = mpu6050.getAngleZ();
  

  diferenca = anguloZ - ideal_value;

  proporcional = diferenca * kp;

  integral += diferenca * ki;
 
  derivativo = (anguloZ - ultimaMedida) * kd;

  ultimaMedida = anguloZ;

  PID = proporcional + integral + derivativo;

  //Serial.println(PID);
  return PID;
}

void andarReto(){
  PIDangular();
  Serial.print("PID ");
  Serial.print(PID);
  Serial.print(" Ideal ");
  Serial.println(ideal_value);
  int motor2 = 0;


  if(PID < -5)
  {
      PID = map(PID, 0, -30, 0, 255);
      if(PID > 255) PID = 255;
      motor2 = map(PID, 25, 255, 0, 100); //0-100
      if (motor2 > 100) motor2 = 100;
      analogWrite(pinMot2A, 0); //PID
      analogWrite(pinMot2B, 0);
      //esquerda
      analogWrite(pinMot1A, motor2);
      //direita
      analogWrite(pinMot1B, PID);
  }

  else if(PID > 5)
  {
    PID = map(PID, 0, 30, 0, 255);
    if(PID > 255) PID = 255;
    motor2 = map(PID, 25, 255, 0, 100);//0-100
    if (motor2 > 100) motor2 = 100;
    analogWrite(pinMot2A, 0);
    analogWrite(pinMot2B, 0);  
    //esquerda   
    analogWrite(pinMot1A, PID); 
    //direita                
    analogWrite(pinMot1B, motor2);
  }
  else
  {
    analogWrite(pinMot2A, 0);
    analogWrite(pinMot2B, 0); 
    //esquerda    
    analogWrite(pinMot1A, 200);
    //direita                 
    analogWrite(pinMot1B, 200);
  }
  
}
