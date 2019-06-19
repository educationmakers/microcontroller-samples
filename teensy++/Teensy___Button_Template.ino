/* Teensy++ Buttons to USB Keyboard Example */

#include <Bounce.h>

// This is the format for a button variable declaration
// Bounce(<pin number>, <time interval in ms, 10 is the default>)  
Bounce buttonUP = Bounce(PIN_D0, 10);
Bounce buttonDOWN = Bounce(PIN_D1, 10);
Bounce buttonLEFT = Bounce(PIN_D2, 10);
Bounce buttonRIGHT = Bounce(PIN_D3, 10);

void setup() {
  // After declaration, each button pin needs to be setup as an input
  pinMode(PIN_D0, INPUT_PULLUP);
  pinMode(PIN_D1, INPUT_PULLUP);
  pinMode(PIN_D2, INPUT_PULLUP);
  pinMode(PIN_D3, INPUT_PULLUP);
}

void loop() {
  // Always refresh the state of each button
  buttonUP.update();
  buttonDOWN.update();
  buttonLEFT.update();
  buttonRIGHT.update();

  // The pushbuttons connect Ground (0V) to each selected pin.
  // Since each pin is internally connected to 5V, when the button
  // is pressed, the pin reads a falling edge (HIGH to LOW, 5V to 0V)
 
  // fallingEdge() returns true is a falling edge is detected on a given button
  if (buttonUP.fallingEdge()) {
    // Similar to a real-world usage of a keyboard, you press a key
    Keyboard.press(KEY_UP);

    // And immediately after, you release it
    Keyboard.release(KEY_UP);
  }

  if (buttonDOWN.fallingEdge()) {
    Keyboard.press(KEY_DOWN);
    Keyboard.release(KEY_DOWN);
  }

  if (buttonLEFT.fallingEdge()) {
    Keyboard.press(KEY_LEFT);
    Keyboard.release(KEY_LEFT);
  }

  if (buttonRIGHT.fallingEdge()) {
    Keyboard.press(KEY_RIGHT);
    Keyboard.release(KEY_RIGHT);
  }
  
  /* 
   *  When released, the pin reads a rising edge (LOW to HIGH, 0V to 5V)
   *  NOTE: You don't have to use both states.
   *  Normally, a falling edge (button press) is all you need. 
   *  In case you need this functionality, uncomment the code below
   *  
   *  risingEdge() returns true if a rising edge is detected on a given button
  */
  /* if (button0.risingEdge()) {
    // Similar to a real-world usage of a keyboard, you press a key
    Keyboard.press(KEY_UP);

    // And immediately after, you release it
    Keyboard.release(KEY_UP);
  } */

  
} /* End of program */


/******* SUPPLEMENTAL INFORMATION ********/
// You can also send a combination of keyboard strokes
// rather than individual key press/release
// Keyboard.println("Message here");


// List of key codes - From https://www.pjrc.com/teensy/td_keyboard.html
//  A = KEY_A
//  B = KEY_B
//  ...
//  Z = KEY_Z
//  1 = KEY_1
//  ...
//  9 = KEY_9
//  UP = KEY_UP
//  DOWN = KEY_DOWN
//  LEFT = KEY_LEFT
//  RIGHT = KEY_RIGHT

// For more key codes, check the link
