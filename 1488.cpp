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
int one = 1;
int two = 1;
int three = 1;
int four = 1;

int first[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
int second[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
int third[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
int foured[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

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
      if(one == 0)
      {
        proverka1 = true;
        one = 0;
        if(two == 3)
        {
          proverka2 = true;
          two = 3;
          if(three == 7)
          {
            proverka3 = true;
            three = 7;
            if(four == 7)
            {
              proverka4 = true;
              four = 7;
              RGB_color(0,255,0);
              servo1.write(0);
            }
          }
        }
      }
  }

  
  delay(1000);

  lcd.setCursor(0, 1);
  
  if(proverka4 == false)lcd.print("                "); // очищаем строку перед печатью новых цифр
  
  lcd.setCursor(0, 1);
  lcd.print("HackCode:");
  lcd.print(first[one]);
  lcd.print(" ");
  lcd.print(second[two]);
  lcd.print(" ");
  lcd.print(third[three]);
  lcd.print(" ");
  lcd.print(foured[four]);


  if (proverka1 == false)one = random(0, 10); // генерация случайного числа от 0 до 9
  if (proverka2 == false)two = random(0, 10); 
  if (proverka3 == false)three = random(0, 10); 
  if (proverka4 == false)four = random(0, 10);  
}

void RGB_color(int red_value, int green_value, int blue_value)
 {
    analogWrite(red_pin, red_value);
    analogWrite(green_pin, green_value);
    analogWrite(blue_pin, blue_value);
}
