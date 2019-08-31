#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "AC101.h"
#include "FaustSawtooth.h"

FaustSawtooth faustSawtooth(48000,8);                           // create instance of FaustSawtooth

AC101 ac;                                                       // create instance of AC101

static uint8_t volume = 30;
const uint8_t volume_step = 2;

void setup() {
  Serial.begin(115200);

  Serial.printf("Connect to AC101 codec... ");
  while (not ac.begin())                                        // loop until ac.begin returns ESP_OK == false
  {
    Serial.printf("Failed!\n");
    delay(1000);
  }
  Serial.printf("OK\n");

  ac.SetVolumeSpeaker(volume);
  ac.SetVolumeHeadphone(volume);
  
  //ac.DumpRegisters();
  
  faustSawtooth.start();                                        // start faust dsp 
}

void loop()
{
  
  faustSawtooth.setParamValue("freq",rand()%(2000-50 + 1) + 50);
  delay(1000);

}
