void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  dot();  
  dot();   
  dot();   
  dash();  

  space(); 

  dot();   
  dot();   
  
  space(); 

  dot();   
  dot();   
  dot();   
  dot();   
  
  space(); 

  dot();   
  dash(); 
  
  space(); 

  dot();   
  dash(); 
  
  space(); 

  dash(); 
  dot();   
  
  space(); 

  delay(10000);
}

void dot()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);                
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

void dash()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1500);                
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

void space()
{
  delay(1000);
}
