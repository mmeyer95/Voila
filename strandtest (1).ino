#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(17, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

const int  inputMorning = 12;    // the pin that the pushbutton is attached to
const int Afternoon = 13;
const int Evening = 11;
const int off = 10;
int inputMorningState = 0;         // current state of the button
int AfternoonState = 0;
int EveningState =0;
int offState = 0;

void setup() {

  // initialize the button pin as a input:
  pinMode(inputMorning, INPUT);
  pinMode(Afternoon, INPUT);
  pinMode(Evening, INPUT);
  pinMode(off, INPUT);
  // initialize the LED as an output:
  // initialize serial communication:
  //Serial.begin(9600);

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
 strip.show();
  inputMorningState = digitalRead(inputMorning);
  AfternoonState = digitalRead(Afternoon);
  EveningState= digitalRead(Evening);
  offState = digitalRead(off);
  Serial.println(inputMorningState);

    if (inputMorningState == HIGH) {
      //colorWipe(strip.Color(255, 0, 0), 50); // Red
     // colorWipe(strip.Color(0, 255, 0), 50); // Green
      //colorWipe(strip.Color(0, 0, 255), 50); // Blue
     // colorWipe(strip.Color(0, 0, 0, 255), 50); // White RGBW
      //Send a theater pixel chase in...
     // theaterChase(strip.Color(127, 127, 127), 50); // White
       //theaterChase(strip.Color(127, 0, 0), 50); // Red
      //theaterChase(strip.Color(0, 0, 127), 50); // Blue
      rainbow(20);
     // rainbowCycle(20);
     // theaterChaseRainbow(50);
     delay (5000);
      colorWipe(strip.Color(0,0,0), 50);
    } 
    else if (AfternoonState==HIGH){
         //colorWipe(strip.Color(255, 0, 0), 50); // Red
     // colorWipe(strip.Color(0, 255, 0), 50); // Green
      //colorWipe(strip.Color(0, 0, 255), 50); // Blue
     // colorWipe(strip.Color(0, 0, 0, 255), 50); // White RGBW
      //Send a theater pixel chase in...
     // theaterChase(strip.Color(127, 127, 127), 50); // White
       //theaterChase(strip.Color(127, 0, 0), 50); // Red
      //theaterChase(strip.Color(0, 0, 127), 50); // Blue
      rainbow2(20);
     // rainbowCycle(20);
     // theaterChaseRainbow(50);
     //delay (5000);
      //colorWipe(strip.Color(0,0,0), 50);
     
    }
    else if (EveningState==HIGH){
         //colorWipe(strip.Color(255, 0, 0), 50); // Red
     // colorWipe(strip.Color(0, 255, 0), 50); // Green
      colorWipe(strip.Color(0, 0, 63), 50); // Blue
     // colorWipe(strip.Color(0, 0, 0, 255), 50); // White RGBW
      //Send a theater pixel chase in...
     // theaterChase(strip.Color(127, 127, 127), 50); // White
       //theaterChase(strip.Color(127, 0, 0), 50); // Red
      //theaterChase(strip.Color(0, 0, 127), 50); // Blue
      //rainbow2(20);
     // rainbowCycle(20);
     // theaterChaseRainbow(50);
     delay (5000);
     colorWipe(strip.Color(0,0,0), 50);
     
    }
    else if (offState == HIGH){
      colorWipe (strip.Color(0,0,0),10);
    }
    else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
      strip.begin();
      strip.show();
    }
 //colorWipe(strip.Color(255, 0, 0), 50); // Red
 //colorWipe(strip.Color(0, 255, 0), 50); // Green
 // colorWipe(strip.Color(0, 0, 255), 50); // Blue
 // colorWipe(strip.Color(0, 0, 0, 255), 50); // White RGBW
  // Send a theater pixel chase in...
  //theaterChase(strip.Color(127, 127, 127), 50); // White
  //theaterChase(strip.Color(127, 0, 0), 50); // Red
 // theaterChase(strip.Color(0, 0, 127), 50); // Blue

  //rainbow(20);
  //rainbowCycle(20);
  //theaterChaseRainbow(50);

}

// Fill the dots one after the other with a color
      void colorWipe(uint32_t c, uint8_t wait) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, c);
        strip.show();
        delay(wait);
        }
      }

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<24; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
      delay (25);
    }
    strip.show();
    delay(wait);
  }
}

void rainbow2(uint8_t wait) {
  uint16_t i, j;

  for(j=35; j<100; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 127));
      delay (10);
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
  
  
  // Some example procedures showing how to display to the pixels:
 
