#define STEP_PIN 7
#define DIR_PIN 6
#define MS1_PIN 3
#define MS2_PIN 4
#define MS3_PIN 5
#define ENABLE_PIN 2
#define etat digitalRead(DIR_PIN)
#define changeDirection digitalWrite(DIR_PIN, !etat)
int ldr1 = A0;
int ldr2 = A1;
int ldr3 = A2;
int ldr4 = A3;
int gaucheHaut = 0;
int droitHaut = 0;
int gaucheBas = 0;
int droiteBas = 0;
void setup() {
  Serial.begin(9600);
  Serial.println("Test A4988");
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(MS1_PIN, OUTPUT);
  pinMode(MS2_PIN, OUTPUT);
  pinMode(MS3_PIN, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);

  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  pinMode(ldr3, INPUT);
  pinMode(ldr4, INPUT);


  digitalWrite(DIR_PIN, LOW);
  digitalWrite(MS1_PIN, LOW);
  digitalWrite(MS2_PIN, LOW);
  digitalWrite(MS3_PIN, LOW);
  digitalWrite(ENABLE_PIN, LOW);

}
int stopper = 0;
void loop() {
  gaucheHaut = analogRead(ldr1);
  Serial.println(gaucheHaut);
  gaucheBas = analogRead(ldr2);
  Serial.println(gaucheBas);
  if (gaucheHaut < 1000)
    digitalWrite(ENABLE_PIN, LOW);
  else {
    for (int i = 0; i < 800; i++) {
      digitalWrite(STEP_PIN, 1);
      delayMicroseconds(800);
      digitalWrite(STEP_PIN, 0);
      delayMicroseconds(800);
    }
  }
  /*right = analogRead(ldr2);
    Serial.println(right);
    top = analogRead(ldr3);
    Serial.println(top);
    bottom = analogRead(ldr4);
    Serial.println(bottom);*/

}
