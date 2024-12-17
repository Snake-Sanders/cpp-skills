#include "pico/stdlib.h"

#include "hardware/gpio.h"
#include "pico/binary_info.h"
#include <stdio.h>

const uint LED_PIN = 17;

int main() {
  stdio_init_all();
  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);

  while (1) {
    gpio_put(LED_PIN, 1);
    sleep_ms(300);
    gpio_put(LED_PIN, 0);
    sleep_ms(300);
    gpio_put(LED_PIN, 1);
    sleep_ms(300);
    gpio_put(LED_PIN, 0);
    sleep_ms(5000);
  }
}
