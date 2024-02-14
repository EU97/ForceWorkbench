#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hx711.h"

#define PIN_DOUT 2  // GPIO2 - Pin conectado a DOUT del HX711
#define PIN_SCK 3   // GPIO3 - Pin conectado a SCK del HX711

int main() {
    stdio_init_all();
    gpio_init(PIN_DOUT);
    gpio_init(PIN_SCK);
    gpio_set_dir(PIN_DOUT, GPIO_IN);
    gpio_set_dir(PIN_SCK, GPIO_OUT);

    // Inicializar el HX711
    hx711_init(PIN_DOUT, PIN_SCK);

    while (1) {
        // Leer valor del sensor
        int32_t weight = hx711_read();

        // Imprimir el valor leído
        printf("Peso: %d\n", weight);

        sleep_ms(1000);  // Esperar 1 segundo
    }

    return 0;
}
