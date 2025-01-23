

void IRWEM1() {
/* if (ir_flag == 1) {
customRoutine();
bluetoothRoutine();
}
  */   
  // Проверяем, есть ли новый сигнал



    // Выводим результаты декодирования в последовательный порт
    serialPrintUint64(results.value, HEX);
    Serial.print(" ");

    switch (results.value) {
      if (millis() - okk >= 120) {
            case 0xFF38C7:  // Пример значения для кнопки "OK" на некоторых пультах
        Serial.println("Button OK pressed"); button ++;
        break;
        okk = millis();
      }
    }
 //   pred = results.value;
if (button == 0) {
/*  digitalWrite(ledg, HIGH);
  digitalWrite(ledr, LOW);
  digitalWrite(ledb, LOW); */
    // Выводим разный текст в зависимости от нажатой кнопки
    switch (results.value) {
      case 0xFFA25D:  // Пример значения для кнопки "1" на некоторых пультах
        Serial.println("Button 1 pressed"); press = 1; FastLED.clear(); AUTOPLAY_PERIOD = AUTOPLAYz;
        break;
      case 0xFF629D:  // Пример значения для кнопки "2" на некоторых пультах
        Serial.println("Button 2 pressed"); press = 2; FastLED.clear(); AUTOPLAY_PERIOD = AUTOPLAYz;
        break;
      case 0xFFE21D:  // Пример значения для кнопки "3" на некоторых пультах
        Serial.println("Button 3 pressed"); press = 3; FastLED.clear(); AUTOPLAY_PERIOD = AUTOPLAYz;
        break;
      case 0xFF22DD:  // Пример значения для кнопки "4" на некоторых пультах
        Serial.println("Button 4 pressed"); press = 4; FastLED.clear(); AUTOPLAY_PERIOD = AUTOPLAYz;
        break;
      case 0xFF02FD:  // Пример значения для кнопки "5" на некоторых пультах
        Serial.println("Button 5 pressed"); press = 5; FastLED.clear(); gameOverTetris(); newGameTetris(); AUTOPLAY_PERIOD = 30000;
        break;
      case 0xFFC23D:  // Пример значения для кнопки "6" на некоторых пультах
        Serial.println("Button 6 pressed"); press = 6; FastLED.clear(); newGameSnake(); AUTOPLAY_PERIOD = 30000;
        break;
      case 0xFFE01F:  // Пример значения для кнопки "7" на некоторых пультах
        Serial.println("Button 7 pressed"); press = 7; FastLED.clear(); AUTOPLAY_PERIOD = 30000;
        break;
      case 0xFFA857:  // Пример значения для кнопки "8" на некоторых пультах
        Serial.println("Button 8 pressed"); press = 8; FastLED.clear(); AUTOPLAY_PERIOD = 30000;
        break;
      case 0xFF906F:  // Пример значения для кнопки "9" на некоторых пультах
        Serial.println("Button 9 pressed"); press = 9; FastLED.clear(); gameOverArkan(); newGameArkan(); AUTOPLAY_PERIOD = 30000;
        break;
      case 0xFF9867:  // Пример значения для кнопки "0" на некоторых пультах
        Serial.println("Button 0 pressed"); press = 0; ESP.restart(); AUTOPLAY_PERIOD = 30000; //FastLED.clear();
        break;
       case 0xFF6897:  // Пример значения для кнопки "*" на некоторых пультах
        Serial.println("Button * pressed"); press = 11;
        break;
      case 0xFFB04F:  // Пример значения для кнопки "#" на некоторых пультах
        Serial.println("Button # pressed"); press = 12;
        break;
      case 0xFF18E7:  // Пример значения для кнопки "UP" на некоторых пультах
        Serial.println("Button UP pressed"); pressu = 22;
        break;
      case 0xFF4AB5:  // Пример значения для кнопки "DOWN" на некоторых пультах
        Serial.println("Button DOWN pressed"); pressu = 23;
        break;
      case 0xFF10EF:  // Пример значения для кнопки "LEFT" на некоторых пультах
        Serial.println("Button LEFT pressed"); pressu = 20;
        break;
      case 0xFF5AA5:  // Пример значения для кнопки "RIGHT" на некоторых пультах
        Serial.println("Button RIGHT pressed"); pressu = 21;
        break;

    


    }
}


if (button == 1) {
/*  digitalWrite(ledb, HIGH);
  digitalWrite(ledr, LOW);
  digitalWrite(ledg, LOW);*/
    // Выводим разный текст в зависимости от нажатой кнопки
    switch (results.value) {
      case 0xFFA25D:  // Пример значения для кнопки "1" на некоторых пультах
        Serial.println("Button 1 pressed"); press = 101; FastLED.clear(); AUTOPLAY_PERIOD = AUTOPLAYz;
        break;
      case 0xFF629D:  // Пример значения для кнопки "2" на некоторых пультах
        Serial.println("Button 2 pressed"); press = 102; FastLED.clear(); AUTOPLAY_PERIOD = AUTOPLAYz;
        break;
      case 0xFFE21D:  // Пример значения для кнопки "3" на некоторых пультах
        Serial.println("Button 3 pressed"); press = 103; FastLED.clear(); AUTOPLAY_PERIOD = AUTOPLAYz;
        break;
      case 0xFF22DD:  // Пример значения для кнопки "4" на некоторых пультах
        Serial.println("Button 4 pressed"); press = 104; FastLED.clear(); AUTOPLAY_PERIOD = AUTOPLAYz;
        break;
      case 0xFF02FD:  // Пример значения для кнопки "5" на некоторых пультах
        Serial.println("Button 5 pressed"); press = 105; FastLED.clear();  AUTOPLAY_PERIOD = AUTOPLAYz;
        break;
      case 0xFFC23D:  // Пример значения для кнопки "6" на некоторых пультах
        Serial.println("Button 6 pressed"); press = 106; FastLED.clear();  AUTOPLAY_PERIOD = AUTOPLAYz;
        break;
      case 0xFFE01F:  // Пример значения для кнопки "7" на некоторых пультах
        Serial.println("Button 7 pressed"); press = 107; FastLED.clear();  AUTOPLAY_PERIOD = AUTOPLAYz;
        break;
      case 0xFFA857:  // Пример значения для кнопки "8" на некоторых пультах
        Serial.println("Button 8 pressed"); press = 108; FastLED.clear();  AUTOPLAY_PERIOD = AUTOPLAYz;
        break;
      case 0xFF906F:  // Пример значения для кнопки "9" на некоторых пультах
        Serial.println("Button 9 pressed"); press = 109; FastLED.clear();  AUTOPLAY_PERIOD = AUTOPLAYz;
        break;
      case 0xFF9867:  // Пример значения для кнопки "0" на некоторых пультах
        Serial.println("Button 0 pressed"); press = 100; FastLED.clear(); AUTOPLAY_PERIOD = AUTOPLAYz;
        break;
               case 0xFF6897:  // Пример значения для кнопки "*" на некоторых пультах
        Serial.println("Button * pressed"); press = 111;
        break;
      case 0xFFB04F:  // Пример значения для кнопки "#" на некоторых пультах
        Serial.println("Button # pressed"); press = 112;
        break;
      case 0xFF18E7:  // Пример значения для кнопки "UP" на некоторых пультах
        Serial.println("Button UP pressed"); pressu = 122;
        break;
      case 0xFF4AB5:  // Пример значения для кнопки "DOWN" на некоторых пультах
        Serial.println("Button DOWN pressed"); pressu = 123;
        break;
      case 0xFF10EF:  // Пример значения для кнопки "LEFT" на некоторых пультах
        Serial.println("Button LEFT pressed"); pressu = 120;
        break;
      case 0xFF5AA5:  // Пример значения для кнопки "RIGHT" на некоторых пультах
        Serial.println("Button RIGHT pressed"); pressu = 121;
        break;

    


    }
}



if (button == 2) {
/*   digitalWrite(ledr, HIGH); 
   digitalWrite(ledg, LOW);
   digitalWrite(ledb, LOW);*/
    // Выводим разный текст в зависимости от нажатой кнопки
    switch (results.value) {
      case 0xFFA25D:  // Пример значения для кнопки "1" на некоторых пультах
        Serial.println("Button 1 pressed"); press = 201; FastLED.clear(); AUTOPLAY_PERIOD = AUTOPLAYz;
        break;
      case 0xFF629D:  // Пример значения для кнопки "2" на некоторых пультах
        Serial.println("Button 2 pressed"); press = 202; FastLED.clear(); AUTOPLAY_PERIOD = AUTOPLAYz;
        break;
      case 0xFFE21D:  // Пример значения для кнопки "3" на некоторых пультах
        Serial.println("Button 3 pressed"); press = 203; FastLED.clear(); AUTOPLAY_PERIOD = AUTOPLAYz;
        break;
      case 0xFF22DD:  // Пример значения для кнопки "4" на некоторых пультах
        Serial.println("Button 4 pressed"); press = 204; FastLED.clear(); AUTOPLAY_PERIOD = AUTOPLAYz;
        break;
      case 0xFF02FD:  // Пример значения для кнопки "5" на некоторых пультах
        Serial.println("Button 5 pressed"); press = 205; FastLED.clear(); AUTOPLAY_PERIOD = AUTOPLAYz;
        break;
      case 0xFFC23D:  // Пример значения для кнопки "6" на некоторых пультах
        Serial.println("Button 6 pressed"); press = 206; FastLED.clear(); AUTOPLAY_PERIOD = AUTOPLAYz;
        break;
      case 0xFFE01F:  // Пример значения для кнопки "7" на некоторых пультах
        Serial.println("Button 7 pressed"); press = 207; FastLED.clear(); AUTOPLAY_PERIOD = AUTOPLAYz;
        break;
      case 0xFFA857:  // Пример значения для кнопки "8" на некоторых пультах
        Serial.println("Button 8 pressed"); press = 208; FastLED.clear(); AUTOPLAY_PERIOD = AUTOPLAYz;
        break;
      case 0xFF906F:  // Пример значения для кнопки "9" на некоторых пультах
        Serial.println("Button 9 pressed"); press = 209; FastLED.clear(); AUTOPLAY_PERIOD = AUTOPLAYz;
        break;
      case 0xFF9867:  // Пример значения для кнопки "0" на некоторых пультах
        Serial.println("Button 0 pressed"); press = 210; FastLED.clear(); AUTOPLAY_PERIOD = AUTOPLAYz;
        break;
               case 0xFF6897:  // Пример значения для кнопки "*" на некоторых пультах
        Serial.println("Button * pressed"); press = 211;
        break;
      case 0xFFB04F:  // Пример значения для кнопки "#" на некоторых пультах
        Serial.println("Button # pressed"); press = 212;
        break;
      case 0xFF18E7:  // Пример значения для кнопки "UP" на некоторых пультах
        Serial.println("Button UP pressed"); pressu = 222;
        break;
      case 0xFF4AB5:  // Пример значения для кнопки "DOWN" на некоторых пультах
        Serial.println("Button DOWN pressed"); pressu = 223;
        break;
      case 0xFF10EF:  // Пример значения для кнопки "LEFT" на некоторых пультах
        Serial.println("Button LEFT pressed"); pressu = 220;
        break;
      case 0xFF5AA5:  // Пример значения для кнопки "RIGHT" на некоторых пультах
        Serial.println("Button RIGHT pressed"); pressu = 221;
        break;
    }
}














      //ir_flag = 1;
    // Ждем 200 мс перед обработкой следующего сигнала
    irrecv.resume();
    delay(125);

        if (pressu == 20) {
    buttons = 3;
  }

    if (pressu == 21) {
    buttons = 1;
  }

    if (pressu == 22) {
    buttons = 0;
  }

    if (pressu == 23) {
    buttons = 2;
  }
  }










 /* if (press == 20) {
    buttons = 3;
  }

    if (press == 21) {
    buttons = 1;
  }

    if (press == 22) {
    buttons = 0;
  }

    if (press == 23) {
    buttons = 2;
  }

    press = 200;
*/







