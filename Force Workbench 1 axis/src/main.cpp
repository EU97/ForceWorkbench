#include <Arduino.h>
#include "HX711.h"

// Definir los pines al que está conectado el HX711
const int pinDato = 15;  // Pin de datos conectado al pin SPIOTX 15
const int pinSCK = 14;   // Pin de reloj (SCK) conectado al SPIOSCK 14

HX711 escala;  // Crear una instancia de la clase HX711

void setup() {
  Serial.begin(9600);  // Inicializar la comunicación serial a 9600 baudios
  escala.begin(pinDato, pinSCK);  // Inicializar la instancia HX711 con los pines especificados
}

void loop() {
  if (escala.is_ready()) {
    // Leer el peso del HX711
    float peso = escala.get_units();
    
    // Mostrar el peso en el monitor serial
    Serial.print("Peso: ");
    Serial.print(peso);
    Serial.println(" g");

    delay(1000); // Esperar 1 segundo antes de la próxima lectura
  } else {
    // Mostrar un mensaje de error si no se puede inicializar el HX711
    Serial.println("Error al inicializar el HX711. Comprueba las conexiones.");
    while (1); // Bucle infinito si hay un error
  }