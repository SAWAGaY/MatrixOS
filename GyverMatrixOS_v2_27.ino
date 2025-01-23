/*
  Скетч к проекту "Адресная матрица"
  Гайд по постройке матрицы: https://alexgyver.ru/matrix_guide/
  Страница проекта (схемы, описания): https://alexgyver.ru/GyverMatrixBT/
  Подробное описание прошивки: https://alexgyver.ru/gyvermatrixos-guide/
  Исходники на GitHub: https://github.com/AlexGyver/GyverMatrixBT/
  Нравится, как написан код? Поддержи автора! https://alexgyver.ru/support_alex/
  Автор: AlexGyver Technologies, 2018
  https://AlexGyver.ru/
*/

#define MC_IMAGE                23
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

#include <PubSubClient.h>

//boolean switchVariable = 0;

// Настройки Wi-Fi
const char* ssid = "KV 27-A1";
const char* password = "16072017";

// Настройки MQTT для Delegate
const char* mqtt_server = "mqtt.dealgate.ru"; // Адрес брокера Delegate
const int mqtt_port = 1883; // Порт по умолчанию для MQTT
const char* mqtt_username = "sawaSAWA"; // Имя пользователя для брокера Delegate
const char* mqtt_password = "SAWA2009"; // Пароль для брокера Delegate

// Список топиков
const char* topics[] = {
  "button1", "button2", "button3", "button4", "button5",
  "button6", "button7", "button8", "button9", "button0",
  "up", "down", "ok", "left", "right",
  "star", "grid", "topic/18", "topic/19", "topic/20"
};

int AUTOPLAYz = 120;

byte BRIGHTNES = 150;

byte button = 0;

boolean clocks = false;

boolean jed = false;

//uint64_t pred = 0xFF9867;

int sdmin = 1;
int sdsec = 55;

unsigned long ani;
unsigned long sad;
unsigned long gar;
unsigned long mqtt;
unsigned long mqtt2;
unsigned long mqtt3;
unsigned long let;
unsigned long okk;
//boolean ok_flag = 0;
//boolean ir_flag = 0;

byte press = 0; // 1-9(+0) -- цифры. звёздачка(star(10)) -- текст. решётка(hesh(11)) -- картинка(анимация). левая, правая, верхняя, нижняя(left, right, up, down(20, 21, 22, 23)) -- стрелочки. ок(ok(24)) -- ok
byte pressu = 0;
// Указываем пин, к которому подключен ИК-приемник
const uint16_t kRecvPin = 0;  // Например, GPIO14 на ESP8266

// Создаем объект IRrecv
IRrecv irrecv(kRecvPin);

// Создаем объект для хранения результатов декодирования
decode_results results;

// GyverMatrixOS
// Версия прошивки 1.12, совместима с приложением GyverMatrixBT версии 1.12 и выше
// 1.12 - поправлен косяк с кнопкой SET на wemos/nodemcu

// ************************ МАТРИЦА *************************
// если прошивка не лезет в Arduino NANO - отключай режимы! Строка 60 и ниже

#define BRIGHTNESS 150        // стандартная маскимальная яркость (0-255)
#define CURRENT_LIMIT 2000    // лимит по току в миллиамперах, автоматически управляет яркостью (пожалей свой блок питания!) 0 - выключить лимит

#define WIDTHS 1
#define WIDTH 16              // ширина матрицы
#define HEIGHT 16             // высота матрицы
#define SEGMENTS 1            // диодов в одном "пикселе" (для создания матрицы из кусков ленты)

#define COLOR_ORDER GRB       // порядок цветов на ленте. Если цвет отображается некорректно - меняйте. Начать можно с RGB

#define MATRIX_TYPE 0         // тип матрицы: 0 - зигзаг, 1 - параллельная
#define CONNECTION_ANGLE 0    // угол подключения: 0 - левый нижний, 1 - левый верхний, 2 - правый верхний, 3 - правый нижний
#define STRIP_DIRECTION 0     // направление ленты из угла: 0 - вправо, 1 - вверх, 2 - влево, 3 - вниз
// при неправильной настрйоке матрицы вы получите предупреждение "Wrong matrix parameters! Set to default"
// шпаргалка по настройке матрицы здесь! https://alexgyver.ru/matrix_guide/

#define MCU_TYPE 1            // микроконтроллер: 
//                            0 - AVR (Arduino NANO/MEGA/UNO)
//                            1 - ESP8266 (NodeMCU, Wemos D1)
//                            2 - STM32 (Blue Pill)

// ******************** ЭФФЕКТЫ И РЕЖИМЫ ********************
#define D_TEXT_SPEED 1      // скорость бегущего текста по умолчанию (мс)
#define D_EFFECT_SPEED 1     // скорость эффектов по умолчанию (мс)
#define D_GAME_SPEED 1     // скорость игр по умолчанию (мс)
#define D_GIF_SPEED 1        // скорость гифок (мс)//////////////////////////////////////////////////////////могут быть проблеммы..
#define DEMO_GAME_SPEED 1    // скорость игр в демо режиме (мс)

boolean AUTOPLAY = 1;         // 0 выкл / 1 вкл автоматическую смену режимов (откл. можно со смартфона)
int AUTOPLAY_PERIOD = 30000;     // время между авто сменой режимов (секунды)
#define IDLE_TIME 20          // время бездействия кнопок или Bluetooth (в секундах) после которого запускается автосмена режимов и демо в играх

// о поддерживаемых цветах читай тут https://alexgyver.ru/gyvermatrixos-guide/
#define GLOBAL_COLOR_1 CRGB::Green    // основной цвет №1 для игр
#define GLOBAL_COLOR_2 CRGB::Orange   // основной цвет №2 для игр

#define SCORE_SIZE 0          // размер символов счёта в игре. 0 - маленький для 8х8 (шрифт 3х5), 1 - большой (шрифт 5х7)
#define FONT_TYPE 1           // (0 / 1) два вида маленького шрифта в выводе игрового счёта

// ************** ОТКЛЮЧЕНИЕ КОМПОНЕНТОВ СИСТЕМЫ (для экономии памяти) *************
// внимание! отключение модуля НЕ УБИРАЕТ его эффекты из списка воспроизведения!
// Это нужно сделать вручную во вкладке custom, удалив ненужные функции
#define USE_ir 1 
#define USE_BUTTONS 1         // использовать физические кнопки управления играми (0 нет, 1 да)
#define BT_MODE 0             // использовать блютус (0 нет, 1 да)
#define USE_NOISE_EFFECTS 1   // крутые полноэкранные эффекты (0 нет, 1 да) СИЛЬНО ЖРУТ ПАМЯТЬ!!!11
#define USE_FONTS 1           // использовать буквы (бегущая строка) (0 нет, 1 да)
#define USE_CLOCK 1           // использовать часы (0 нет, 1 да)

// игры
#define USE_SNAKE 1           // игра змейка (0 нет, 1 да)
#define USE_TETRIS 1          // игра тетрис (0 нет, 1 да)
#define USE_MAZE 0            // игра лабиринт (0 нет, 1 да)
#define USE_RUNNER 1          // игра бегалка-прыгалка (0 нет, 1 да)
#define USE_FLAPPY 1          // игра flappy bird
#define USE_ARKAN 1           // игра арканоид

// ****************** ПИНЫ ПОДКЛЮЧЕНИЯ *******************
// Arduino (Nano, Mega)
#if (MCU_TYPE == 0)
#define ledr 12               // пин светодиода
#define ledg 13               // пин светодиода
#define ledb 14               // пин светодиода
#define LED_PIN 6           // пин ленты
#define BUTT_UP 3           // кнопка вверх
#define BUTT_DOWN 5         // кнопка вниз
#define BUTT_LEFT 2         // кнопка влево
#define BUTT_RIGHT 4        // кнопка вправо
#define BUTT_SET 7          // кнопка выбор/игра

// пины подписаны согласно pinout платы, а не надписям на пинах!
// esp8266 - плату выбирал Wemos D1 R1
#elif (MCU_TYPE == 1)
#define ledr 12               // пин светодиода
#define ledg 13               // пин светодиода
#define ledb 14               // пин светодиода
#define LED_PIN 2           // пин ленты
#define BUTT_UP 16          // кнопка вверх
#define BUTT_DOWN 4        // кнопка вниз
#define BUTT_LEFT 0         // кнопка влево
#define BUTT_RIGHT 5       // кнопка вправо
#define BUTT_SET 15         // кнопка выбор/игра

// STM32 (BluePill) - плату выбирал STM32F103C
#elif (MCU_TYPE == 2)
#define LED_PIN PB12         // пин ленты
#define BUTT_UP PA1          // кнопка вверх
#define BUTT_DOWN PA3        // кнопка вниз
#define BUTT_LEFT PA0        // кнопка влево
#define BUTT_RIGHT PA2       // кнопка вправо
#define BUTT_SET PA4         // кнопка выбор/игра
#endif

// ******************************** ДЛЯ РАЗРАБОТЧИКОВ ********************************
#define DEBUG 0
#define NUM_LEDS WIDTH * HEIGHT * SEGMENTS

#define RUNNING_STRING 0
#define CLOCK_MODE 1
#define GAME_MODE 2
#define MADNESS_NOISE 3
#define CLOUD_NOISE 4
#define LAVA_NOISE 5
#define PLASMA_NOISE 6
#define RAINBOW_NOISE 7
#define RAINBOWSTRIPE_NOISE 8
#define ZEBRA_NOISE 9
#define FOREST_NOISE 10
#define OCEAN_NOISE 11
#define SNOW_ROUTINE 12
#define SPARKLES_ROUTINE 13
#define MATRIX_ROUTINE 14
#define STARFALL_ROUTINE 15
#define BALL_ROUTINE 16
#define BALLS_ROUTINE 17
#define RAINBOW_ROUTINE 18
#define RAINBOWDIAGONAL_ROUTINE 19
#define FIRE_ROUTINE 20
#define IMAGE_MODE 21

#if (MCU_TYPE == 1)
#define FASTLED_INTERRUPT_RETRY_COUNT 0
#define FASTLED_ALLOW_INTERRUPTS 0
#include <ESP8266WiFi.h>
WiFiClient espClient;
PubSubClient client(espClient);
#endif

#include "FastLED.h"
CRGB leds[NUM_LEDS];
String runningText = "";

static const byte maxDim = max(WIDTH, HEIGHT);
byte buttons = 4;   // 0 - верх, 1 - право, 2 - низ, 3 - лево, 4 - не нажата
int globalBrightness = BRIGHTNESS;
byte globalSpeed = 200;
uint32_t globalColor = 0x00ff00;   // цвет при запуске зелёный
byte breathBrightness;
boolean loadingFlag = true;
byte frameNum;
int gameSpeed = DEMO_GAME_SPEED;
boolean gameDemo = false;
boolean idleState = true;  // флаг холостого режима работы
boolean BTcontrol = false;  // флаг контроля с блютус. Если false - управление с кнопок
int8_t thisMode = 0;
boolean controlFlag = false;
boolean gamemodeFlag = false;
boolean mazeMode = false;
int effects_speed = D_EFFECT_SPEED;
int8_t hrs = 10, mins = 25, secs, day, month;
boolean dotFlag;
byte modeCode;    // 0 бегущая, 1 часы, 2 игры, 3 нойс маднесс и далее, 21 гифка или картинка,
boolean fullTextFlag = false;
boolean clockSet = false;

#if (USE_FONTS == 1)
#include "fonts.h"
#endif

uint32_t autoplayTime = ((long)AUTOPLAY_PERIOD * 1000);
uint32_t autoplayTimer;

#include "timerMinim.h"
timerMinim effectTimer(D_EFFECT_SPEED);
timerMinim gameTimer(DEMO_GAME_SPEED);
timerMinim scrollTimer(D_TEXT_SPEED);
timerMinim idleTimer((long)IDLE_TIME * 1000);
timerMinim changeTimer(70);
timerMinim halfsecTimer(500);

#if (USE_CLOCK == 1 && (MCU_TYPE == 0 || MCU_TYPE == 1))
#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;
// RTC_DS1307 rtc;
#endif

void setup() {
  pinMode(ledr, OUTPUT);
    pinMode(ledg, OUTPUT);
      pinMode(ledb, OUTPUT);

    //Serial.begin(115200);
  
  // Подключение к Wi-Fi
  setup_wifi();
  
  // Настройка MQTT клиента
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

  gameDemo = 0;

#if (BT_MODE == 1)
  Serial.begin(9600);
#endif

#if (USE_ir == 1)
  // Инициализация последовательного порта для отладки
  Serial.begin(115200);
  
  // Инициализация ИК-приемника
  irrecv.enableIRIn();
  
  Serial.println("IR Receiver is ready");
#endif

#if (MCU_TYPE == 1)
  WiFi.setSleepMode(WIFI_NONE_SLEEP);
#endif

#if (USE_CLOCK == 1 && (MCU_TYPE == 0 || MCU_TYPE == 1))
  rtc.begin();
  if (rtc.lostPower()) { //если не работает убрать ли изменить это
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  DateTime now = rtc.now();
  secs = now.second();
  mins = now.minute();
  hrs = now.hour();
  day = now.day();
  month = now.month();

/*rtc.now() = DateTime now;
now.second() = secs;
now.minute() = mins;
now.hour() = hrs;
now.day() = day;
now.month() = month;
*/
#endif

  // настройки ленты
  FastLED.addLeds<WS2812, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(BRIGHTNES);
  if (CURRENT_LIMIT > 0) FastLED.setMaxPowerInVoltsAndMilliamps(5, CURRENT_LIMIT);
  FastLED.clear();
  FastLED.show();
  randomSeed(analogRead(0) + analogRead(1));    // пинаем генератор случайных чисел
}

void loop() {
  if (button >= 3) {
    button = 0;
  }

  MQTT();


      //AUTOPLAY_PERIOD = 30000;



      //AUTOPLAY_PERIOD = 120;


if (USE_ir == 1) {
if (millis() - ani >= 400) {
customRoutine();
ani = millis();
}




 if (irrecv.decode(&results)) {
  IRWEM1();

 //   IRWEM2();
 }
}
else {
  customRoutine();
}



if (millis() - sad >= 750) {
  Serial.println("...");
  Serial.println(press);
  Serial.println("...");
        Serial.print(hrs);
        Serial.print(":");
        Serial.print(mins);
        Serial.print(":");
        Serial.println(secs);
                Serial.print(day);
        Serial.print(".");
        Serial.println(month);
        sad = millis();
}
autoplayTime = ((long)AUTOPLAY_PERIOD * 1000);

if (button == 2) {
/*  if (press != 0) {
    press = press += 200;
  }
  else if (press == 0) {
    press = 210;
  }
*/
   digitalWrite(ledr, HIGH); 
   digitalWrite(ledg, LOW);
   digitalWrite(ledb, LOW);
  
}

if (button == 1) {
//  press = press += 100;
  digitalWrite(ledb, HIGH);
  digitalWrite(ledr, LOW);
  digitalWrite(ledg, LOW);
}

if (button == 0) {
  digitalWrite(ledg, HIGH);
  digitalWrite(ledr, LOW);
  digitalWrite(ledb, LOW); 
}

}
