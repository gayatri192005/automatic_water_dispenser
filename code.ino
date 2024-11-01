// Pin connections
const int trigPin = 9;       // Trig pin of HC-SR04
const int echoPin = 10;      // Echo pin of HC-SR04
const int motorPin = 3;      // Motor connected to pin 3 (via transistor)

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);
  
  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance
  distance = duration * 0.034 / 2;
  
  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Check if distance is within threshold (e.g., 10 cm)
  if (distance <= 10) {
    digitalWrite(motorPin, HIGH);  // Turn on motor
    Serial.println("Object detected! Motor ON (Water dispensing)");
  } else {
    digitalWrite(motorPin, LOW);   // Turn off motor
    Serial.println("No object detected. Motor OFF");
  }
  
  delay(500);  // Wait for a while before the next reading
}
