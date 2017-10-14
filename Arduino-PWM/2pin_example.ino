include <avr/io.h>
 
#define PWMPin1 9	// 9ピン
#define PWMPin2 10	// 10ピン
 
unsigned int frq = 10000; // 周波数: 10kHz
float duty1 = 0.50;	// Pin1に指定したいデューティ比
float duty2 = 0.80;	// Pin2に指定したいデューティ比
 
void setup() {
  pinMode(PWMPin1, OUTPUT);
  pinMode(PWMPin2, OUTPUT);
}
 
void loop() {
 
  // モード指定
  TCCR1A = 0b00100000; // <- WGM10 を 0 にすることで ICR1 を TOP 値に指定
  TCCR1B = 0b00010010;
 
  // TOP値指定
  ICR1 = (unsigned int)(1000000 / frq);
 
  // Duty比指定
  OCR1A = (unsigned int)(1000000 / frq * duty1);
  OCR1B = (unsigned int)(1000000 / frq * duty2);
}