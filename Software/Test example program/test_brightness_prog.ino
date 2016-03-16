#define H 255
#define M 125
#define L  100
void setup() {                
  // initialize the digital pin as an output.
  pinMode(2, OUTPUT);     
  pinMode(6, OUTPUT);  
  pinMode(7, OUTPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
  analogWrite(2, H);    // turn the LED in pin 2 on with HIGH bright
  analogWrite(6, M);    // turn the LED in pin 6 on with Middle bright
  analogWrite(7, L);     // turn the LED in pin 7 on with LOW bright
  delay(1000);               // wait for a second
}
