
//  Sample code  Will not compile\
//   32 color paletts programing question:  How to?
//   16 color paletts work 



//  initialize
#include <Wire.h>
#include <IoAbstraction.h>
#include<TaskManagerIO.h>
#include <KeyboardManagerFG.h>

#include "FastLED.h"
FASTLED_USING_NAMESPACE
#include "colorutils.h"

#define DATA_PIN 2
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS 62
#define BRIGHTNESS 60
#define UPDATES_PER_SECOND 100 
#define FRAMES_PER_SECOND  120

int KeyFG = 0;
#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

CRGB leds[NUM_LEDS];

//  Start define Pallets
CRGBPalette16 currentPalette;
CRGBPalette32 currentPalette32;    //Added to intalize CRGBPalette32
TBlendType    currentBlending;

//  CRGBPalette16 example
extern CRGBPalette16 myRedBluePalette;
extern const TProgmemPalette16 myRedBluePalette_p PROGMEM;

extern CRGBPalette32 Ocean;
extern const TProgmemPalette32 Ocean_p PROGMEM;

//  Fill both Paletts
void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
   uint8_t brightness = 255;
//  Loads color palette(?)    
    for( int i = 0; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
}
void FillLEDsFromPaletteColors32( uint8_t colorIndex)
{
   uint8_t brightness = 255;
//  Loads color palette(?)    
    for( int i = 0; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette( currentPalette32, colorIndex, brightness, currentBlending);
        colorIndex += 1;     // Note changed to 1 to lenghthen color pixel 
    }
}

void LoopFLed()
//Works
   if(  KeyFG == 23)  //K
// predefined color palette
   { currentPalette = CloudColors_p; currentBlending = NOBLEND;
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    FillLEDsFromPaletteColors( startIndex);     
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
   }      
//custom color palette
   if(  KeyFG == 14)  //B
   { currentPalette = myRedBluePalette_p; currentBlending = NOBLEND;    //Police
    static uint8_t startIndex = 0;
    startIndex = startIndex + 2; /* motion speed */
    FillLEDsFromPaletteColors( startIndex);     
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
//    FastLED.delay(1000 / UPDATES_PER_SECOND);
   } 

  // Working 32 colorpalette
   if(  KeyFG == 24)  //L
   { currentPalette32 = Ocean_p; currentBlending = NOBLEND;
    static uint16_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    FillLEDsFromPaletteColors32( startIndex);     
      FastLED.delay(10000 / UPDATES_PER_SECOND);
        FastLED.show();
 
   }      
//   End LoopFLed  !!

//custom 16 color palette
const TProgmemPalette16 myRedBluePalette_p PROGMEM =
  {
    CRGB::Red,
    CRGB::Blue,
    CRGB::Red,
    CRGB::Blue,
    
    CRGB::Red,
    CRGB::Blue,
    CRGB::Red,
    CRGB::Blue,
    
    CRGB::Red,
    CRGB::Blue,
    CRGB::Red,
    CRGB::Blue,
 
    CRGB::Red,
    CRGB::Blue,
    CRGB::Red,
    CRGB::Blue,
 };

//custom 32 color palette
const TProgmemRGBPalette32 Ocean_p PROGMEM =
{
    CRGB::MidnightBlue,
    CRGB::DarkBlue,
    CRGB::Teal,
    CRGB::Navy,

    CRGB::DarkBlue,
    CRGB::Blue,
    CRGB::SeaGreen,
    CRGB::DarkGreen,

    CRGB::CadetBlue,
    CRGB::Blue,
    CRGB::DarkCyan,
    CRGB::OliveDrab,

    CRGB::MediumSeaGreen,
    CRGB::Aqua, 
    CRGB::SeaGreen,
    CRGB::DarkSeaGreen,
         
    CRGB::LimeGreen,
    CRGB::DarkTurquoise,
    CRGB::Aqua,
    CRGB::Blue,

    CRGB::DarkBlue,
    CRGB::MediumBlue,
    CRGB::SeaGreen,
    CRGB::Teal,

    CRGB::CadetBlue,
    CRGB::Blue,
    CRGB::DarkCyan,
    CRGB::CornflowerBlue,

    CRGB::DarkSlateBlue,
    CRGB::MediumPurple,
    CRGB::Indigo,
    CRGB::Purple,
};
