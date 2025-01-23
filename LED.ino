




void led500_500() { 
  if (millis() - let >= 500 and jed == false) {
digitalWrite(ledr, HIGH);
digitalWrite(ledg, HIGH);
digitalWrite(ledb, HIGH);
let = millis();
jed = true;
  }
    if (millis() - let >= 500 and jed == true) {
digitalWrite(ledr, LOW);
digitalWrite(ledg, LOW);
digitalWrite(ledb, LOW);
let = millis();
jed = false;
  }
}

void led100_100() { 
  if (millis() - let >= 100 and jed == false) {
digitalWrite(ledr, HIGH);
digitalWrite(ledg, HIGH);
digitalWrite(ledb, HIGH);
let = millis();
jed = true;
  }
    if (millis() - let >= 100 and jed == true) {
digitalWrite(ledr, LOW);
digitalWrite(ledg, LOW);
digitalWrite(ledb, LOW);
let = millis();
jed = false;
  }
}

void led2000_2000() { 
  if (millis() - let >= 2000 and jed == false) {
digitalWrite(ledr, HIGH);
digitalWrite(ledg, HIGH);
digitalWrite(ledb, HIGH);
let = millis();
jed = true;
  }
    if (millis() - let >= 2000 and jed == true) {
digitalWrite(ledr, LOW);
digitalWrite(ledg, LOW);
digitalWrite(ledb, LOW);
let = millis();
jed = false;
  }
}

void led10000_10000() { 
  if (millis() - let >= 10000 and jed == false) {
digitalWrite(ledr, HIGH);
digitalWrite(ledg, HIGH);
digitalWrite(ledb, HIGH);
let = millis();
jed = true;
  }
    if (millis() - let >= 10000 and jed == true) {
digitalWrite(ledr, LOW);
digitalWrite(ledg, LOW);
digitalWrite(ledb, LOW);
let = millis();
jed = false;
  }
}