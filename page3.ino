#if (button == 2) //red
if (pressu == 121) {
  AUTOPLAYz += 5;
  pressu = 200;


}

if (pressu == 120) {
  AUTOPLAYz -= 5;
    pressu = 200;

}


if (pressu == 122) {
  AUTOPLAYz += 25;
  pressu = 200;

}

if (pressu == 123) {
  AUTOPLAYz -= 25;
    pressu = 200;

}

Serial.print("button = ");
Serial.print(button);
Serial.println("led = ");
Serial.print("red");
Serial.println("AUTOPLAYz = ");
Serial.print(AUTOPLAYz);
Serial.println(" ; ");

#endif

