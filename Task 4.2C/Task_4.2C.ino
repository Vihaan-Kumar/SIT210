// Pin assignments
const int buttonPin = 2;     // Push button
const int motionPin = 3;     // Motion sensor
const int led1Pin = 4;       // LED1 that works through the button
const int led2Pin = 5;       // LED2 that works due to motion sensor

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); //input pullup makes readings more consistent and stable
  pinMode(motionPin, INPUT);    
  pinMode(led1Pin, OUTPUT);   
  pinMode(led2Pin, OUTPUT);    

  Serial.begin(9600);
}

void loop() {
  // Read button state 
  bool buttonPressed = digitalRead(buttonPin) == LOW;

  // Read motion sensor state
  bool motionDetected = digitalRead(motionPin) == HIGH;


  if (buttonPressed) {
    digitalWrite(led1Pin, HIGH);
    Serial.println("Button pressed: LED1 ON");
  } else {
    digitalWrite(led1Pin, LOW);
  }

  if (motionDetected) {
    digitalWrite(led2Pin, HIGH);
    Serial.println("Motion detected: LED2 ON");
  } else {
    digitalWrite(led2Pin, LOW);
  }

  delay(100); // Small delay to stabilize everything
}
