// Declaration of pins
int IN1 = 4;
int IN2 = 3;
int ldr1 = A4;
int ldr2 = A5;
int ldr3 = A2;
int ldr4 = A3;
//int ldr5 = A4;
int gauche_haut = 0;
int gauche_bas = 0;
int droite_haut = 0;
int droite_bas = 0;
//int milieu = 0;
int seuil_1 = 20;// threshold to activate the actuator
int seuil_2 = 700; // difference between day and night
void setup() {
  Serial.begin(9600);
  Serial.println("Test A4988");// allows you to read the value on the LDRs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  pinMode(ldr3, INPUT);
  pinMode(ldr4, INPUT);
  //pinMode(ldr5, INPUT);
}

void loop() {
  // Lire la valeur reçue des LDR
  gauche_haut = analogRead(ldr1);
  Serial.println(gauche_haut+gauche_bas);
  gauche_bas = analogRead(ldr2);
  //Serial.println(gauche_bas);
  droite_haut = analogRead(ldr3);
  Serial.println(droite_haut+droite_bas);
  droite_bas = analogRead(ldr4);
  //Serial.println(droite_bas);
  //milieu = analogRead(ldr5);
  //Serial.println(milieu);
  // Comparer et actionner le verin
  if (((gauche_haut + gauche_bas) - (droite_haut + droite_bas)) > seuil_1) {
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    //delay(1000);

  }

  else if (((droite_haut + droite_bas) - (gauche_haut + gauche_bas)) > seuil_1) {
    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    //delay(1000);

  }

  else {
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 0);
    //delay(1000);
  }
}
