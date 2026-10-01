#define LED 4
#define BUTTON 5

int ledState = LOW;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);

  Serial.begin(115200);

  digitalWrite(LED, LOW);

  Serial.println("System Ready");
}

void loop()
{
  // Button pressed
  if (digitalRead(BUTTON) == LOW)
  {
    // Toggle LED state
    if (ledState == LOW)
    {
      ledState = HIGH;
      digitalWrite(LED, HIGH);
      Serial.println("LED ON");
    }
    else
    {
      ledState = LOW;
      digitalWrite(LED, LOW);
      Serial.println("LED OFF");
    }

    // Wait until button is released
    while (digitalRead(BUTTON) == LOW)
    {
      delay(10);
    }

    // Debounce
    delay(100);
  }
}
