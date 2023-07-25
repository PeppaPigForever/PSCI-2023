#include <LiquidCrystal.h> //library so we can access the functions required for the Liquid Crystal Display
int led=13;                //Initialisation for the additional LED (The light altering one)
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //Initialisation of LCD pins
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);                  //Actual LCD initialisation
const int pResistor = A3; //Photoresitor pin
int value;				        //Variable for storing the input of the photoresistor
void setup() {  //run once
  lcd.begin(16, 2);       //Define the size of the LCD(16 columns, 2 rows)
  pinMode(pResistor, INPUT); //Define the photoresistor pin as a read(Data is INPUT through it)
  pinMode(led, OUTPUT);      //Define led as a OUTPUT (We can change its value)
}

void loop() { //keep running
  value = analogRead(pResistor); //read the value of the photoresistor
  lcd.clear();                   //clear lcd screen, so that there is no chance of data corruption
  lcd.setCursor(0, 0);           //start inputing data at coordinates (0,0) which is the start
  lcd.print("Light:");           //Next three lines is just how the LCD shows data with formatting, using the value collected above
  lcd.print(value);
  lcd.print("512");
  if(value<300){                 //check value, if its too low, it will turn on the Led
    digitalWrite(led,HIGH);
  } else{
    digitalWrite(led,LOW);
  }
  delay(100);                   //It is a 0.1 delaymakes sure that the program does not get overwhelmed by doing it every single tick, instead, have a little bit of time in between each read/write cycle                         
}
