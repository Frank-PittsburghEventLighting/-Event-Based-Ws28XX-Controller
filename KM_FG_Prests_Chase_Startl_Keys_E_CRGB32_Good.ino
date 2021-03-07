//
//  24 keys with presets and chases Tasks are handled with TaskManager software #include <TaskManagerIO.h> https://www.thecoderscorner.com/products/arduino-libraries/taskmanager-io/task-manager-scheduling-guide/
//
//  Keys are responsive with little latency Events are working smoothly presets and chases are working but will be improved overtime (My OCD)
//
//  Next step is to incorporate four faders 4 controlling RGB and chase speed.
//
//  initialize
#include <Wire.h>
#include <IoAbstraction.h>
#include<TaskManagerIO.h>
#include <KeyboardManagerFG.h>

#include "FastLED.h"
FASTLED_USING_NAMESPACE
//#include "colorutils.h"

#define DATA_PIN 2
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS 62
#define BRIGHTNESS 60
#define UPDATES_PER_SECOND  100
#define FRAMES_PER_SECOND  120

int KeyFG = 0;
#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

CRGB leds[NUM_LEDS];

//  Start define Pallets
CRGBPalette16 currentPalette;
CRGBPalette32 currentPalette32;
TBlendType    currentBlending;


extern CRGBPalette16 myRedBluePalette;
extern const TProgmemPalette16 myRedBluePalette_p PROGMEM;

extern CRGBPalette16 RWBPalette;
extern const TProgmemPalette16 RWB_p PROGMEM;

extern CRGBPalette32 Ocean;
extern const TProgmemPalette32 Ocean_p PROGMEM;


//
// We need to make a keyboard layout that the manager can use. choose one of the below.
// The parameter in brackets is the variable name.
//
//MAKE_KEYBOARD_LAYOUT_3X4(keyLayout)
//MAKE_KEYBOARD_LAYOUT_4X4(keyLayout)
MAKE_KEYBOARD_LAYOUT_3X8(keyLayout)


//
// We need a keyboard manager class too
//
MatrixKeyboardManager keyboard;

// this examples connects the pins directly to an arduino but you could use
// IoExpanders or shift registers instead.
IoAbstractionRef arduinoIo = ioUsingArduino();

//  Functions for LEDS  Fastlight and Neopixel

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
        colorIndex += 1;
    }
}

//  Start key press funcions

void RedFunctionFor1() {
   // take action when 1 typed on keypad
    KeyFG = 1;
      Serial.println(KeyFG);
      Serial.print("Test ");
}   
void OrangeFunctionFor2() {
   // take action when 2 typed on keypad
      KeyFG = 2;
        Serial.println(KeyFG);
        Serial.print("Test2 ");
}
void YellowFunctionFor3() {
   // take action when 3 typed on keypad
      KeyFG = 3;
        Serial.println(KeyFG);
        Serial.print("Test "); 
}
void GreenFunctionFor4() {
   // take action when 4 typed on keypad
      KeyFG = 4;
        Serial.println(KeyFG);
        Serial.print("Test "); 
}
void CyanFunctionFor5() {
   // take action when 5 typed on keypad
      KeyFG = 5;
        Serial.println(KeyFG);
        Serial.print("Test ");  
}
void BlueFunctionFor6() {
   // take action when 6 typed on keypad
      KeyFG = 6;
        Serial.println(KeyFG);
        Serial.print("Test ");      
}
void PurpleFunctionFor7() {
   // take action when 7 typed on keypad
      KeyFG = 7;
        Serial.println(KeyFG);
        Serial.print("Test "); 
}
void MagentaFunctionFor8() {
   // take action when 8 typed on keypad
      KeyFG = 8;
        Serial.println(KeyFG);
        Serial.print("Test ");  
}
void WhiteFunctionFor9() {
   // take action when 9 typed on keypad
      KeyFG = 9;
        Serial.println(KeyFG);
        Serial.print("Test ");    
}
void Pre1FunctionForX() {
   // take action when X typed on keypad
      KeyFG = 10;
        Serial.println(KeyFG);
        Serial.print("Test "); 
}
void Pre2FunctionFor0() {
   // take action when 0 typed on keypad
      KeyFG = 11;
        Serial.println(KeyFG);
        Serial.print("Test ");     
}
void Pre3FunctionForY() {
   // take action when Y typed on keypad
      KeyFG = 12;
        Serial.println(KeyFG);
        Serial.print("Test ");     
}
//Chases

void  ChaseForA() {
   // take action when A typed on keypad
//    delay( 1000 ); // power-up safety delay
      KeyFG = 13;
    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
}
void ChaseForB() {
   // take action when B typed on keypad
    KeyFG = 14;
    delay( 1000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
}
void ChaseForC() {
   // take action when  C typed on keypad
    KeyFG = 15;
    delay( 1000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
}
void ChaseForD() {
   // take action when  D typed on keypad
    KeyFG = 16;
    delay( 1000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );  
}
void  ChaseForE() {
   // take action when E typed on keypad
//    delay( 1000 ); // power-up safety delay
      KeyFG = 17;
    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
}
void ChaseForF() {
   // take action when F typed on keypad
    KeyFG = 18;
    delay( 1000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
}
void ChaseForG() {
   // take action when  G typed on keypad
    KeyFG = 19;
    delay( 1000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
}
void ChaseForH() {
   // take action when  H typed on keypad
    KeyFG = 20;
    delay( 1000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );  
}
void  ChaseForI() {
   // take action when I typed on keypad
    KeyFG = 21;
    delay( 1000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
}
void ChaseForJ() {
   // take action when J typed on keypad
    KeyFG = 22;
    delay( 1000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
}
void ChaseForK() {
   // take action when  K typed on keypad
    KeyFG = 23;
    delay( 1000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
}
void ChaseForL() {
   // take action when  L typed on keypad
    KeyFG = 24;
    delay( 1000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );  
}
//  End Key Functions
//
// We need a class that extends from KeyboardListener. this gets notified when
// there are changes in the keyboard state.
//
class MyKeyboardListener : public KeyboardListener {
public:
    void keyPressed(char key, bool held) override {
//  Testing key presses       
        Serial.print("Key ");
        Serial.print(key);
        Serial.print(" is pressed, held = ");
        Serial.println(held);
//Start switch case for key press
//
    switch(key) {
        case '1':
            RedFunctionFor1();
        Serial.println("Red ");      
        Serial.println(KeyFG);
            break;
            
        case '2':
            OrangeFunctionFor2();
        Serial.println("Orange ");
        Serial.println(KeyFG);
             break;
        
        case '3':
             YellowFunctionFor3();
        Serial.println("Yellow ");
        Serial.println(KeyFG);    
             break;       

        case '4':
             GreenFunctionFor4();
        Serial.println("Green ");
        Serial.println(KeyFG);     
             break;
        case '5':
             CyanFunctionFor5();
        Serial.println("Cyan ");
             
             break;
        case '6':
             BlueFunctionFor6();
        Serial.println("Blue ");
             
             break;
        case '7':
             PurpleFunctionFor7();
        Serial.println("Purple ");
             
             break;
        case '8':
             MagentaFunctionFor8();
        Serial.println("Magenta ");
             
             break;
        case '9':
             WhiteFunctionFor9();
        Serial.println("White ");
             
             break;
        case 'X':
             Pre1FunctionForX();
        Serial.println("Red White Blue with Sparkles ");
             
             break;
        case '0':
             Pre2FunctionFor0();
        Serial.println("Lava ");
             
             break;
        case 'Y':
             Pre3FunctionForY();
        Serial.println("Preset 3 ");
             
             break;
        case 'A':
             ChaseForA();
        Serial.println("Rainbow ");
        Serial.println(KeyFG);      
             break;             
        case 'B':
             ChaseForB();
        Serial.println("Police ");
        Serial.println(KeyFG);     
             break;             
                        
        case 'C':
             ChaseForC();
        Serial.println("Forest ");
        Serial.println(KeyFG);    
             break; 
                  
        case 'D':
             ChaseForD();
        Serial.println("Patriot ");
        Serial.println(KeyFG);    
             break; 
                         
        case 'E':
             ChaseForE();
        Serial.println("Gliter Rainbow ");
        Serial.println(KeyFG);    
             break;
              
         case 'F':
             ChaseForF();
        Serial.println("Popcorn");
        Serial.println(KeyFG);      
             break;             
        
        case 'G':
             ChaseForG();
        Serial.println("Back and Forth ");
        Serial.println(KeyFG);     
             break;             
                        
        case 'H':
             ChaseForH();
        Serial.println("Ramdom Blinks ");
        Serial.println(KeyFG);    
             break; 
             
        case 'I':
             ChaseForI();
        Serial.println("?????");
        Serial.println(KeyFG);    
             break; 
                     
        case 'J':
             ChaseForJ();
        Serial.println("Left ");
        Serial.println(KeyFG);     
             break;             
                        
        case 'K':
             ChaseForK();
        Serial.println("Clouds ");
        Serial.println(KeyFG);    
             break; 
             
        case 'L':
             ChaseForL();
        Serial.println("Ocean ");
        Serial.println(KeyFG);    
             break;      
        }
    }

 void keyReleased(char key) override {   } 
} myListener;

 
// Fastled show loop
void LoopFLed(){
//   Preset Fills   
    if(  KeyFG == 1)  { fill_solid( leds, NUM_LEDS, CRGB::Red); FastLED.show();     }
    if(  KeyFG == 2)  { fill_solid( leds, NUM_LEDS, CRGB::Orange); FastLED.show();  }
    if(  KeyFG == 3)  { fill_solid( leds, NUM_LEDS, CRGB(0xFFFF20)); FastLED.show();      } 
    if(  KeyFG == 4)  { fill_solid( leds, NUM_LEDS, CRGB::Green); FastLED.show();   }
    if(  KeyFG == 5)  { fill_solid( leds, NUM_LEDS, CRGB::Cyan); FastLED.show();    }
    if(  KeyFG == 6)  { fill_solid( leds, NUM_LEDS, CRGB::Blue); FastLED.show();   }
    if(  KeyFG == 7)  { fill_solid( leds, NUM_LEDS, CRGB::Purple); FastLED.show();   }
    if(  KeyFG == 8)  { fill_solid( leds, NUM_LEDS, CRGB(0xFF1040)); FastLED.show();   }
    if(  KeyFG == 9)  { fill_solid( leds, NUM_LEDS, CRGB::White); FastLED.show();   }
    if(  KeyFG == 10)  
{  
  currentPalette = RWB_p; currentBlending = NOBLEND;
    static uint8_t startIndex = 0;
 //   startIndex = startIndex + 2; /* motion speed */  //Remove Chase
    FillLEDsFromPaletteColors( startIndex);
       { if( random8() < 120)    //Good Amount of sparkles       
    leds[ random16(NUM_LEDS) ] += CRGB::White;} 
       { if( random8() < 120)
    leds[ random16(NUM_LEDS) ] += CRGB::White;}      
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);   
}    
    if(  KeyFG == 11)  
{   currentPalette = LavaColors_p; currentBlending = NOBLEND;
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    FillLEDsFromPaletteColors( startIndex);     
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
}
    if(  KeyFG == 12)   
{ 
   static uint8_t gHue = 0;
   gHue = gHue + 2; /* motion speed */
   // Call the current pattern function once, updating the 'leds' array
   fill_rainbow( leds, NUM_LEDS, gHue, 14); 
   { if( random8() < 80)
    leds[ random16(NUM_LEDS) ] += CRGB::White;}
   // send the 'leds' array out to the actual LED strip
   FastLED.show();
   FastLED.delay(1000 / UPDATES_PER_SECOND);      
 }

//  Chase Functions
   if(  KeyFG == 13)  //A
   { currentPalette = RainbowColors_p; currentBlending = NOBLEND;
    static uint8_t startIndex = 0;
    startIndex = startIndex + 2; /* motion speed */
    FillLEDsFromPaletteColors( startIndex);     
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
//    FastLED.delay(1000 / UPDATES_PER_SECOND);
   }
   if(  KeyFG == 14)  //B
   { currentPalette = myRedBluePalette_p; currentBlending = NOBLEND;    //Police
    static uint8_t startIndex = 0;
    startIndex = startIndex + 2; /* motion speed */
    FillLEDsFromPaletteColors( startIndex);     
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
//    FastLED.delay(1000 / UPDATES_PER_SECOND);
   } 
     if(  KeyFG == 15)  //C
   { currentPalette = ForestColors_p; currentBlending = NOBLEND;
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    FillLEDsFromPaletteColors( startIndex);     
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
//    FastLED.delay(1000 / UPDATES_PER_SECOND);
   }   
    if(  KeyFG == 16)  //D
   { currentPalette = FOGRedWhiteBlue_p; currentBlending = NOBLEND;
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    FillLEDsFromPaletteColors( startIndex);     
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
//    FastLED.delay(1000 / UPDATES_PER_SECOND);
   }  
//   Different Functions   
   if(  KeyFG == 17)  //E
  { static uint8_t gHue = 0;
     gHue = gHue + 2; /* motion speed */
   // Call the current pattern function once, updating the 'leds' array
   fill_rainbow( leds, NUM_LEDS, gHue, 4); //4 is a good Size
       { if( random8() < 120)    //Good Amount of sparkles       
    leds[ random16(NUM_LEDS) ] += CRGB::White;} 
       { if( random8() < 120)
    leds[ random16(NUM_LEDS) ] += CRGB::White;}
   // send the 'leds' array out to the actual LED strip
   FastLED.show(); 
   FastLED.delay(1000 / UPDATES_PER_SECOND);     
   }
   if(  KeyFG == 18)  //F
 // random colored speckles that blink in and fade smoothly  Popcorn 
   { static uint8_t gHue = 0;
     gHue = gHue + 4; /* motion speed */
   // Call the current pattern function once, updating the 'leds' array
    fadeToBlackBy( leds, NUM_LEDS, 10);
       int pos = random16(NUM_LEDS);
       leds[pos] += CHSV( gHue + random8(200), 200, 255); 
        { if( random8() < 180)    //Good Amount of sparkles       
    leds[ random16(NUM_LEDS) ] += CRGB::White;}    
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
   } 
    if(  KeyFG == 19)  //G
  // a colored dot sweeping back and forth, with fading trails
   { static uint8_t gHue = 0;
     gHue = gHue + 2; /* motion speed */
   // Call the current pattern function once, updating the 'leds' array
      fadeToBlackBy( leds, NUM_LEDS, 40);
      int pos = beatsin16( 13, 0, NUM_LEDS-1 );
      leds[pos] += CHSV( gHue, 255, 192);   
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
   }   
    if(  KeyFG == 20) //H
 // eight colored dots, weaving in and out of sync with each other 
   { static uint8_t gHue = 0;
     gHue = gHue + 1; /* motion speed */
   // Call the current pattern function once, updating the 'leds' array
  fadeToBlackBy( leds, NUM_LEDS, 20);
  byte dothue = 0;
  for( int i = 0; i < 8; i++) {
    leds[beatsin16( i+7, 0, NUM_LEDS-1 )] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }  
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
   }    
    if(  KeyFG == 21)  //I
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)    
   { static uint8_t gHue = 0;
     gHue = gHue + 1; /* motion speed */
   // Call the current pattern function once, updating the 'leds' array
  uint8_t BeatsPerMinute = 60;
  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
  for( int i = 0; i < NUM_LEDS; i++) { //9948
    leds[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
  }  
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
   } 
   if(  KeyFG == 22)  //J
   { currentPalette =  RainbowStripeColors_p; currentBlending = NOBLEND;
    static uint8_t startIndex = 0;
    startIndex = startIndex + 2; /* motion speed */
    FillLEDsFromPaletteColors( startIndex);     
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
   }      
   if(  KeyFG == 23)  //K
   { currentPalette = CloudColors_p; currentBlending = NOBLEND;
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    FillLEDsFromPaletteColors( startIndex);     
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
   }      
   if(  KeyFG == 24)  //L
   { currentPalette32 = Ocean_p; currentBlending = LINEARBLEND;
    static uint16_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    FillLEDsFromPaletteColors32( startIndex);     
      FastLED.delay(10000 / UPDATES_PER_SECOND);
        FastLED.show();
 
   }        
//   End LoopFLed  !!
}
//   End LoopFLed  !!

void setup() {
    while(!Serial);
    Serial.begin(115200);

    keyLayout.setRowPin(0, 10);
    keyLayout.setRowPin(1, 9);
    keyLayout.setRowPin(2, 8);
    keyLayout.setRowPin(3, 7);
    keyLayout.setRowPin(4, 6);
    keyLayout.setRowPin(5, 5);
    keyLayout.setRowPin(6, 4);
    keyLayout.setRowPin(7, 3);
    
    keyLayout.setColPin(0, 13);
    keyLayout.setColPin(1, 12);
    keyLayout.setColPin(2, 11);

    // create the keyboard mapped to arduino pins and with the layout chosen above.
    // it will callback our listener
    keyboard.initialise(arduinoIo, &keyLayout, &myListener);

    // start repeating at 850 millis then repeat every 350ms
    keyboard.setRepeatKeyMillis(850, 350);

    Serial.println("Keyboard is initialised!");

//   Setup FastLed loading palettes   
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
    fill_solid( leds, NUM_LEDS, CRGB::Black); FastLED.show(); 
//    currentPalette = RainbowColors_p;
//    currentBlending = LINEARBLEND;

uint8_t taskId = taskManager.scheduleFixedRate(100, LoopFLed);;


}

void loop() {
    // as this indirectly uses taskmanager, we must include this in loop.
    taskManager.runLoop();

  
}

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

/// FOG test Palettel16load
const TProgmemPalette16 RWB_p  PROGMEM =
  {
    CRGB::Blue,
    CRGB::Red, 
    CRGB::White,
    CRGB::Blue,
    
    CRGB::Red,
    CRGB::White,
    CRGB::Blue,
    CRGB::Red,
    
    CRGB::White,
    CRGB::Blue,
    CRGB::Red,
    CRGB::White,

    CRGB::Red,
    CRGB::Red,
    CRGB::White,
    CRGB::Blue,
 };
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



 
