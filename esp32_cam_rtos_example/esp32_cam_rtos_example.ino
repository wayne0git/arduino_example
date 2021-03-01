// Use only single core for demo
#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif

// Pins
static const int led_pin = 33;  // ESP32-CAM Builtin LED Pin

// Task: Blink LED
// For RTOS, function should return void and accept void pointer
void toggleLED(void* parameter){
  // Use non-blocking delay
  while(1){
    digitalWrite(led_pin, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS); // since timing unit for RTOS is tick
    digitalWrite(led_pin, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);    
  }
}

void setup() {
  // Configure pin
  pinMode(led_pin, OUTPUT);

  // Task to run forever
  xTaskCreatePinnedToCore(  // Use xTaskCreate() in vanilla FreeRTOS
              toggleLED,    // Task function
              "Toggle LED", // Task name
              1024,         // Stack size (unit: byte in ESP32, word in vanilla FreeRTOS)
              NULL,         // Parameter to pass to task function
              1,            // Task priority (Higher => High priority) (0 ~ configMax_PRIORITIES - 1 = 24)
              NULL,         // Task handle. Used when deal with other tasks.
              app_cpu);     // Run on single core for demo

  // If this was vanilla FreeRTOS, you'd want to call vTaskStartScheduler() in main after setting up the taks
}       

void loop() {
  // put your main code here, to run repeatedly:

}
