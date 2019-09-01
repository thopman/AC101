/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "esp_spi_flash.h"
#include "AC101.h"
#include "FaustSawtooth.h"
#include "sdkconfig.h"



extern "C" {
    void app_main(void);
}

void app_main(void)
{
  AC101 ac101;
  ac101.begin();

  int SR = 48000;
  int BS = 8;

  FaustSawtooth faustSawtooth(SR,BS);
  faustSawtooth.start();
  
    while(1) {
    faustSawtooth.setParamValue("freq",rand()%(2000-50 + 1) + 50);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
