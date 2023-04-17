/*
  This example shows how to configure SAMD21 timer.
  - TC4 and TC5 are used as one 32-bit timer.
  - TC5 registers are ignored when in 32-bit mode.
  - Timer runs from the main clock.
  - Timer is read trough software.
  - Serial Plotter can be used to see the interval or COUNT value.
  
  The circuit:
  - Arduino Nano 33 IoT.

  This example code is in the public domain.
*/

#include <samd.h>

void setup()
{
  Serial.begin( 9600 );
  while ( !Serial );

  TC4Init();
}

void loop()
{
#define PRINT_INTERVAL 10

  static uint32_t previousMillis = 0;
  static uint32_t previousTC4Count = 0;

  uint32_t currentMillis = millis();
  if ( currentMillis - previousMillis >= PRINT_INTERVAL )
  {
    previousMillis = currentMillis;

    uint32_t currentTC4Count = TC4Read();
    uint32_t TC4Interval = currentTC4Count - previousTC4Count;
    previousTC4Count = currentTC4Count;
    Serial.print( TC4Interval );
//    Serial.println( currentTC4Count );
  }
}

// For register naming structs and unions see
// .\AppData\Local\Arduino15\packages\arduino\tools\CMSIS-Atmel\1.2.0\CMSIS\Device\
   ATMEL\samd21\include\component\tc.h

void TC4Init()
{
  // Enable and configure clock source for timer TC4/5
  GCLK->CLKCTRL.reg = GCLK_CLKCTRL_CLKEN | GCLK_CLKCTRL_GEN_GCLK0 | GCLK_CLKCTRL_ID_TC4_TC5;
  while ( GCLK->STATUS.bit.SYNCBUSY );

  // Reset timer registers ( just to be sure )
  TC4->COUNT32.CTRLA.bit.SWRST = 1;
  while ( TC4->COUNT32.STATUS.bit.SYNCBUSY );

  // Set mode to 32 bit
  TC4->COUNT32.CTRLA.bit.MODE = TC_CTRLA_MODE_COUNT32_Val;

  // Set prescaler
  TC4->COUNT32.CTRLA.bit.PRESCALER = TC_CTRLA_PRESCALER_DIV1024_Val;

  // Enable read synchronization of the timer COUNT register ( Offset: 0x10 )
  TC4->COUNT32.READREQ.reg = TC_READREQ_RCONT | TC_READREQ_ADDR( 0x10 );
  while ( TC4->COUNT32.STATUS.bit.SYNCBUSY );

  // Enable timer
  TC4->COUNT32.CTRLA.bit.ENABLE = 1;
  while ( TC4->COUNT32.STATUS.bit.SYNCBUSY );
}

uint32_t TC4Read()
{
  return TC4->COUNT32.COUNT.reg;
}
