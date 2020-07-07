#include <CapacitiveSensor.h>

CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
// pin 2 -> 1K resistor -> foil on cap
// pin 4 -> 4.7M resistor to foil on cap
// A9 pin to LED (add ~200ohm resistor) which will turn on when triggered

void setup()                    
{
   pinMode(12, OUTPUT);
}

void loop()                    
{
    long start = millis();
    long total1 =  cs_4_2.capacitiveSensor(30);
    // also tested with 1400 on bigger foil
    if (total1 > 250) {
      digitalWrite(12, HIGH);
      Keyboard.set_key1(KEY_ESC);
      Keyboard.send_now();
      delay(1);
      Keyboard.set_key1(0);
      Keyboard.send_now();
      Keyboard.print(":q!"); 
      delay(1);
      Keyboard.send_now();
      Keyboard.set_key2(KEY_ENTER);
      Keyboard.send_now();
      delay(1);      
      Keyboard.set_key2(0);
      Keyboard.send_now();
      delay(500);
      digitalWrite(12, LOW);
    }
    delay(5);    
}
