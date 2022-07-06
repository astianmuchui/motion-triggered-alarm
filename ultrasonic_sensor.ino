
#define trigpin 14
#define echopin 27
#define ledpin 13
#define buzzerpin 4

long ult_duration;
long ult_distance;
// Set a reference distance
int expc = 399;
void setup() {
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(ledpin, OUTPUT);
  pinMode(buzzerpin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(trigpin,LOW);
  delayMicroseconds(1);
  digitalWrite(trigpin, HIGH);
  // Activate sensing for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);

  //Read echo pin
  ult_duration = pulseIn(echopin,HIGH);
  ult_distance = ult_duration * 0.034 /2; 
  Serial.print("Distance: ");
  Serial.print(ult_distance);
  Serial.println(" cm");
  if(ult_distance < expc){
    Serial.println("Motion Detected");

    digitalWrite(buzzerpin, HIGH);
    delay(2500);
    digitalWrite(buzzerpin,LOW);

    digitalWrite(ledpin, HIGH);
    delay(100);
    digitalWrite(ledpin, LOW);

    
  }
  delay(10); // this speeds up the simulation
}
