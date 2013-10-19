void setup(){
  //Configure a baud rate for serial port
  Serial.begin(9600);

  delay(1000);
  //Print out the value of the MCU Control register
  Serial.println("MCU Control Registers");
  Serial.println("----------------------");
  Serial.print("MCUCR: ");
  Serial.println(MCUCR,BIN);

  delay(2000);

  MCUCR=MCUCR | B00010000;

  Serial.println();
  Serial.println("MCU Control Registers");
  Serial.println("----------------------");
  Serial.print("MCUCR: ");
  Serial.println(MCUCR,BIN);
}

void loop(){
}
