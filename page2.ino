#if (button == 1) //blue

if (pressu == 121) {
  BRIGHTNES += 5;
  pressu = 200;


}

if (pressu == 120) {
  BRIGHTNES -= 5;
    pressu = 200;


}


if (pressu == 122) {
  BRIGHTNES += 25;
  pressu = 200;


}

if (pressu == 123) {
  BRIGHTNES -= 25;
    pressu = 200;


}

FastLED.show(BRIGHTNES);

Serial.print("button = ");
Serial.print(button);
Serial.println("led = ");
Serial.print("blue");
Serial.println("BRIGHTNES = ");
Serial.print(BRIGHTNES);
Serial.println(" ; ");

#endif