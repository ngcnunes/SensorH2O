#include <Adafruit_SH110X.h>
#define i2c_Address 0x3c

int buttonPin = 7;
int buttonState = 0;

int level1=A3;
int level2=A2;
int level3=A1;
int level4=A0; //defining to which pin of Arduino the level sensor are connected

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1   //   QT-PY / XIAO
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int a;
int b;
int c;
int d;
int z=150; // If circuit is not displaying correct digit then adjust this value from 100 to 1023 . 


void setup() {
  
 delay(250); // wait for the OLED to power up
 display.begin(i2c_Address); // Address 0x3C default
 //display.setContrast (0); // dim display
 
 display.display();
 delay(2000);

  // Clear the buffer.
  display.clearDisplay();

  pinMode(buttonPin, INPUT);

  pinMode(level1,INPUT);
  pinMode(level2,INPUT);
  pinMode(level3,INPUT);
  pinMode(level4,INPUT);  // defining input pins
}


void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    a=analogRead(level1);
    b=analogRead(level2);
    c=analogRead(level3);
    d=analogRead(level4);

    if (d>z && c>z && b>z && a>z){


    display.clearDisplay();
    display.setTextSize(2); // Set the text size
    display.setTextColor(SH110X_WHITE); // Set the text color to white
    display.setCursor(0,0); // Set the cursor position
    display.print("Sensor H2O");
    
    for(int x =5;x<114;x=x+6){                            //draw scale
      display.drawLine(x, 32, x, 27, SH110X_WHITE);
    }
   display.drawRoundRect(0, 32, 120, 20, 6, SH110X_WHITE);       //draw outline of bar graph
   int r = map(120,0,120,1,120);                           //set bar graph for width of screen
   display.fillRoundRect(1, 33, r, 18, 6, SH110X_WHITE);         //draw bar graph with a width of r
   display.display();                                     //show all that we just wrote & drew
   display.clearDisplay();                                //clear the display
   


    }
  else
  {
  if(a<z && b>z && c>z && d>z){
    display.clearDisplay();
    display.setTextSize(2); // Set the text size
    display.setTextColor(SH110X_WHITE); // Set the text color to white
    display.setCursor(0,0); // Set the cursor position
    display.print("Sensor H2O");
    for(int x =5;x<114;x=x+6){                            //draw scale
      display.drawLine(x, 32, x, 27, SH110X_WHITE);
    }
   display.drawRoundRect(0, 32, 120, 20, 6, SH110X_WHITE);       //draw outline of bar graph
   int r = map(90,0,120,1,120);                           //set bar graph for width of screen
   display.fillRoundRect(1, 33, r, 18, 6, SH110X_WHITE);         //draw bar graph with a width of r
   display.display();                                     //show all that we just wrote & drew
   display.clearDisplay();                                //clear the display
    
  }
   
  else
  {
  if(a<z && b<z && c>z && d>z){
   display.clearDisplay();
    display.setTextSize(2); // Set the text size
    display.setTextColor(SH110X_WHITE); // Set the text color to white
    display.setCursor(0,0); // Set the cursor position
    display.print("Sensor H2O");

    for(int x =5;x<114;x=x+6){                            //draw scale
      display.drawLine(x, 32, x, 27, SH110X_WHITE);
    }
   display.drawRoundRect(0, 32, 120, 20, 6, SH110X_WHITE);       //draw outline of bar graph
   int r = map(60,0,120,1,120);                           //set bar graph for width of screen
   display.fillRoundRect(1, 33, r, 18, 6, SH110X_WHITE);         //draw bar graph with a width of r
   display.display();                                     //show all that we just wrote & drew
   display.clearDisplay();                                //clear the display
  }
   
  else
  {
  if(a<z && b<z && c<z && d>z){
    display.clearDisplay();
    display.setTextSize(2); // Set the text size
    display.setTextColor(SH110X_WHITE); // Set the text color to white
    display.setCursor(0,0); // Set the cursor position
    display.print("Sensor H2O");
    for(int x =5;x<114;x=x+6){                            //draw scale
      display.drawLine(x, 32, x, 27, SH110X_WHITE);
    }
   display.drawRoundRect(0, 32, 120, 20, 6, SH110X_WHITE);       //draw outline of bar graph
   int r = map(30,0,120,1,120);                           //set bar graph for width of screen
   display.fillRoundRect(1, 33, r, 18, 6, SH110X_WHITE);         //draw bar graph with a width of r
   display.display();                                     //show all that we just wrote & drew
   display.clearDisplay();                                //clear the display
   

  } 
  
else
  {
  if(a<z && b<z && c<z && d<z){
   display.clearDisplay();
    display.setTextSize(2); // Set the text size
    display.setTextColor(SH110X_WHITE); // Set the text color to white
    display.setCursor(0,0); // Set the cursor position
    display.print("Sensor H2O");
        for(int x =5;x<114;x=x+6){                            //draw scale
      display.drawLine(x, 32, x, 27, SH110X_WHITE);
    }
   display.drawRoundRect(0, 32, 120, 20, 6, SH110X_WHITE);       //draw outline of bar graph
   int r = map(0,0,120,1,120);                           //set bar graph for width of screen
   display.fillRoundRect(1, 33, r, 18, 6, SH110X_WHITE);         //draw bar graph with a width of r
   display.display();                                     //show all that we just wrote & drew
   display.clearDisplay();                                //clear the display
   

  } 
  }
  }
  }
  }
  }
  else{
  display.clearDisplay();
  display.display();
  }
}

