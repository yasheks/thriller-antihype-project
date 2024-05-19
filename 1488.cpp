#include <LiquidCrystal.h>
#include <Servo.h> 

Servo servo1; 
constexpr uint8_t PIN_RS = 6;
constexpr uint8_t PIN_EN = 7;
constexpr uint8_t PIN_DB4 = 8;
constexpr uint8_t PIN_DB5 = 9;
constexpr uint8_t PIN_DB6 = 10;
constexpr uint8_t PIN_DB7 = 11;

LiquidCrystal lcd(PIN_RS, PIN_EN, PIN_DB4, PIN_DB5, PIN_DB6, PIN_DB7);
int one = 0; // начинаем с 0 элемента
int two = 0;
int three = 0;
int four = 0;

int first[] = {6, 6, 6, 7, 7, 7, 3, 3, 3, 1, 1, 1, 2, 2, 2, 4, 4, 4, 9, 9, 9, 8, 8, 8, 5, 5, 5, 0, 0, 0};

int second[] ={2, 2, 2, 7, 7, 7, 1, 1, 1, 9, 9, 9, 5, 5, 5, 4, 4, 4, 0, 0, 0, 3, 3, 3, 8, 8, 8, 6, 6, 6};

int third[] = {7, 7, 7, 1, 1, 1, 9, 9, 9, 8, 8, 8, 0, 0, 0, 5, 5, 5, 3, 3, 3, 4, 4, 4, 6, 6, 6, 2, 2, 2};

int foured[] = {4, 4, 4, 7, 7, 7, 9, 9, 9, 8, 8, 8, 5, 5, 5, 2, 2, 2, 6, 6, 6, 0, 0, 0, 1, 1, 1, 3, 3, 3};

int red_pin= 3;
int green_pin = 4;
int blue_pin = 5;

bool proverka1 = false;
bool proverka2 = false;
bool proverka3 = false;
bool proverka4 = false;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("CODE: 1488");
  lcd.setCursor(0, 1);
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  RGB_color(255, 0, 0);
  servo1.attach(12);
  servo1.write(90);
}
 
void loop() {
  bool button = !digitalRead(2);    

  if(button){
      if(first[one] == 1)
      {
        proverka1 = true;
        if(second[two] == 4)
        {
          proverka2 = true;
          if(third[three] == 8)
          {
            proverka3 = true;
            if(foured[four] == 8)
            {
              proverka4 = true;
              RGB_color(0,255,0);
              servo1.write(0);
            }
          }
        }
      }
  }

  
  delay(500);

  lcd.setCursor(0, 1);
  
  if(proverka4 == false)lcd.print("                "); // очищаем строку перед печатью новых цифр
  
  lcd.setCursor(0, 1);
  lcd.print("HackCode:");
  if (proverka1 == false || first[one] == 1) lcd.print(first[one]);
  lcd.print(" ");
  if (proverka2 == false || second[two] == 4) lcd.print(second[two]);
  lcd.print(" ");
  if (proverka3 == false || third[three] == 8) lcd.print(third[three]);
  lcd.print(" ");
  if (proverka4 == false || foured[four] == 8) lcd.print(foured[four]);


  if (proverka1 == false) one = (one + 1) % 30; // инкрементируем и применяем остаток от деления
  if (proverka2 == false) two = (two + 1) % 30; 
  if (proverka3 == false) three = (three + 1) % 30; 
  if (proverka4 == false) four = (four + 1) % 30;  
}

void RGB_color(int red_value, int green_value, int blue_value)
 {
    analogWrite(red_pin, red_value);
    analogWrite(green_pin, green_value);
    analogWrite(blue_pin, blue_value);
}
