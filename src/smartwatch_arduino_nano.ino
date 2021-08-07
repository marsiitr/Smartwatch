
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "RTClib.h"
#include <OneWire.h>
#include <DallasTemperature.h>


RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

#define SCREEN_WIDTH 128   
#define SCREEN_HEIGHT 64 

#define ONE_WIRE_BUS 8
#define Pin1 3
#define Pin2 6
#define Pin3 5

#define OLED_RESET 4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
  int buzzer = 11;
  char Incoming_value = 0;
  float Celsius = 0;
  byte option = 0;
  byte pin3_pressed = 0;
  byte menu_selected = 0;
  byte call,whatsapp,msg;
  uint8_t thisSec, thisMin, thisHour;
  byte sethr, setmin;
  
OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);


void setup() 
{
  sensors.begin();
  Serial.begin(9600);
  delay(3000); // wait for console opening
  pinMode(Pin1, INPUT);
  pinMode(Pin2, INPUT);
  pinMode(Pin3, INPUT);
  
  if (! rtc.begin()) 
 {
    Serial.println("Couldn't find RTC");
    while (1);
 }

  if (rtc.lostPower()) 
  {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  display.clearDisplay();
  display.display(); 
  display.setTextColor(WHITE, BLACK);
}

  //date and time function
void showtime()
{
  // for rectangle
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK,WHITE);
  display.setCursor(20,0);
  display.println("MARS Smartwatch");
  display.drawRoundRect(2, 12, 126, 52, 8, WHITE);

  //delay(2000);

  DateTime now = rtc.now();  


  //Date
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(8,15);
  display.print(daysOfTheWeek[now.dayOfTheWeek()]);

  
    display.setTextSize(1);
    display.setCursor(8,29);
    display.print(now.day());
    display.print("/");
    display.print(now.month());
    display.print("/");
    display.setTextSize(1);
    display.setCursor(44,29);
    display.print(now.year(), DEC);


  //Time
  //char buffer [16];
  
  thisSec = now.second();
  thisMin = now.minute();
  thisHour = now.hour();
  //sprintf (buffer, "%02d:%02d:%02d", thisHour, thisMin, thisSec);

    display.setTextSize(2);
    display.setCursor(8,44);
    display.print(now.hour());
    display.print(":");
    display.print(now.minute());
    display.print(":");
    display.print(now.second());

  display.display(); 
  delay(3000);
  display.clearDisplay();
  display.display(); 
}



 //Temperature function
void temperature (){
   sensors.requestTemperatures();
      delay(100);
      Celsius = sensors.getTempCByIndex(0);
 
    if(Celsius == -127.00){
      }
    else
  {
    display.drawRoundRect(2, 2, 126, 62, 8, WHITE);
    display.setCursor(10,20);
    display.setTextSize(1);
    display.println("temperature: ");
    display.setCursor(40,35);
    display.print(Celsius);
    display.print(" C");
    display.display();
    delay(3000);
    display.clearDisplay();
  }
}

 //Menu
void menu ()
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(40,0);
  display.println("MENU");
  display.drawRoundRect(2, 12, 126, 52, 8, WHITE);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(8,15);
  display.println("Notifications");
  display.setCursor(8,30);
  display.println("Temperature");
  display.setCursor(8,45);
  display.println("Alarm");  
   display.display();
}

//highlight options
void highlight(int option){
  if(option == 1){
    display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(40,0);
  display.println("MENU");
  display.drawRoundRect(2, 12, 126, 52, 8, WHITE);
  display.setTextSize(1);
  display.setTextColor(BLACK,WHITE);
  display.setCursor(8,15);
  display.println("Notifications");
  display.setTextColor(WHITE);
  display.setCursor(8,30);
  display.println("Temperature");
  display.setCursor(8,45);
  display.println("Alarm");  
   display.display();
  }
  else if(option == 2){
    display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(40,0);
  display.println("MENU");
  display.drawRoundRect(2, 12, 126, 52, 8, WHITE);
  display.setTextSize(1);
  display.setCursor(8,15);
  display.println("Notifications");
  display.setTextColor(BLACK,WHITE);
  display.setCursor(8,30);
  display.println("Temperature");
  display.setTextColor(WHITE);
  display.setCursor(8,45);
  display.println("Alarm");  
   display.display();
  }
   else if(option == 3){
    display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(40,0);
  display.println("MENU");
  display.drawRoundRect(2, 12, 126, 52, 8, WHITE);
  display.setTextSize(1);
  display.setCursor(8,15);
  display.println("Notifications"); 
  display.setCursor(8,30);
  display.println("Temperature");
  display.setTextColor(BLACK,WHITE);
  display.setCursor(8,45);
  display.println("Alarm");  
   display.display();
  }
}

//Notification
void notification(){
    display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
  display.println("NOTIFICATIONS");
  display.drawRoundRect(2, 12, 126, 52, 8, WHITE);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(8,15);
  display.print(call);
  display.println("     Calls");
  display.setCursor(8,30);
  display.print(whatsapp);
  display.println("   whatsapp");
  display.setCursor(8,45);
  display.print(msg);
  display.println("   Messages"); 
   display.display();
   delay(3000);
   display.clearDisplay();
   
}

void alarm(){
  display.setCursor(40,15);
  display.println("Alarm"); 
  display.drawRoundRect(2, 12, 126, 52, 8, WHITE);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(8,15);
  display.println("Set time");
  display.setCursor(8,30);
  display.print(sethr);
  display.print(":");
  display.print(setmin);
  display.setCursor(8,45);
  display.println("Alarm On");  
   display.display();
  display.display();
  delay(2000);
}

void buzz (){
  tone(buzzer, 1000); // Send 1KHz sound signal...
      delay(2000);        // ...for 2 sec
      noTone(buzzer);     // Stop sound...
      delay(1000);        // ...for 1 sec
}

void loop() 
{
  
  if(Serial.available() > 0)  
  {
    
    Incoming_value = Serial.read();      //Read the incoming data and store it into variable Incoming_value
    //Serial.print(Incoming_value);        //Print Value of Incoming_value in Serial monitor
    //Serial.print("\n");        //New line 
    if(Incoming_value == 'c')            //Checks whether value of Incoming_value is equal to c 
  {
    call++;
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(35, 25);// Display static text
    display.setTextSize(1);
    display.print(call);
    display.println(" X CALL");
    display.display(); 
    buzz();
   display.clearDisplay(); 
    display.display();

  }
 if(Incoming_value == 'w')       //Checks whether value of Incoming_value is equal to w
    {
      whatsapp++;
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(20, 20);// Display static text
      display.setTextSize(1);
      display.print(whatsapp);
      display.println(" X WHATSAPP");
      display.display(); 
       buzz();
      display.clearDisplay(); 
      display.display();
    }  
  if(Incoming_value == 'm')       //Checks whether value of Incoming_value is equal to m
    {
      msg++;
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(20, 20);// Display static text
      display.setTextSize(1);
      display.print(msg);
      display.println(" X MESSAGE");
      display.display();  
       buzz();
      display.clearDisplay();
    }
  }
 
 
 if (digitalRead(Pin1) == HIGH)  //if home button (Pin1) is pressed then it will show date and time
 {
 showtime();
 }

 if (digitalRead(Pin2)== HIGH && option == 0)    //if menu button (Pin 2) is pressed then it will open the menu
 {
  menu();
 }


 if (digitalRead(Pin3)== HIGH){
  pin3_pressed = pin3_pressed + 1;
 }
option = pin3_pressed % 4;
highlight(option);

 if (digitalRead(Pin2)== HIGH && option == 1 )
 {
  display.clearDisplay();
  notification(); 
  }

if (digitalRead(Pin2)== HIGH && option == 2 )
 {
       display.clearDisplay();
       temperature();
  }


if (digitalRead(Pin2)== HIGH && option == 3 )
 {
      display.clearDisplay();
      alarm();
  }
if (sethr == thisHour || setmin == thisMin)
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(35, 20);// Display static text
    display.setTextSize(1);
    display.print(call);
    display.println("Wake Up");
    display.display(); 
    buzz();   
    buzz();
    buzz();
   
}
delay(100);
}
