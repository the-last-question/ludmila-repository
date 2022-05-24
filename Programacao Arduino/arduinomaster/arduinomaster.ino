
#define TRIGGER_PIN  5
#define ECHO_PIN     4

#define regiao3 13
#define regiao2 12
#define regiao1 11

float distancia;
float soma = 0;

void setup()
{
  pinMode(regiao3, OUTPUT);
  pinMode(regiao2, OUTPUT);
  pinMode(regiao1, OUTPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.begin(9600);
}

void loop()
{
  soma = 0;
  for(int i = 0; i < 10; i++){
    distancia = getDistance();
    soma = soma + distancia;
    }
    soma = soma / 10;
  Serial.print(String(soma,2));
  Serial.print('\n');

  if (distancia < 10) {
    digitalWrite(regiao3, HIGH);
    digitalWrite(regiao2, LOW);
    digitalWrite(regiao1, LOW);
  }
  else if (distancia < 20) {
    digitalWrite(regiao3, LOW);
    digitalWrite(regiao2, HIGH);
    digitalWrite(regiao1, LOW);
  }
  else {
    digitalWrite(regiao3, LOW);
    digitalWrite(regiao2, LOW);
    digitalWrite(regiao1, HIGH);
  }
  delay(500);
}

float getDistance() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  return pulseIn(ECHO_PIN, HIGH) / 27.6233 / 2.0;
}
