/* Teensy++ Sensor to USB Keyboard Example */

// When connecting sensors to the Teensy++, ensure to match the 
// type of sensor (analog or digital) with the right pins.
// Analog sensors: Potentiometer, Light sensor, Temperature, Humidity, etc
// Digital: Button, Accelerometer, etc
// NOTE: Analog pins are F0 to F7 on the Teensy++

// Declaring the variable t
byte sensorPin = PIN_F0;
int sensorValue;
int threshold;

void setup() {
  // After declaration, each button pin needs to be setup as an input
  pinMode(sensorPin, INPUT);
  
  // Setting a threshold value to determine sensor readings
  // See Sensor Calibration
  threshold = 500;
  
  Serial.begin(9600);
}

void loop() {
  /*********** SENSOR CALIBRATION ***************
  * To identify the desired threshold, you can print sensor readings
  * to the Serial Monitor (Tools > Serial Monitor).
  * Do this while you simulate changes to your sensor
  */
  Serial.println(analogRead(sensorPin));

  // Basic logic:
  // 1. Read the value from the sensor
  sensorValue = analogRead(sensorPin);
  
  // 2. If reading is below the threshold value, press a key
  if (sensorValue < threshold) {
    Keyboard.press(KEY_LEFT);
    Keyboard.release(KEY_LEFT);
  } 

  // 3. If reading is between the threshold and a selected value, press a different key
  if (sensorValue > threshold && sensorValue < 700){ 
    Keyboard.press(KEY_RIGHT);
    Keyboard.release(KEY_RIGHT);
  }

  // 4. If reading is above a select value, press yet another key
  if (sensorValue > threshold && sensorValue < 700){ 
    Keyboard.press(KEY_RIGHT);
    Keyboard.release(KEY_RIGHT);
  }
  
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

// For more key codes, check the link above
