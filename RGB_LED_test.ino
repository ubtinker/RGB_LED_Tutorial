/*
Adafruit Arduino - Lesson 3. RGB LED
*/
 
int redPin = 11;
int greenPin = 10;
int bluePin = 9;

int delay1 = 100;

int red_channel_sat1 = 255;
int green_channel_sat1 = 0;
int blue_channel_sat1 = 0;

int red_channel_sat2 = 0;
int green_channel_sat2 = 255;
int blue_channel_sat2 = 0;


int red_channel_sat3 = 0;
int green_channel_sat3 = 0;
int blue_channel_sat3 = 255;



void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
}
 
void loop()
{
// Set some predefined colors
  setColor(255,0 , 0);  // red
  delay(1000);
  setColor(0, 255, 0);  // green
  delay(1000);
  setColor(0, 0, 255);  // blue
  delay(1000);  
  setColor(255, 255, 0);  // yellow
  delay(1000);
  setColor(80, 0, 80);  // purple
  delay(1000);
  setColor(0, 255, 255);  // aqua
  delay(1000);

  
//Cycle through a rainbow:
  setColor(0,0,0); //Start with it off
  delay(2000);
  unsigned int rgbColour[3];

  // Begins at red.
  rgbColour[0] = 255;
  rgbColour[1] = 0;
  rgbColour[2] = 0;  

  // Choose the colours to increment and decrement.
  for (int decColour = 0; decColour < 3; decColour += 1) {
    int incColour = decColour == 2 ? 0 : decColour + 1;

    // cross-fade the two colours.
    for(int i = 0; i < 255; i += 1) {
      rgbColour[decColour] -= 1;
      rgbColour[incColour] += 1;
      
      setColor(rgbColour[0], rgbColour[1], rgbColour[2]);
      delay(5);
    }
  }

//Cycle through red saturation:
  setColor(0,0,0); //start with it off
  delay(2000);
  while(red_channel_sat1 > 127){
     setColor(red_channel_sat1, green_channel_sat1, blue_channel_sat1);
     delay(100);
     red_channel_sat1 = red_channel_sat1 - 4;
     green_channel_sat1 = green_channel_sat1 + 4;
     blue_channel_sat1 = blue_channel_sat1 + 4;
  }
    red_channel_sat1 = 255;
    green_channel_sat1 = 0;
    blue_channel_sat1 = 0;

  //Cycle through green saturation:
  setColor(0,0,0); //start with it off
  delay(2000);
  while(green_channel_sat2 > 127){
     setColor(red_channel_sat2, green_channel_sat2, blue_channel_sat2);
     delay(100);
     red_channel_sat2 = red_channel_sat2 + 4;
     green_channel_sat2 = green_channel_sat2 - 4;
     blue_channel_sat2 = blue_channel_sat2 + 4;
  }
    red_channel_sat2 = 0;
    green_channel_sat2 = 255;
    blue_channel_sat2 = 0;
    
  //Cycle through blue saturation:
  setColor(0,0,0); //start with it off
  delay(2000);
  while(blue_channel_sat3 > 127){
     setColor(red_channel_sat3, green_channel_sat3, blue_channel_sat3);
     delay(100);
     red_channel_sat3 = red_channel_sat3 + 4;
     green_channel_sat3 = green_channel_sat3 + 4;
     blue_channel_sat3 = blue_channel_sat3 - 4;
  }
    red_channel_sat3 = 0;
    green_channel_sat3 = 0;
    blue_channel_sat3 = 255;
    
  setColor(0,0,0); //end with it off
  delay(2000);
}


//Create a function that sends the signal to change LED brightness (DO NOT REMOVE)
void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
