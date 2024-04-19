/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

// the setup function runs once when you press reset or power the board

int pinButton = 8;
int i = 0;
const String morseCode[] = {"_..", "..", "_.", ".._", "._..", ".."};

void setup(){
  pinMode(13, OUTPUT);
  pinMode(pinButton, INPUT);
}

void loop(){
  
  //for(int i=0; i<6; i++){
  //    Blink_morse(morseCode[i]);
  //  }
  
  if(digitalRead(pinButton)==HIGH){
    innerLoop();
  }

}

void innerLoop(){
  for(int i=0; i<6; i++){
     Blink_morse(morseCode[i]);
   }
}

void Blink_morse(String pattern){
  for (int i=0; i < pattern.length(); i++ ) {
    if (pattern.charAt(i) == '.') {
      digitalWrite(LED_BUILTIN, HIGH); // Using LED_BUILTIN constant
      delay(1000);
    }
    else if(pattern.charAt(i) == '_') {
      digitalWrite(LED_BUILTIN, HIGH); // Using LED_BUILTIN constant
      delay(3000);
    }
    digitalWrite(LED_BUILTIN, LOW); // Using LED_BUILTIN constant
    delay(1000);
  }
  delay(1000); // Pause between letters
}



 