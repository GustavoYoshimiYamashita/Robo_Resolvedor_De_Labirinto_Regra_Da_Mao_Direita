
void leituraUltrassonico(){
  
  digitalWrite(trig_pin1Frente, HIGH);
  delayMicroseconds(11600);
  digitalWrite(trig_pin1Frente, LOW);
  uint32_t pulse_time1 = pulseIn(echo_pin1Frente, HIGH, 23320);

  distanceNORTE = pulse_time1/58;
  if(distanceNORTE <= 0) distanceNORTE = 400;

  //Serial.print("distancia frente: ");
  //Serial.println(distanceNORTE);
  
  //////////////////////////////////////////////
  
  digitalWrite(trig_pin1Direita, HIGH);
  delayMicroseconds(11600);
  digitalWrite(trig_pin1Direita, LOW);
  uint32_t pulse_time2 = pulseIn(echo_pin1Direita, HIGH, 23320);

  distanceLESTE = pulse_time2/58;
  if(distanceLESTE <= 0) distanceLESTE = 400;

  //Serial.print("distancia direita: ");
  //Serial.println(distanceLESTE);
}
