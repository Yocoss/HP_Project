

#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(0);

//declare constants and related pins
const int FLEX_PIN = A0; //pin A0 to read analog input
const int LED_PIN = 3; //pin 3 has PWM funtion to use the led (it also manages the buzzer)
const int BUTTON_PIN = 2;

//declare variables
int flexValue;
int ledState;
bool ohmMode = true;
//screen
int seconds = 0;

//code interrupt, read if button is pushed, if it is switch cf//OO
void button(){
  ohmMode = !ohmMode;
}

void setup() {
  //set pin 3 (led) as output and pin 2 (button) as input
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  //
  lcd_1.begin(16, 2);
  //OO
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), button, CHANGE);
  //begin serial communication
  Serial.begin(9600);
  
}

void loop() {
  lcd_1.begin(16, 2);
  //read flex sensor value
  flexValue = analogRead(FLEX_PIN);
  //map flex sensor value to LED state:
  //map(value, fromLow, fromHigh, toLow, toHigh) 
  ledState = map(flexValue, 767, 964, 0, 100);
  Serial.println(ledState);
  
  //turn LED on and the buzzer if max value (ici 964) reached
  //digitalWrite(LED_PIN, ledState);
  //print the flex sensor value and the selected display mode to serial monitor
  if (ohmMode) {
    Serial.print("Ohm : ");
    Serial.println(flexValue);
    lcd_1.print("Ohm: ");
    lcd_1.println(flexValue);
  } else {
     //map(value, fromLow, fromHigh, toLow, toHigh)
    //767 valeur a vide, égale 0 Newton, reste à définir
    // /10 to replace by the formula obtained previously
    float newtonValue = map(flexValue, 767, 964, 0, 50) / 10;
    Serial.print("Newton : ");
    Serial.println(newtonValue, 3);
    lcd_1.print("N: ");
    lcd_1.println(newtonValue, 3);
  }
  //trigger the led and the buzzer when the maximum value (here 100) is reached
  //to change the ohm value related, change th mapping
  if (ledState == 100){
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  //tried but didnt work: permanently switching mode with only one push:
  //check button state and switch mode if pressed
  //if (digitalRead(BUTTON_PIN) == HIGH) {
  //   ohmMode = !ohmMode;
  //   delay(500);
  
  //delay for 300ms
  delay(300);
}



