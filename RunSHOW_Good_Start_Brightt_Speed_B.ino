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
#include <FastLEDPainter.h>

#include "FastLED.h"
//FASTLED_USING_NAMESPACE
#include "colorutils.h"

#define DATA_PIN 2
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS 62

//   *********   Set  Brightness & Speed    **********
#define MASTER_BRIGHTNESS 255  // Set the master brigtness value [should be greater then min_brightness value].
#define MASTER_Speed 1023       //  To be Adjusted
//#define UPDATES_PER_SECOND  100
//#define FRAMES_PER_SECOND  120

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
extern CRGBPalette16 Irish;
extern const TProgmemPalette16 Irish_p PROGMEM;

extern CRGBPalette32 Ocean;
extern const TProgmemPalette32 Ocean_p PROGMEM;
extern CRGBPalette32 FireFG;
extern const TProgmemPalette32 FireFG_p PROGMEM;

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

void FillLEDsFromPaletteColors( uint8_t colorIndex) //  Load 16 Color palette
{
//     uint8_t brightness = 255;
//        Loads color palette    
      for( int i = 0; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, MASTER_BRIGHTNESS, currentBlending);
        colorIndex += 3;
  }
}
void FillLEDsFromPaletteColors32( uint8_t colorIndex)  //  Load 32 Color palette
{
//     uint8_t brightness = 255;
//        Loads color palette(?)    
      for( int i = 0; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette( currentPalette32, colorIndex, MASTER_BRIGHTNESS, currentBlending);
        colorIndex += 1;
  }
}

// ********* Start key press funcions   *********

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
      Serial.print("Test3 "); 
}
void GreenFunctionFor4() {
 // take action when 4 typed on keypad
    KeyFG = 4;
      Serial.println(KeyFG);
      Serial.print("Test4 "); 
}
void CyanFunctionFor5() {
 // take action when 5 typed on keypad
    KeyFG = 5;
      Serial.println(KeyFG);
      Serial.print("Test5 ");  
}
void BlueFunctionFor6() {
 // take action when 6 typed on keypad
    KeyFG = 6;
      Serial.println(KeyFG);
      Serial.print("Test6 ");      
}
void PurpleFunctionFor7() {
 // take action when 7 typed on keypad
    KeyFG = 7;
      Serial.println(KeyFG);
      Serial.print("Test7 "); 
}
void MagentaFunctionFor8() {
 // take action when 8 typed on keypad
    KeyFG = 8;
      Serial.println(KeyFG);
      Serial.print("Test8 ");  
}
void WhiteFunctionFor9() {
 // take action when 9 typed on keypad
    KeyFG = 9;
      Serial.println(KeyFG);
      Serial.print("Test9 ");    
}
void Pre1FunctionForX() {
 // take action when X typed on keypad
    KeyFG = 10;
      Serial.println(KeyFG);
      Serial.print("Test10 "); 
}
void Pre2FunctionFor0() {
 // take action when 0 typed on keypad
    KeyFG = 11;
      Serial.println(KeyFG);
      Serial.print("Test11 ");     
}
void Pre3FunctionForY() {
 // take action when Y typed on keypad
    KeyFG = 12;
      Serial.println(KeyFG);
      Serial.print("Test12 ");     
}

// *******************   KeyPad  #2  *********************************
//Chases

void  ChaseForA() {
 // take action when A typed on keypad
    KeyFG = 13;
      Serial.println(KeyFG);
      Serial.print("TestA ");   
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
}
void ChaseForB() {
 // take action when B typed on keypad
  KeyFG = 14;
    Serial.println(KeyFG);
    Serial.print("TestB ");      
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
}
void ChaseForC() {
 // take action when  C typed on keypad
  KeyFG = 15;
    Serial.println(KeyFG);
    Serial.print("TestC ");      
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
}
void ChaseForD() {
 // take action when  D typed on keypad
  KeyFG = 16;
    Serial.println(KeyFG);
    Serial.print("TestD ");      
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
}
void  ChaseForE() {
 // take action when E typed on keypad
//    delay( 1000 ); // power-up safety delay
    KeyFG = 17;
    Serial.println(KeyFG);
    Serial.print("TestE ");        
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
}
void ChaseForF() {
 // take action when F typed on keypad
  KeyFG = 18;
    Serial.println(KeyFG);
    Serial.print("TestF ");      
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
}
void ChaseForG() {
 // take action when  G typed on keypad
  KeyFG = 19;
    Serial.println(KeyFG);
    Serial.print("TestG ");      
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
}
void ChaseForH() {
 // take action when  H typed on keypad
  KeyFG = 20;
    Serial.println(KeyFG);
    Serial.print("TestH ");      
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
}
void  ChaseForI() {
 // take action when I typed on keypad
  KeyFG = 21;
    Serial.println(KeyFG);
    Serial.print("TestI ");      
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
}
void ChaseForJ() {
 // take action when J typed on keypad
  KeyFG = 22;
    Serial.println(KeyFG);
    Serial.print("TestJ ");      
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
}
void ChaseForK() {
 // take action when  K typed on keypad
  KeyFG = 23;
    Serial.println(KeyFG);
    Serial.print("TestK ");      
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
}
void ChaseForL() {
 // take action when  K typed on keypad
  KeyFG = 24;
    Serial.println(KeyFG);
    Serial.print("TestL ");      
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
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
      Serial.println(KeyFG);    
           break;
      case '6':
           BlueFunctionFor6();
      Serial.println("Blue ");
      Serial.println(KeyFG);     
           break;
      case '7':
           PurpleFunctionFor7();
      Serial.println("Purple ");
      Serial.println(KeyFG);     
           break;
      case '8':
           MagentaFunctionFor8();
      Serial.println("Magenta ");
      Serial.println(KeyFG);     
           break;
      case '9':
           WhiteFunctionFor9();
      Serial.println("White ");
      Serial.println(KeyFG);     
           break;
      case 'X':
           Pre1FunctionForX();
      Serial.println("Red White Blue with Sparkles ");
      Serial.println(KeyFG);     
           break;
      case '0':
           Pre2FunctionFor0();
      Serial.println("Fire ");
      Serial.println(KeyFG);     
           break;
      case 'Y':
           Pre3FunctionForY();
      Serial.println("Irish ");
      Serial.println(KeyFG);     
           break;

// *******************   KeyPad  #2  *********************************
           
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
      Serial.println("Tape Ticker");
      Serial.println(KeyFG);    
           break; 
           
      case 'I':
           ChaseForI();
      Serial.println("Right");
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
  if(  KeyFG == 1)  { fill_solid( leds, NUM_LEDS, CRGB::Red);       goto RunSHOW; }
  if(  KeyFG == 2)  { fill_solid( leds, NUM_LEDS, CRGB::Orange);    goto RunSHOW; }    
  if(  KeyFG == 3)  { fill_solid( leds, NUM_LEDS, CRGB(0xFFFF20));  goto RunSHOW; } 
  if(  KeyFG == 4)  { fill_solid( leds, NUM_LEDS, CRGB::Green);     goto RunSHOW; }  
  if(  KeyFG == 5)  { fill_solid( leds, NUM_LEDS, CRGB::Cyan);      goto RunSHOW; } 
  if(  KeyFG == 6)  { fill_solid( leds, NUM_LEDS, CRGB::Blue);      goto RunSHOW; } 
  if(  KeyFG == 7)  { fill_solid( leds, NUM_LEDS, CRGB::Purple);    goto RunSHOW; } 
  if(  KeyFG == 8)  { fill_solid( leds, NUM_LEDS, CRGB(0xFF1040));  goto RunSHOW; } 
  if(  KeyFG == 9)  { fill_solid( leds, NUM_LEDS, CRGB::White);     goto RunSHOW; } 
  
//Presets
  if(  KeyFG == 10)  
{  
currentPalette = RWB_p; currentBlending = NOBLEND;
  static uint8_t startIndex = 0;
//   startIndex = startIndex + 1; /* motion speed */  //Remove Chase
  FillLEDsFromPaletteColors( startIndex);
     { if( random8() < 120)    //Good Amount of sparkles       
  leds[ random16(NUM_LEDS) ] += CRGB::White;} 
     { if( random8() < 120)
  leds[ random16(NUM_LEDS) ] += CRGB::White;}  
  goto RunSHOW;    

}    
  if(  KeyFG == 11)  
 { currentPalette32 = FireFG_p; currentBlending = LINEARBLEND;
  static uint16_t startIndex = 0;
  startIndex = startIndex + 1; /* motion speed */
  FillLEDsFromPaletteColors32( startIndex);     

     { if( random8() < 120)    //Good Amount of sparkles       
  leds[ random16(NUM_LEDS) ] += CRGB::White;}
  goto RunSHOW;     

}
  if(  KeyFG == 12)   
{  
currentPalette = Irish_p; currentBlending = NOBLEND;
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; /* motion speed */ 
  FillLEDsFromPaletteColors( startIndex);
  goto RunSHOW;
}  

// *******************   KeyPad  #2  *********************************

//  Chase Functions
 if(  KeyFG == 13)  //A
 { currentPalette = RainbowColors_p; currentBlending = LINEARBLEND;
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; /* motion speed */
  FillLEDsFromPaletteColors( startIndex);  
  goto RunSHOW;   
}
 if(  KeyFG == 14)  //B
 { currentPalette = myRedBluePalette_p; currentBlending = NOBLEND;    //Police
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; /* motion speed */
  FillLEDsFromPaletteColors( startIndex);     
  goto RunSHOW;
 } 
   if(  KeyFG == 15)  //C
 { currentPalette = ForestColors_p; currentBlending = LINEARBLEND;
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; /* motion speed */
  FillLEDsFromPaletteColors( startIndex);
  goto RunSHOW;     
 }   
  if(  KeyFG == 16)  //D
 { currentPalette = FOGRedWhiteBlue_p; currentBlending = NOBLEND;
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; /* motion speed */
  FillLEDsFromPaletteColors( startIndex);
  goto RunSHOW;     
 }  
//   Different Functions   
 if(  KeyFG == 17)  //E  Gilter Rainbow
{ static uint8_t gHue = 0;
   gHue = gHue + 2; /* motion speed */
 // Call the current pattern function once, updating the 'leds' array
 fill_rainbow( leds, NUM_LEDS, gHue, 4); //4 is a good Size(LEDs+=0)
     { if( random8() < 120)    //Good Amount of sparkles       
  leds[ random16(NUM_LEDS) ] += CRGB::White;} 
     { if( random8() < 120)
  leds[ random16(NUM_LEDS) ] += CRGB::White;}
  goto RunSHOW;
 // send the 'leds' array out to the actual LED strip
 }
 if(  KeyFG == 18)  //F
// random colored speckles that blink in and fade smoothly  Popcorn 
 { static uint8_t gHue = 0;
   gHue = gHue + 1; /* motion speed */
 // Call the current pattern function once, updating the 'leds' array
  fadeToBlackBy( leds, NUM_LEDS, 10);  //(good fade #)
     int pos = random8(NUM_LEDS);
     leds[pos] += CHSV( gHue + random8(255), 255, 255); 
     int pos2 = random8(NUM_LEDS);
     leds[pos2] += CHSV( gHue + random8(255), 255, 255); // Good 2*Times the dots
     goto RunSHOW;
 } 
  if(  KeyFG == 19)  //G  Good but simliar to H 
// a colored dot sweeping back and forth, with fading trails
 { static uint8_t gHue = 0;
   gHue = gHue + 1; /* motion speed */
 // Call the current pattern function once, updating the 'leds' array
    fadeToBlackBy( leds, NUM_LEDS, 20);
    int pos = beatsin16( 6, 0, NUM_LEDS-1 ); // 6 is Good
    leds[pos] += CHSV( gHue, random8(255), 255); 
    goto RunSHOW;  
 } 
   
  if(  KeyFG == 20) //H
//  Spew  Tape Ticker   Good Tweaked all parameters!!
{   static uint8_t gHue = 0;
  gHue = gHue - 30; /* motion speed */
const uint16_t spewSpeed = 200;  // rate of advance
static boolean spewing = 0;  // pixels are On(1) or Off(0)
static uint8_t count = 1;  // how many to light (or not light)
static uint8_t temp = count;
static uint8_t hue = random8();

EVERY_N_MILLISECONDS(spewSpeed){
  
  if (count == 0) {
    spewing = !spewing;
    if (spewing == 1) { count = random8(1,9); }  // random number for On pixels
    else { count = random8(2,4); }  // random number for Off pixels
    temp = count;
    hue = random8();
  }  
     for (uint8_t i = NUM_LEDS-1; i > 0; i--) {
      leds[i] = leds[i-1];  // shift data down the line by one pixel
  }
  if (spewing == 1) {  // new pixels are On
      if (temp == count) {
      leds[0] = CHSV(hue-5, 215, 255);  // for first dot
      leds[1] = CHSV(hue-5, 215, 255);  // for second dot
      leds[2] = CHSV(hue-5, 215, 255);  // for third dot        
      leds[3] = CHSV(hue-5, 215, 255);  // for forth dot        
      leds[4] = CHSV(hue-5, 215, 255);  // for fifth dot
    } else {
      leds[0] = CHSV(hue, 255, 255/(1+((temp-count)*2)) );  // for following dots
          
    }
  } else {  // new pixels are Off
    leds[0] = CHSV(0,0,0);  // set pixel 0 to black
   // leds[1] = CHSV(0,0,0);  // set pixel 1 to black
   // leds[2] = CHSV(0,0,0);  // set pixel 2 to black
   // leds[3] = CHSV(0,0,0);  // set pixel 3 to black
  }
 
  count = count - 1;  // reduce count by one.
}//end every_n
    goto RunSHOW;
//  End Tape Ticker    
} 
    
  if(  KeyFG == 21)  //I   RIGHT
 { currentPalette =  RainbowStripeColors_p; currentBlending = NOBLEND;
  static uint8_t startIndex = 0;
  startIndex = startIndex - 1; /* motion speed */
  FillLEDsFromPaletteColors( startIndex);  
  goto RunSHOW;   
 }   
 if(  KeyFG == 22)  //J   LEFT
 { currentPalette =  RainbowStripeColors_p; currentBlending = NOBLEND;
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; /* motion speed */
  FillLEDsFromPaletteColors( startIndex);   
  goto RunSHOW;  
 }      
 if(  KeyFG == 23)  //K
 { currentPalette = CloudColors_p; currentBlending = LINEARBLEND;
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; /* motion speed */
  FillLEDsFromPaletteColors( startIndex);  
  goto RunSHOW;   
 }      
 if(  KeyFG == 24)  //L
 { currentPalette32 = Ocean_p; currentBlending = LINEARBLEND;
  static uint16_t startIndex = 0;
  startIndex = startIndex + 1; /* motion speed */
  FillLEDsFromPaletteColors32( startIndex); 
  goto RunSHOW;    

//   **************   Test FastLED.show();   **************


RunSHOW:
//  **********  Brightness Control      **********
    uint16_t min_brightness = 1;   // Set a minimum brightness level.
    uint16_t brightness;            // Mapped master brightness based on potentiometer reading.
    int potPinA = A0;   // Pin for potentiometer B (for brightness) 
    int potValA;        // Variable to store potentiometer B value (for brightness)
      FastLED.setBrightness(MASTER_BRIGHTNESS);
      pinMode(potPinA, INPUT);  // Set pin as an input. 
        potValA = analogRead(potPinA);  // Read potentiometer B (for brightness).
        brightness = map(potValA, 0, 1023, min_brightness, MASTER_BRIGHTNESS);
      FastLED.setBrightness(brightness);  // Set master brightness based on potentiometer position.
      //  Serial.println(brightness); 

// *********    END Brightness Control ***********   
    
// *********            SPEED          ***********

    uint16_t min_RUNSpeed = 1;   // Set a minimum speed level.
    uint16_t RUNSpeed = 200;  // rate of advance
    uint16_t SpeedRate;
    int potPinB = A1;   // Pin for potentiometer B (Speed)
    int potValB;        // Variable to store potentiometer  value (Speed)
        pinMode(potPinB, INPUT);  // Set pin as an input.
        potValB = analogRead(potPinB);  // Read potentiometer B (for Speed).
        SpeedRate = map(potValB, 1, 1023, min_RUNSpeed, MASTER_Speed);
       
        //  Serial.println(SpeedRate );

                   
EVERY_N_MILLISECONDS(SpeedRate){
 
    FastLED.show();   

}//end every_n 

}  

//  END KEY Functions ********************************   


   
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

//   Start UP FastLed  Set to Black
  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  MASTER_BRIGHTNESS );
  fill_solid( leds, NUM_LEDS, CRGB::Black); FastLED.show(); 

//   Setup Faders
//   pinMode(FSpeed, INPUT);
//   FastLED.setBrightness(MASTER_BRIGHTNESS);
    
uint8_t taskId = taskManager.scheduleFixedRate(100, LoopFLed);;


}

void loop() {
  // as this indirectly uses taskmanager, we must include this in loop.
  taskManager.runLoop();


}

const TProgmemRGBPalette16 myRedBluePalette_p PROGMEM =
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
const TProgmemRGBPalette16 RWB_p  PROGMEM =
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

const TProgmemRGBPalette16 Irish_p PROGMEM =
{
  CRGB::Green,
  CRGB::Green,
  CRGB::DarkOrange,
  CRGB::Green,

  CRGB::Green,
  CRGB::Green,
  CRGB::DarkOrange,
  CRGB::Green,
  
  CRGB::Green,
  CRGB::Green,
  CRGB::DarkOrange,
  CRGB::Green,
  
  CRGB::Green,
  CRGB::Green,
  CRGB::DarkOrange,
  CRGB::Green,
};

const TProgmemRGBPalette32 FireFG_p FL_PROGMEM =
{
 0xB22222, //FireBrick
 CRGB::Maroon,
 CRGB::Crimson,
 CRGB::OrangeRed,
  
 CRGB::DarkRed,
 0xFF0040, //  Carmine
 CRGB::DarkRed,
 CRGB::DarkOrange,
 
 CRGB::Tomato,
 CRGB::DarkRed,
 CRGB::Red,
 CRGB::Orange,
 
 CRGB::White,
 CRGB::Yellow,
 CRGB::Gold,
 CRGB::DarkRed,
 
 CRGB::OrangeRed,
 0xFF0040, //  Carmine
 CRGB::Black,
 CRGB::Red,
  
 CRGB::DarkRed,
 CRGB::Gold,
 0xB22222, //FireBrick
 CRGB::Red,
 
 CRGB::DarkRed,
 CRGB::DarkOrange,
 CRGB::OrangeRed,
 CRGB::Orange,
 
 CRGB::White,
 CRGB::Orange,
 CRGB::Red,
 CRGB::DarkRed,
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
  CRGB::DarkSlateBlue,

  CRGB::Violet,
  CRGB::MediumPurple,
  CRGB::Indigo,
  CRGB::Purple,

};
