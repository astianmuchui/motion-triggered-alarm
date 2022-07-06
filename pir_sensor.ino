int ledpin = 12;
int vcc = 15;
int status;



void setup(){
  pinMode(ledpin, OUTPUT);
  pinMode(vcc, INPUT);
  Serial.begin(9600);
}
void loop(){
  if(DetectMotion()== true){
    Serial.println("Gatchu!");
    digitalWrite(ledpin, HIGH);
    delay(500);
    digitalWrite(ledpin,LOW);
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
