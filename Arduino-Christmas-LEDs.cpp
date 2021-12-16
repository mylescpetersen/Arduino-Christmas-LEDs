#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN        6
#define NUMPIXELS 600

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 0

// COLOUR DEFINITIONS
#define RED 1
#define GREEN 2
#define BLUE 3
#define YELLOW 4
#define PINK 5
#define PURPLE 6
#define CYAN 7
#define NUM_COLOURS 7

#define SET_RED pixels.setPixelColor(i, pixels.Color(150, 0, 0))
#define SET_GREEN pixels.setPixelColor(i, pixels.Color(0, 150, 0))
#define SET_BLUE pixels.setPixelColor(i, pixels.Color(0, 0, 150))
#define SET_WHITE pixels.setPixelColor(i, pixels.Color(150, 150, 150))
#define SET_WHITE_BACKWARDS pixels.setPixelColor((NUMPIXELS - i), pixels.Color(150, 150, 150))
#define SET_YELLOW pixels.setPixelColor(i, pixels.Color(150, 150, 0))
#define SET_PINK pixels.setPixelColor(i, pixels.Color(255, 68, 204))
#define SET_PURPLE pixels.setPixelColor(i, pixels.Color(165, 0, 255))
#define SET_CYAN pixels.setPixelColor(i, pixels.Color(0, 150, 150))

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
clock_prescale_set(clock_div_1);
#endif

  pixels.begin();
}

void loop() {
  pixels.clear();

  // Set random initial colour
  int solidColour = rand() & NUM_COLOURS;
  for(int i = 0; i<NUMPIXELS; i++) {
    switch (solidColour) {
      case RED:
        SET_RED;
        break;
      case GREEN:
        SET_GREEN;
        break;
      case BLUE:
        SET_BLUE;
        break;
      case YELLOW:
        SET_YELLOW;
        break;
      case PINK:
        SET_PINK;
        break;
      case PURPLE:
        SET_PURPLE;
        break;
      case CYAN:
        SET_CYAN;
        break;
    }
  }

  // Forward red/green 
  for(int i=0; i<NUMPIXELS; i++) {
    if (i % 2 == 0) {
      SET_RED;
    }
    else {
      SET_GREEN;
    }
    // Backwards white
    if ((NUMPIXELS - i) % 3 == 0) {
      SET_WHITE_BACKWARDS;
    }

    // Backwards random colours
    else {
      int randR = rand() & 255;
      int randG = rand() & 255;
      int randB = rand() & 255;
      pixels.setPixelColor((NUMPIXELS - i), pixels.Color(randR, randG, randB));
    }
   pixels.show();
  }
}
