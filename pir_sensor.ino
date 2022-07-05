int ledpin = 12;
int vcc = 15;
int status;
void setup(){
  pinMode(ledpin, OUTPUT);
  pinMode(vcc, INPUT);
  Serial.begin(9600);
}
void loop(){
  status = digitalRead(vcc);
  if(status == HIGH){
    Serial.println("Gatchu!");
    digitalWrite(ledpin, HIGH);
    delay(500);
    digitalWrite(ledpin,LOW);
  }
}
