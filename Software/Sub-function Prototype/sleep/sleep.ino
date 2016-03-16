void Fall_Asleep(void) 
{
  delay(debounce_delay);     // delay for approximately 250ms, longer than duration of switch bounce
  // Put all I/O pins into input mode to save power when uC goes to sleep:
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT_PULLUP);   // pullup resistor for switch that will interrupt sleep mode
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT_PULLUP);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  pinMode(13,INPUT);
  pinMode(14,INPUT);
  pinMode(15,INPUT);
  // Enable interrupt upon HIGH to LOW transition at pin 5 (P1.3, S2 on LaunchPad board)
  P1IE |= BIT3;              // Enable interrupt by change in voltage at pin P1.3
  P1IES |= BIT3;             // Specifically, trigger interrupt at HIGH to LOW transition in P1.3
  P1IFG &= ~BIT3;            // Clear interrupt flage IFG corresponding to pin P1.3
  // fall asleep:
  _BIS_SR(LPM4_bits + GIE);  // Enter Low Power Mode 4 w/interrupt
  
  // upon waking up:
  delay(debounce_delay);           // delay for approximately 250ms, longer than duration of switch bounce
  Initialize_Pins();                  // Initialize I/O pins after sleep mode
  // wait for user to release the wake-up switch:
  while (digitalRead(sleep_switch) == LOW) {
  }
} 

