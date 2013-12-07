#include <LiquidCrystal.h>

// var globais
#define BUTTON_PIN A5
#define LCD_LIGHT_PIN A4
#define LCD_LIGHT_ON_TIME 60000
unsigned int currentLcdLightOnTime = 0;
unsigned long lcdLightOn_StartMillis;
boolean isLcdLightOn;
int buttonState = 0;
int BAUD_RATE;

// armazena bytes chegando pela serial
int incom;

// lcd
LiquidCrystal lcd (12, 11, 5, 4, 3, 2);

void setup()
{
  //Configure a baud rate for serial port
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();

  // lcd
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LCD_LIGHT_PIN, OUTPUT);
  digitalWrite(LCD_LIGHT_PIN, LOW);
  isLcdLightOn = false;

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

void loop()
{
  if (Serial.available() > 0)
  {
    incom = Serial.read();
    Serial.print(incom);
    Serial.println();
    lcd.print(incom);
    lcd.println();
  }

  buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == HIGH){
    lcdLightOn_StartMillis = millis();
    currentLcdLightOnTime = 0;
    isLcdLightOn = true;
    digitalWrite(LCD_LIGHT_PIN, HIGH);
  }
  else{
    if(isLcdLightOn){
      currentLcdLightOnTime = millis() - lcdLightOn_StartMillis;
      if(currentLcdLightOnTime > LCD_LIGHT_ON_TIME){
        isLcdLightOn = false;
        digitalWrite(LCD_LIGHT_PIN, LOW);
      }
    }
  }
}

void stopbits(byte stopbit) {
  if (stopbit == 1) {
    UCSR0C = UCSR0C | B00000100; // (stop == 1)
  }
  else {
    UCSR0C = UCSR0C | B00000000; // (stop == 2)
  }
}


void parity(int parity) {
  if ((parity == 'o')|(parity == 'O')) //ODD
  UCSR0C = UCSR0C | B00110000;
  else if ((parity == 'e')|(parity == 'E')) //EVEN
  UCSR0C = UCSR0C | B00100000;
  else if ((parity == 'n')|(parity == 'N')) //NONE
  UCSR0C = UCSR0C | B00000000;
}
