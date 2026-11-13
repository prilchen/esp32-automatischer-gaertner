// Pin-Belegung festlegen
const int SENSOR_PIN = 34; // Hier ist der Sensor angeschlossen
const int RELAY_PIN = 23;  // Hier ist das Relais angeschlossen

// Achtung: Viele 3,3V Relais schalten "Active LOW" 
// Das heißt: 0 Volt schaltet das Relais EIN, 3.3 Volt schaltet es AUS.
const int RELAY_ON = LOW;  
const int RELAY_OFF = HIGH; 

// --- KALIBRIERUNG (Bitte mit deinen eigenen Werten anpassen!) ---
const int VAL_DRY = 2500; // Sensorwert an der trockenen Luft (0%)
const int VAL_WET = 600; // Sensorwert im Wasserglas (100%)

// Hysterese: Wann soll gegossen werden?
const int THRESHOLD_ON = 30;  // Pumpe AN, wenn Feuchtigkeit unter 30%
const int THRESHOLD_OFF = 60; // Pumpe AUS, wenn Feuchtigkeit über 60%

// Merkt sich, ob die Pumpe gerade läuft
bool pumpIsRunning = false;

void setup() {
  Serial.begin(115200); // Startet die Ausgabe für den PC

  // Relais-Pin als Ausgang setzen und zur Sicherheit sofort ausschalten
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, RELAY_OFF);

  Serial.println("Prilchen LABS: Automatischer Gärtner gestartet!");
}

void loop() {
  // 1. Rohwert vom Sensor messen
  int rawValue = analogRead(SENSOR_PIN);
  
  // 2. Den Rohwert in saubere 0 bis 100 Prozent umrechnen
  int percent = map(rawValue, VAL_DRY, VAL_WET, 0, 100);
  percent = constrain(percent, 0, 100); // Verhindert Werte wie -5% oder 110%

  // 3. Zur Kontrolle im Seriellen Monitor ausgeben
  Serial.print("Sensor-Rohwert: ");
  Serial.print(rawValue);
  Serial.print(" | Feuchtigkeit in der Erde: ");
  Serial.print(percent);
  Serial.println(" %");

  // 4. Pumpen-Logik (Die Hysterese)
  if (percent < THRESHOLD_ON && !pumpIsRunning) {
    // Erde ist zu trocken -> Pumpe einschalten
    digitalWrite(RELAY_PIN, RELAY_ON);
    pumpIsRunning = true;
    Serial.println("--> Erde zu trocken: Pumpe AN!");
  } 
  else if (percent > THRESHOLD_OFF && pumpIsRunning) {
    // Erde ist nass genug -> Pumpe ausschalten
    digitalWrite(RELAY_PIN, RELAY_OFF);
    pumpIsRunning = false;
    Serial.println("--> Erde nass genug: Pumpe AUS!");
  }

  // 2 Sekunden warten, dann erneut messen
  delay(2000); 
}