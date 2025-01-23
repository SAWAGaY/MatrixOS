


void setup_wifi() {
  if (millis() - mqtt >= 10){
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    if (millis() - mqtt2 >= 500){
    Serial.print(".");
    mqtt2 = millis();
    }
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  mqtt = millis();
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  pressu = 200;
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  
  // Преобразуем payload в строку
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  
  Serial.println(message);

    // Проверка, если топик "topic/1" и значение равно "1"
  if (strcmp(topic, "button1") == 0/* && message == "1"*/) {
  press = 1;
  }
    if (strcmp(topic, "button2") == 0/* && message == "1"*/) {
  press = 2;
  }
    if (strcmp(topic, "button3") == 0/* && message == "1"*/) {
  press = 3;
  }
    if (strcmp(topic, "button4") == 0/* && message == "1"*/) {
  press = 4;
  }
    if (strcmp(topic, "button5") == 0/* && message == "1"*/) {
  press = 5;
  FastLED.clear(); 
  gameOverTetris(); 
  newGameTetris(); 
  }
    if (strcmp(topic, "button6") == 0/* && message == "1"*/) {
  press = 6;
  FastLED.clear(); 
  newGameSnake();
  }
    if (strcmp(topic, "button7") == 0/* && message == "1"*/) {
  press = 7;
  FastLED.clear(); 
  }
    if (strcmp(topic, "button8") == 0/* && message == "1"*/) {
  press = 8;
  FastLED.clear(); 
  }
    if (strcmp(topic, "button9") == 0/* && message == "1"*/) {
  press = 9;
  FastLED.clear(); 
  gameOverArkan(); 
  newGameArkan();
  }
    if (strcmp(topic, "button0") == 0/* && message == "1"*/) {
  press = 0;
  ESP.restart();
  }

      if (strcmp(topic, "grid") == 0) {
  press = 11;
  }    if (strcmp(topic, "star") == 0) {
  press = 10;
  }
  /*    if (strcmp(topic, "up") == 0) {
  pressu = 22;
  }    if (strcmp(topic, "down") == 0) {
  pressu = 23;
  }    if (strcmp(topic, "ok") == 0) {
  button = !button;
  Serial.println(button);
  }    if (strcmp(topic, "left") == 0) {
  pressu = 20;
  }    if (strcmp(topic, "right") == 0) {
  pressu = 21;
  }
 */
  
  // Здесь вы можете добавить логику для обработки значений
  // Например, если вам нужно преобразовать строку в число:
  int value = message.toInt();
  Serial.print("Value: ");
  Serial.println(value);
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("WemosMiniClient", mqtt_username, mqtt_password)) {
      Serial.println("connected");
      
      // Подписка на все топики
      for (int i = 0; i < sizeof(topics) / sizeof(topics[0]); i++) {
        client.subscribe(topics[i]);
        Serial.print("Subscribed to: ");
        Serial.println(topics[i]);
      }
    } else if (millis() - mqtt3 >= 5000){
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      mqtt3 = millis();
    }
  }
}

void MQTT() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}