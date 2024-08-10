int vibPin = 8;
int echoPin = 13;
int trigPin = 12;

float distance;
int duration;
int i;
float total;
float avgDistance;
int numMeas = 50;


void setup() {
  // put your setup code here, to run once:
pinMode(vibPin,OUTPUT);
pinMode(echoPin, INPUT);
pinMode(trigPin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  total = 0;
for(i=1;i<=numMeas;i++){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,HIGH);

  duration = pulseIn(echoPin,HIGH);

  distance = duration * 0.034/2;
  total += distance;
  delay(15);
}
avgDistance = total/numMeas;
Serial.println(avgDistance);
delay(50);

if(avgDistance < 15){
  digitalWrite(vibPin,HIGH);
  delay(1000);
  digitalWrite(vibPin,LOW);
  delay(100);
}else{
  digitalWrite(vibPin,LOW);
}
}
