//Arduino Nano
#define THROTTLE_IN A1
#define MODIFIED_OUT 10

int TIME_DELAY;
int VAL1;
int VAL2;

void setup() {
// Enable fast shim
  TCCR1A = 0b00000001;  // 8bit
  TCCR1B = 0b00001001;  // x1 fast pwm
  VAL2=0;
//  Serial.begin(9600);
  TIME_DELAY = 20;  // Delaying (smoothing) input value
}

void loop() {
  VAL1=analogRead(THROTTLE_IN);
//  Serial.print("Input: ");
//  Serial.print(VAL1);
  VAL1=map(VAL1,0,1023,0,254);
  VAL1=constrain(VAL1,0,254);
//  Serial.print(" Processing: ");
//  Serial.print(VAL1);
  
  if (VAL1 > VAL2) {
    VAL2=VAL2+1;
    delay(TIME_DELAY);
  }
  else {
    VAL2=VAL1;
  }

  VAL2=constrain(VAL2,0,254);
//  Serial.print(" Output: ");
//  Serial.print(VAL2);
  analogWrite(MODIFIED_OUT, VAL2);
//  Serial.print(" Mod_Output: ");
//  Serial.print(analogRead(MODIFIED_OUT));
// Serial.println("");
}
