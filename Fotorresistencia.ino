int ldrPin=A0; //Pin analógico donde se conecta el ldr
const int ledPin = 4; // Pin PWM donde está conectado el LED
int brightnessLevels[13]; // Arreglo para almacenar los niveles de brillo
int currentLevel = -1; // Variable para almacenar el último nivel seleccionado
#include <Servo.h>

Servo miServo;  // Crear un objeto Servo
int pinServo = 9; // Pin donde está conectado el servo
//const int pinB=3;
void setup() {
  
Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    miServo.attach(pinServo); // Adjuntar el servo al pin definido
 miServo.write(0);

    // Rellenar el arreglo con valores de 0 a 255 en 12 niveles
    for (int i = 0; i <= 12; i++) {
        brightnessLevels[i] = map(i, 0, 12, 0, 255);
    }
    Serial.println("Envia un numero (0-12) para ajustar el brillo del LED.");
//pinMode(pinB,OUTPUT);
}

void loop() {
 int lectura= analogRead(ldrPin);
 Serial.println(lectura); //Muestra valor en el monitor serie
  if (Serial.available() > 0) {
    char comando = Serial.read(); // Leer el comando desde la consola
    
    if (comando == 'a') {
      miServo.write(45); // Mover a 45°
    } else if (comando == 'b') {
      miServo.write(90); // Mover a 90°
    } else if (comando == 'c') {
      miServo.write(180); // Mover a 180°
    }
    else if (comando == 'd') {
      miServo.write(0); // Mover a 0°
    }
        int receivedNumber = Serial.parseInt(); // Leer número del monitor serial

        // Limpiar caracteres residuales en el buffer
        while (Serial.available() > 0) {
            Serial.read();
        }

        if (receivedNumber >= 0 && receivedNumber <= 12) {
            // Solo actualiza si el valor es diferente al actual
            if (receivedNumber != currentLevel) {
                currentLevel = receivedNumber; // Guardar nuevo nivel
                analogWrite(ledPin, brightnessLevels[currentLevel]); // Ajustar brillo
                Serial.print("Brillo ajustado al nivel: ");
                Serial.println(currentLevel);
            }
        } else {
            Serial.println("Número fuera de rango. Ingresa un valor entre 0 y 12.");
        }
    }

// if (Serial.available() > 0) {  // Si hay datos disponibles en el monitor serial
//    int comando = Serial.parseInt(); // Lee el número enviado (1 o 0)
//
//    if (comando == 1) {
//      digitalWrite(pinB, HIGH);  // Enciende la bomba (transistor en ON)
//      Serial.println("Bomba Encendida");
//    } 
//    else if (comando == 0) {
//      digitalWrite(pinB, LOW);  // Apaga la bomba (transistor en OFF)
//      Serial.println("Bomba Apagada");

//}

//}
}
