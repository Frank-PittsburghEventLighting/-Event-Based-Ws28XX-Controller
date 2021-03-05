
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
TBlendType    currentBlending;


extern CRGBPalette16 myRedBluePalette;
extern const TProgmemPalette16 myRedBluePalette_p PROGMEM;

extern CRGBPalette16 RWBPalette;
extern const TProgmemPalette16 RWB_p PROGMEM;
//  note function CRGBPalette32 not recognized
extern CRGBPalette32 Ocean;
extern const TProgmemPalette32 Ocean_p PROGMEM;

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

  // Does not work?
   if(  KeyFG == 24)  //L
   { currentPalette = Ocean_p; currentBlending = NOBLEND;
    static uint32_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    FillLEDsFromPaletteColors( startIndex);     
    FastLED.show();
   FastLED.delay(1000 / UPDATES_PER_SECOND);
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

//custom 16 color palette
const TProgmemRGBPalette32 Ocean_p PROGMEM =
{
    CRGB::MidnightBlue,
    CRGB::DarkBlue,
    CRGB::Green,
    CRGB::Navy,

    CRGB::DarkBlue,
    CRGB::MediumBlue,
    CRGB::SeaGreen,
    CRGB::Teal,

    CRGB::CadetBlue,
    CRGB::Blue,
    CRGB::DarkCyan,
    CRGB::CornflowerBlue,

    CRGB::Aquamarine,
    CRGB::SeaGreen,
    CRGB::Aqua,
    CRGB::LightSkyBlue
     
    CRGB::MidnightBlue,
    CRGB::DarkBlue,
    CRGB::Green,
    CRGB::Navy,

    CRGB::DarkBlue,
    CRGB::MediumBlue,
    CRGB::SeaGreen,
    CRGB::Teal,

    CRGB::CadetBlue,
    CRGB::Blue,
    CRGB::DarkCyan,
    CRGB::CornflowerBlue,

    CRGB::Aquamarine,
    CRGB::SeaGreen,
    CRGB::Aqua,
    CRGB::LightSkyBlue
};
