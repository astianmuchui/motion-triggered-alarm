int ledpin = 12;
int vcc = 15;
int status;
int buzzer = 8;


void setup(){
  pinMode(ledpin, OUTPUT);
  pinMode(vcc, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}
void loop(){
  if(DetectMotion()== true){
    Serial.println("Gatchu!");
    digitalWrite(ledpin, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(ledpin,LOW);
    digitalWrite(buzzer,LOW);
  }
}
// Function to detect motion
bool DetectMotion(){
  status = digitalRead(vcc);
  if(status ==  HIGH){
    return true;
  }else{
    return false;
  }
}
