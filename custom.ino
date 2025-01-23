// свой список режимов

// ************************ НАСТРОЙКИ ************************
#define SMOOTH_CHANGE 1     // плавная смена режимов через чёрный
#define SHOW_FULL_TEXT 1    // не переключать режим, пока текст не покажется весь
#define SHOW_TEXT_ONCE 0    // показывать бегущий текст только 1 раз

// подключаем внешние файлы с картинками



/*
   Режимы:
    clockRoutine();       // часы на чёрном фоне

   Эффекты:
    sparklesRoutine();    // случайные цветные гаснущие вспышки
    snowRoutine();        // снег
    matrixRoutine();      // "матрица"
    starfallRoutine();    // звездопад (кометы)
    ballRoutine();        // квадратик
    ballsRoutine();       // шарики
    rainbowRoutine();     // радуга во всю матрицу горизонтальная
    rainbowDiagonalRoutine();   // радуга во всю матрицу диагональная
    fireRoutine();        // огонь

  Крутые эффекты "шума":
    madnessNoise();       // цветной шум во всю матрицу
    cloudNoise();         // облака
    lavaNoise();          // лава
    plasmaNoise();        // плазма
    rainbowNoise();       // радужные переливы
    rainbowStripeNoise(); // полосатые радужные переливы
    zebraNoise();         // зебра
    forestNoise();        // шумящий лес
    oceanNoise();         // морская вода

  Игры:
    snakeRoutine();     // змейка
    tetrisRoutine();    // тетрис
    mazeRoutine();      // лабиринт
    runnerRoutine();    // бегалка прыгалка
    flappyRoutine();    // flappy bird
    arkanoidRoutine();  // арканоид

  Бегущая строка:
    fillString("Ваш текст", цвет);    // цвет вида 0x00ff25 или CRGB::Red и проч. цвета
    fillString("Ваш текст", 1);       // радужный перелив текста
    fillString("Ваш текст", 2);       // каждая буква случайным цветом!

  Рисунки и анимации:
    loadImage(<название массива>);    // основная функция вывода картинки
    imageRoutine1();                  // пример использования
    animation1();                     // пример анимации

*/

// ************************* СВОЙ СПИСОК РЕЖИМОВ ************************
// список можно менять, соблюдая его структуру. Можно удалять и добавлять эффекты, ставить их в
// любой последовательности или вообще оставить ОДИН. Удалив остальные case и break. Cтруктура оч простая:
// case <номер>: <эффект>;
//  break;

// не забудьте указать количество режимов для корректного переключения с последнего на первый
int MODES_AMOUNT = 0;   // количество кастомных режимов (которые переключаются сами или кнопкой)
void customModes() {
//results.value = pred;
 // ir_flag = 0;
  
if (press == 1) {
MODES_AMOUNT = 9;
switch (thisMode) {
    case 0: madnessNoise();       // цветной шум во всю матрицу
    break;
    case 1: cloudNoise();         // облака
    break;
    case 2: lavaNoise();          // лава
    break;
    case 3: plasmaNoise();        // плазма
    break;
    case 4: rainbowNoise();       // радужные переливы
    break;
    case 5: rainbowStripeNoise(); // полосатые радужные переливы
    break;
    case 6: zebraNoise();         // зебра
    break;
    case 7: forestNoise();        // шумящий лес
    break;
    case 8: oceanNoise();         // морская вода
    break;
}

}

if (press == 2) {
MODES_AMOUNT = 10;
switch (thisMode) {
    case 0: fireRoutine();               // огонь
    break;
        case 1: fireRoutine();               // огонь
    break;
        case 2: fireRoutine();               // огонь
    break;
        case 3: fireRoutine();               // огонь
    break;
        case 4: fireRoutine();               // огонь
    break;
        case 5: fireRoutine();               // огонь
    break;
        case 6: fireRoutine();               // огонь
    break;
        case 7: fireRoutine();               // огонь
    break;
        case 8: fireRoutine();               // огонь
    break;
        case 9: fireRoutine();               // огонь
    break;
}
     
}



if (press == 3) {
MODES_AMOUNT = 8;
switch (thisMode) {
    case 0: snowRoutine();        // снег
    break;
    case 1: sparklesRoutine();    // случайные цветные гаснущие вспышки
    break;
    case 2: ballsRoutine();       // шарики
    break;
    case 3: starfallRoutine();    // звездопад (кометы)
    break;
    case 4:     ballRoutine();        // квадратик
    break;
    case 5: matrixRoutine();      // "матрица"
    break;
    case 6: rainbowRoutine();     // радуга во всю матрицу горизонтальная
    break;
    case 7: rainbowDiagonalRoutine();   // радуга во всю матрицу диагональная
    break;

}
     
}

if (press == 4) {
MODES_AMOUNT = 1;
switch (thisMode) {
  FastLED.clear();
    case 0: fillString("Я гей", 1);
    break;
}
     
}

if (press == 5) {
MODES_AMOUNT = 1;
switch (thisMode) {
  FastLED.clear();
    case 0: tetrisRoutine();    // тетрис
    break;
}
     
}

if (press == 6) {
MODES_AMOUNT = 1;
switch (thisMode) {
  FastLED.clear();
 case 0:snakeRoutine();     // змейка
break;
}
      
}

if (press == 7) {
MODES_AMOUNT = 1;
switch (thisMode) {
  FastLED.clear();
    case 0: runnerRoutine();    // бегалка прыгалка
    break;
}
      
}

if (press == 8) {
MODES_AMOUNT = 1;
switch (thisMode) {
  FastLED.clear();
    case 0: flappyRoutine();    // flappy bird
    break;
}
      
}

if (press == 9) {
MODES_AMOUNT = 1;
switch (thisMode) {
  FastLED.clear();
    case 0: arkanoidRoutine();  // арканоид
    break;
}
      
}

if (press == 0) {
MODES_AMOUNT = 1;
switch (thisMode) {
    case 0: clockRoutine();
    break;
    }  
}
//clockRoutine();       // часы

/*         case 1:oceanNoise();
       break;
           case 2: madnessNoise();
      break;
*/

      if (press == 11) {
MODES_AMOUNT = 3;
switch (thisMode) {
    case 0: sparklesRoutine();    // случайные цветные гаснущие вспышки
    break;
    case 1: matrixRoutine();      // "матрица"
    break;
    case 2: starfallRoutine();    // звездопад (кометы)
    break;
    }  
      }

    if (press == 12) {
MODES_AMOUNT = 2;
switch (thisMode) {
    case 0: rainbowRoutine();     // радуга во всю матрицу горизонтальная
    break;
    case 1: rainbowDiagonalRoutine();   // радуга во всю матрицу диагональная
    break;
    }  


}

  if (press == 101) {
MODES_AMOUNT = 1;
switch (thisMode) {
    case 0: fillString("Дай списать", 1);
    break;
}
    
}

  if (press == 102) {
MODES_AMOUNT = 1;
switch (thisMode) {
    case 0: fillString("Я люблю тебя <3", 2);
    break;
}
    
}

  if (press == 103) {
MODES_AMOUNT = 1;
switch (thisMode) {
    case 0: fillString("Пошёл нахер", 1);
    break;
}
    
}


if (press == 104) {
MODES_AMOUNT = 1;
switch (thisMode) {
    case 0: fillString("Привет", 1);
    break;
}
    
}

if (press == 105) {
MODES_AMOUNT = 1;
switch (thisMode) {
    case 0: fillString("Пока", 1);
    break;
}
    
}

if (press == 106) {
MODES_AMOUNT = 1;
switch (thisMode) {
    case 0: fillString("hello world", 1);
    break;
}
    
}

if (press == 107) {
MODES_AMOUNT = 1;
switch (thisMode) {
    case 0: fillString("Кастую фиолетовый", 2);
    break;
}
    
}

if (press == 108) {
MODES_AMOUNT = 1;
switch (thisMode) {
    case 0: fillString("???", 1);
    break;
}
    
}

if (press == 109) {
MODES_AMOUNT = 1;
switch (thisMode) {
    case 0: fillString("???", 1);
    break;
}
    
}

if (press == 100) {
MODES_AMOUNT = 1;
switch (thisMode) {
    case 0: fillString("???", 1);
    break;
}
    
}

if (press == 111) {
MODES_AMOUNT = 1;
switch (thisMode) {
    case 0: fillString("???", 1);
    break;
}
    
}

if (press == 112) {
MODES_AMOUNT = 1;
switch (thisMode) {
    case 0: fillString("???", 1);
    break;
}
    
}


  if (press == 201) {
MODES_AMOUNT = 6;
switch (thisMode) {
    case 0: animation(1); 
    break;
 //       case 1: animation(2); 
    //break;
        case 1: animation(3); 
    break;
        case 2: animation(4); 
    break;
        case 3: animation(5); 
    break;
        case 4: animation(6); 
    break;
        case 5: animation(7); 
    break;
    }
    
}

  if (press == 202) {
MODES_AMOUNT = 2;
switch (thisMode) {
    case 0: animation(5); 
    break;
        case 1: animation(4); 
    break;
}
    
}

  if (press == 203) {
MODES_AMOUNT = 1;
switch (thisMode) {
    case 0: animation(1); 
    break;
}
    
}


if (press == 204) {
MODES_AMOUNT = 1;
switch (thisMode) {
    case 0: animation(3); 
    break;
}
    
}

if (press == 205) {
MODES_AMOUNT = 1;
switch (thisMode) {
    case 0: animation(4); 
    break;
}
    
}

if (press == 206) {
MODES_AMOUNT = 1;
switch (thisMode) {
    case 0: animation(5); 
    break;
}
    
}

if (press == 207) {
MODES_AMOUNT = 1;
switch (thisMode) {
    case 0: animation(6); 
    break;
}
    
}

if (press == 208) {
MODES_AMOUNT = 1;
switch (thisMode) {
    case 0: animation(7); 
    break;
}
    
}

if (press == 209) {
MODES_AMOUNT = 3;
switch (thisMode) {
    case 0: animation(2); 
    break;
        case 1: animation(1); 
    break;
        case 2: animation(4); 
    break;
}
    
}

if (press == 210) {
MODES_AMOUNT = 4;
switch (thisMode) {
    case 0: animation(4); 
    break;
        case 1: animation(5); 
    break;
        case 2: animation(3); 
    break;
        case 3: animation(1); 
    break;
}
    
}

if (press == 211) {
MODES_AMOUNT = 2;
switch (thisMode) {
    case 0: animation(3); 
    break;
        case 1: animation(4); 
    break;
}
    
}

if (press == 212) {
MODES_AMOUNT = 2;
switch (thisMode) {
    case 0: animation(7); 
    break;
        case 1: animation(6); 
    break;
}
    
}
/*

    
    
    
    
    



    rainbowRoutine();     // радуга во всю матрицу горизонтальная
    rainbowDiagonalRoutine();   // радуга во всю матрицу диагональная
  switch (thisMode) {

    case 0: fillString("КРАСНЫЙ", CRGB::Red);
      break;
    case 1: fillString("РАДУГА", 1);
      break;
    case 2: fillString("RGB LED", 2);
      break;
    case 3: madnessNoise();
      break;
    case 4: cloudNoise();
      break;
    case 5: lavaNoise();
      break;
    case 6: plasmaNoise();
      break;
    case 7: rainbowNoise();
      break;
    case 8: rainbowStripeNoise();
      break;
    case 9: zebraNoise();
      break;
    case 10: forestNoise();
      break;
    case 11: oceanNoise();
      break;
    case 12: snowRoutine();
      break;
    case 13: sparklesRoutine();
      break;
    case 14: matrixRoutine();
      break;
    case 15: starfallRoutine();
      break;
    case 16: ballRoutine();
      break;
    case 17: ballsRoutine();
      break;
    case 18: rainbowRoutine();
      break;
    case 19: rainbowDiagonalRoutine();
      break;
    case 20: fireRoutine();
      break;
    case 21: snakeRoutine();
      break;
    case 22: tetrisRoutine();
      break;
    case 23: mazeRoutine();
      break;
    case 24: runnerRoutine();
      break;
    case 25: flappyRoutine();
      break;
    case 26: arkanoidRoutine();
      break;
    case 27: clockRoutine();
      break;


  }
*/
}

// функция загрузки картинки в матрицу. должна быть здесь, иначе не работает =)
/*void loadImage(uint16_t (*frame)[WIDTH]) {
  for (byte i = 0; i < WIDTH; i++)
    for (byte j = 0; j < HEIGHT; j++)
      drawPixelXY(i, j, gammaCorrection(expandColor((pgm_read_word(&(frame[HEIGHT - j - 1][i]))))));
  // да, тут происходит лютенький п@здец, а именно:
  // 1) pgm_read_word - восстанавливаем из PROGMEM (флэш памяти) цвет пикселя в 16 битном формате по его координатам
  // 2) expandColor - расширяем цвет до 24 бит (спасибо adafruit)
  // 3) gammaCorrection - проводим коррекцию цвета для более корректного отображения
}
*/


// ********************** ПРИМЕРЫ ВЫВОДА КАРТИНОК ***********************

// Внимание! Если размер матрицы не совпадает с исходным размером матрицы в скетче
// (если вы только что  его скачали), то нужно удалить/закомментировать данные функции!
//
/*
  // показать картинку
  void imageRoutine1() {
  if (loadingFlag) {
    loadingFlag = false;
    loadImage(frame00);
  }
  }

  void animation1() {
  if (gifTimer.isReady()) {
    frameNum++;
    if (frameNum >= sizeof(framesArray)) frameNum = 0;
    loadImage(framesArray[frameNum]);
  }
  }
*/

// ********************* ОСНОВНОЙ ЦИКЛ РЕЖИМОВ *******************
#if (SMOOTH_CHANGE == 1)
byte fadeMode = 4;
boolean modeDir;
#endif

static void nextMode() {
#if (SMOOTH_CHANGE == 1)
  fadeMode = 0;
  modeDir = true;
#else
  nextModeHandler();
#endif
}
static void prevMode() {
#if (SMOOTH_CHANGE == 1)
  fadeMode = 0;
  modeDir = false;
#else
  prevModeHandler();
#endif
}
void nextModeHandler() {
  thisMode++;
  if (thisMode >= MODES_AMOUNT) thisMode = 0;
  loadingFlag = true;
  gamemodeFlag = false;
  FastLED.clear();
  FastLED.show();
}
void prevModeHandler() {
  thisMode--;
  if (thisMode < 0) thisMode = MODES_AMOUNT - 1;
  loadingFlag = true;
  gamemodeFlag = false;
  FastLED.clear();
  FastLED.show();
}

int fadeBrightness;
#if (SMOOTH_CHANGE == 1)
void modeFader() {
  if (fadeMode == 0) {
    fadeMode = 1;
  } else if (fadeMode == 1) {
    if (changeTimer.isReady()) {
      fadeBrightness -= 40;
      if (fadeBrightness < 0) {
        fadeBrightness = 0;
        fadeMode = 2;
      }
      FastLED.setBrightness(fadeBrightness);
    }
  } else if (fadeMode == 2) {
    fadeMode = 3;
    if (modeDir) nextModeHandler();
    else prevModeHandler();
  } else if (fadeMode == 3) {
    if (changeTimer.isReady()) {
      fadeBrightness += 40;
      if (fadeBrightness > globalBrightness) {
        fadeBrightness = globalBrightness;
        fadeMode = 4;
      }
      FastLED.setBrightness(fadeBrightness);
    }
  }
}
#endif

boolean loadFlag2;
void customRoutine() {
  if (!BTcontrol) {
    if (!gamemodeFlag) {
      if (effectTimer.isReady()) {
#if (OVERLAY_CLOCK == 1 && USE_CLOCK == 1)
        if (overlayAllowed()) {
          if (!loadingFlag && !gamemodeFlag && needUnwrap() && modeCode != 0) clockOverlayUnwrap(CLOCK_X, CLOCK_Y);
          if (loadingFlag) loadFlag2 = true;
        }
#endif

        customModes();                // режимы крутятся, пиксели мутятся

#if (OVERLAY_CLOCK == 1 && USE_CLOCK == 1)
        if (overlayAllowed()) {
          if (!gamemodeFlag && modeCode != 0) clockOverlayWrap(CLOCK_X, CLOCK_Y);
          if (loadFlag2) {
            setOverlayColors();
            loadFlag2 = false;
          }
        }
#endif
        loadingFlag = false;
        FastLED.show();
      }
    } else {
      customModes();
    }
    btnsModeChange();
#if (SMOOTH_CHANGE == 1)
    modeFader();
#endif
  }

  if (idleState) {
    if (fullTextFlag && SHOW_TEXT_ONCE) {
      fullTextFlag = false;
      autoplayTimer = millis();
      nextMode();
    }
    if (millis() - autoplayTimer > autoplayTime && AUTOPLAY) {    // таймер смены режима
      if (modeCode == 0 && SHOW_FULL_TEXT) {    // режим текста
        if (fullTextFlag) {
          fullTextFlag = false;
          autoplayTimer = millis();
          nextMode();
        }
      } else {
        autoplayTimer = millis();
        nextMode();
      }
    }
  } else {
    if (idleTimer.isReady()) {      // таймер холостого режима
      idleState = true;
      autoplayTimer = millis();
      gameDemo = true;

      gameSpeed = DEMO_GAME_SPEED;
      gameTimer.setInterval(gameSpeed);

      loadingFlag = true;
      BTcontrol = false;
      FastLED.clear();
      FastLED.show();
    }
  }
}

void timeSet(boolean type, boolean dir) {    // type: 0-часы, 1-минуты, dir: 0-уменьшить, 1-увеличить
  if (type) {
    if (dir) hrs++;
    else hrs--;
  } else {
    if (dir) mins++;
    else mins--;
    if (mins > 59) {
      mins = 0;
      hrs++;
    }
    if (mins < 0) {
      mins = 59;
      hrs--;
    }
  }
  if (hrs > 23) hrs = 0;
  if (hrs < 0) hrs = 23;
}

void btnsModeChange() {
#if (USE_BUTTONS == 1)
  if (bt_set.clicked()) {
    if (gamemodeFlag) gameDemo = !gameDemo;
    if (gameDemo) {
      gameSpeed = DEMO_GAME_SPEED;
      gameTimer.setInterval(gameSpeed);
      AUTOPLAY = true;
    } else {
      gameSpeed = D_GAME_SPEED;
      gameTimer.setInterval(gameSpeed);
      AUTOPLAY = false;
    }
  }
  if (bt_set.holded()) {
    if (modeCode == 2)
      mazeMode = !mazeMode;
    if (modeCode == 1) {    // вход в настройку часов
      clockSet = !clockSet;
      AUTOPLAY = false;
      secs = 0;
#if (USE_CLOCK == 1)
      if (!clockSet) rtc.adjust(DateTime(2014, 1, 21, hrs, mins, 0)); // установка нового времени в RTC
#endif
    }
  }

  // timeSet type: 0-часы, 1-минуты, dir: 0-уменьшить, 1-увеличить

  if (gameDemo) {
    if (bt_right.clicked()) {
      if (!clockSet) {
        autoplayTimer = millis();
        nextMode();
      } else {
        timeSet(1, 1);
      }
    }

    if (bt_left.clicked()) {
      if (!clockSet) {
        autoplayTimer = millis();
        prevMode();
      } else {
        timeSet(1, 0);
      }
    }

    if (bt_up.clicked()) {
      if (!clockSet) {
        AUTOPLAY = true;
        autoplayTimer = millis();
      } else {
        timeSet(0, 1);
      }
    }
    if (bt_down.clicked()) {
      if (!clockSet) {
        AUTOPLAY = false;
      } else {
        timeSet(0, 0);
      }
    }

    if (bt_right.holding())
      if (changeTimer.isReady()) {
        if (!clockSet) {
          effects_speed -= 2;
          if (effects_speed < 30) effects_speed = 30;
          effectTimer.setInterval(effects_speed);
        } else {
          timeSet(1, 1);
        }
      }
    if (bt_left.holding())
      if (changeTimer.isReady()) {
        if (!clockSet) {
          effects_speed += 2;
          if (effects_speed > 300) effects_speed = 300;
          effectTimer.setInterval(effects_speed);
        } else {
          timeSet(1, 0);
        }
      }
    if (bt_up.holding())
      if (changeTimer.isReady()) {
        if (!clockSet) {
          globalBrightness += 2;
          if (globalBrightness > 255) globalBrightness = 255;
          fadeBrightness = globalBrightness;
          FastLED.setBrightness(globalBrightness);
        } else {
          timeSet(0, 1);
        }
      }
    if (bt_down.holding())
      if (changeTimer.isReady()) {
        if (!clockSet) {
          globalBrightness -= 2;
          if (globalBrightness < 0) globalBrightness = 0;
          fadeBrightness = globalBrightness;
          FastLED.setBrightness(globalBrightness);
        } else {
          timeSet(0, 0);
        }
      }
  }
#endif
}
