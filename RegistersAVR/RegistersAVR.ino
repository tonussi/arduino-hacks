void setup(){
  //Configure a baud rate for serial port
  Serial.begin(9600);
  UCSR0C=B00011100;

  delay(1000);
  //Print out the value of the serial port configuration registers
  Serial.println("Serial Ports Registers");
  Serial.println("----------------------");
  Serial.print("UCSR0A: ");
  Serial.println(UCSR0A,BIN);
  Serial.print("UCSR0B: ");
  Serial.println(UCSR0B,BIN);
  Serial.print("UCSR0C: ");
  Serial.println(UCSR0C,BIN);
  Serial.print("UBRR0H: ");
  Serial.println(UBRR0H,BIN);
  Serial.print("UBRR0L: ");
  Serial.println(UBRR0L,BIN);
}

void loop(){
}

