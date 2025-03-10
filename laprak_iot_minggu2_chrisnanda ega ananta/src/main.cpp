#include <Arduino.h>

int tombolMerah  = 34;
int tombolKuning = 26;
int tombolHijau  = 13;

int ledMerah  = 19;
int ledKuning = 16;
int ledHijau  = 15;

bool lastStateMerah = HIGH;

void setup() {
    pinMode(tombolMerah, INPUT_PULLUP);
    pinMode(tombolKuning, INPUT_PULLUP);
    pinMode(tombolHijau, INPUT_PULLUP);

    pinMode(ledMerah, OUTPUT);
    pinMode(ledKuning, OUTPUT);
    pinMode(ledHijau, OUTPUT);

    Serial.begin(115200);
}

void loop() {
    bool currentStateMerah = digitalRead(tombolMerah);
    
    // Cek apakah tombol merah ditekan (LOW) dan sebelumnya dalam keadaan tidak ditekan (HIGH)
    if (currentStateMerah == LOW && lastStateMerah == HIGH) {
        Serial.println("Tombol Merah Ditekan, LED Merah Berkedip 5 Kali");
        for (int i = 0; i < 5; i++) {
            digitalWrite(ledMerah, HIGH);
            delay(500);
            digitalWrite(ledMerah, LOW);
            delay(500);
        }
    }

    lastStateMerah = currentStateMerah;  // Simpan status terakhir tombol merah

    if (digitalRead(tombolKuning) == LOW) {
        for (int i = 0; i < 5; i++) {
            digitalWrite(ledMerah, HIGH);
            digitalWrite(ledKuning, LOW);
            delay(500);
            digitalWrite(ledMerah, LOW);
            digitalWrite(ledKuning, HIGH);
            delay(500);
        }
        digitalWrite(ledKuning, LOW);
    }

    if (digitalRead(tombolHijau) == LOW) {
        for (int i = 0; i < 5; i++) {
            digitalWrite(ledMerah, HIGH);
            digitalWrite(ledKuning, LOW);
            digitalWrite(ledHijau, LOW);
            delay(300);
            digitalWrite(ledMerah, LOW);
            digitalWrite(ledKuning, HIGH);
            delay(300);
            digitalWrite(ledKuning, LOW);
            digitalWrite(ledHijau, HIGH);
            delay(300);
            digitalWrite(ledHijau, LOW);
        }
    }
}
