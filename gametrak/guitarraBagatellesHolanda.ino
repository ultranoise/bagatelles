/* Complete USB Joystick Example
   Teensy becomes a USB joystick with 16 or 32 buttons and 6 axis input

   You must select Joystick from the "Tools > USB Type" menu

   Pushbuttons should be connected between the digital pins and ground.
   Potentiometers should be connected to analog inputs 0 to 5.

   This example code is in the public domain.
*/

// Configure the number of buttons.  Be careful not
// to use a pin for both a digital button and analog
// axis.  The pullup resistor will interfere with
// the analog voltage.
const int numButtons = 3;  // 16 for Teensy, 32 for Teensy++

void setup() {
  // you can print to the serial monitor while the joystick is active!
  Serial.begin(115200);
  // configure the joystick to manual send mode.  This gives precise
  // control over when the computer receives updates, but it does
  // require you to manually call Joystick.send_now().
  Joystick.useManualSend(true);
  for (int i=0; i<numButtons; i++) {
    pinMode(i, INPUT_PULLUP);
  }
  
  pinMode(4, OUTPUT);
  pinMode(13,OUTPUT);

}

byte allButtons[numButtons];
byte prevButtons[numButtons];
int angle=0;

void loop() {
  
  //LED color
  digitalWrite(4,HIGH);
  
  // read 6 analog inputs and use them for the joystick axis
  Joystick.X(analogRead(0));
  Joystick.Y(analogRead(1));
  Joystick.Z(analogRead(2));
  Joystick.Zrotate(analogRead(4));
  Joystick.sliderLeft(analogRead(5));
  Joystick.sliderRight(analogRead(6));
  
  // read digital pins and use them for the buttons
  for (int i=0; i<numButtons; i++) {
    if (digitalRead(i)) {
      // when a pin reads high, the button is not pressed
      // the pullup resistor creates the "on" signal
      allButtons[i] = 0;
    } else {
      // when a pin reads low, the button is connecting to ground.
      allButtons[i] = 1;
      if(i==2) {
        digitalWrite(13,HIGH);
      }
    }
    Joystick.button(i + 1, allButtons[i]);
  }

  
  // Because setup configured the Joystick manual send,
  // the computer does not see any of the changes yet.
  // This send_now() transmits everything all at once.
  Joystick.send_now();
  
  // check to see if any button changed since last time
  boolean anyChange = false;
  for (int i=0; i<numButtons; i++) {
    if (allButtons[i] != prevButtons[i]) anyChange = true;
    prevButtons[i] = allButtons[i];
  }
  
  // a brief delay, so this runs "only" 200 times per second
  delay(1);
}

