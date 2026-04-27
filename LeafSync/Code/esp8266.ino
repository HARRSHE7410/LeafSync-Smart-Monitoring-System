#define BLYNK_TEMPLATE_ID "____________"
#define BLYNK_TEMPLATE_NAME "_______"
#define BLYNK_AUTH_TOKEN "_____________"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// WiFi
char ssid[] = "XXXXX";
char pass[] = "YYYYYYYY";

// Pins
#define TOUCH_PIN D2       // GPIO4
#define VIB_PIN   D5       // GPIO14 (for vibration sensor)
#define LED_PIN   D4       // Built-in LED

bool touched = false;
bool vibrated = false;

void setup() {
  Serial.begin(115200);

  pinMode(TOUCH_PIN, INPUT);
  pinMode(VIB_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(LED_PIN, HIGH); // LED OFF

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();

  int touchState = digitalRead(TOUCH_PIN);
  int vibState   = digitalRead(VIB_PIN);

  Serial.print("Touch: ");
  Serial.print(touchState);
  Serial.print(" | Vibration: ");
  Serial.println(vibState);

  // -------- TOUCH SENSOR --------
  if (touchState == HIGH && !touched) {
    touched = true;

    Serial.println("Touch Detected!");

    blinkLED();

    Blynk.logEvent("touch_alert", "Touch detected!");
  }

  if (touchState == LOW) {
    touched = false;
  }

  // -------- VIBRATION SENSOR --------
  if (vibState == HIGH && !vibrated) {
    vibrated = true;

    Serial.println("Vibration Detected!");

    blinkLED();

    Blynk.logEvent("touch_alert", "Vibration detected!");
  }

  if (vibState == LOW) {
    vibrated = false;
  }

  delay(100);
}

// -------- LED BLINK FUNCTION --------
void blinkLED() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(LED_PIN, LOW);   // ON
    delay(200);
    digitalWrite(LED_PIN, HIGH);  // OFF
    delay(200);
  }
}
