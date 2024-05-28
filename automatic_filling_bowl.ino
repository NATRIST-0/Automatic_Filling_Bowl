#define SENSOR A0
#define LED_ROUGE 10
#define LED_VERTE 9
int etat_sensor, etat_vert, etat_rouge ;
void setup() {
  Serial.begin(9600) ;
  Serial.print ("OK") ;
  pinMode (LED_ROUGE, OUTPUT) ;
  pinMode (LED_VERTE, OUTPUT) ;
  pinMode (SENSOR, INPUT);
}

void loop() {
  int valeur ;
  float volt ;
  valeur = analogRead (SENSOR) ;
  volt = valeur / 1023.0 * 3.3 ;
  if (volt <= 0.5 ) {
    etat_sensor = 1 ; 
  } else {
      etat_sensor = 2 ;
  }
if (etat_sensor == 1) {
  Serial.print ("PAS EAU  ") ;
  digitalWrite(LED_ROUGE, HIGH) ;
  digitalWrite(LED_VERTE, LOW) ;

} else {
  Serial.print ("EAU  ") ;
  digitalWrite(LED_ROUGE, LOW) ;
  digitalWrite(LED_VERTE, HIGH) ;
}
delay(2000) ;
}
