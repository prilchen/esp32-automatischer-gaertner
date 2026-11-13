# 🌱 Automatischer Gärtner – ESP32 Pflanzenbewässerung

Dieses Projekt ermöglicht eine automatische Bewässerung von Zimmerpflanzen mit einem ESP32.

Ein kapazitiver Bodenfeuchtesensor misst kontinuierlich die Feuchtigkeit der Erde. Wird ein bestimmter Trockenheitswert unterschritten, aktiviert der ESP32 über ein Relais eine kleine Wasserpumpe.

## Benötigte Hardware

- ESP32 Entwicklungsboard
- Kapazitiver Bodenfeuchtesensor V1.2
- 3,3-V-kompatibles Relaismodul
- 5-V-Mini-Tauchpumpe
- Freilaufdiode (z. B. 1N4007)
- 5-V-Netzteil

## GPIO-Belegung

| Bauteil | ESP32 |
|---|---|
| Bodenfeuchtesensor | GPIO 34 |
| Relais | GPIO 23 |

## Installation

1. Arduino IDE öffnen.
2. Datei `Automatischer_Gaertner.ino` herunterladen.
3. Sketch in der Arduino IDE öffnen.
4. Die beiden Kalibrierungswerte `VAL_DRY` und `VAL_WET` an den eigenen Sensor anpassen.
5. ESP32 auswählen und Sketch hochladen.

## Kalibrierung

Die Sensorwerte müssen individuell ermittelt werden.

- `VAL_DRY`: Messwert des trockenen Sensors.
- `VAL_WET`: Messwert des nassen Sensors.

## Weitere Informationen

Die vollständige Bauanleitung mit Schaltplan, Erklärungen und Kalibrierung findest du hier:

https://prilchen.de/smarte-pflanzenbewaesserung-leicht-gemacht-der-automatische-gaertner/

Viel Spaß beim Nachbauen!

**Prilchen Labs**
https://prilchen.de
