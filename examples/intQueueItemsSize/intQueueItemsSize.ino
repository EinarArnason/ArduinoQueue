/*
        Author: Vasco Baptista
        email: vascojdb@gmail.com

        An example of using Einar Arnason's queue
        In this example we create a queue of int's
        limited by the maximum amount of items

        Usage and further info:
        https://github.com/EinarArnason/ArduinoQueue
*/

#include "Queue.h"

#define QUEUE_SIZE_ITEMS 10

// Queue creation:
ArduinoQueue<int> intQueue(QUEUE_SIZE_ITEMS);

void printQueueStats() {
  Serial.println("");
  Serial.printf("Size of each element:    %u bytes\r\n", intQueue.item_size());
  Serial.printf("Items in queue now:      %u items\r\n", intQueue.item_count());
  Serial.printf("Queue actual max items:  %u items\r\n",
                intQueue.maxQueueSize());
  Serial.printf("Queue actual max memory: %u bytes\r\n",
                intQueue.maxMemorySize());
  Serial.println("");
}

void setup() {
  Serial.begin(115200);
  Serial.println("");
  Serial.println("========== Queue example ==========");
  Serial.printf("Desired max item size:  %u items\r\n", QUEUE_SIZE_ITEMS);
  Serial.println("===================================");
}

void loop() {
  printQueueStats();

  // Add elements: (add more than the queue size for demo purposes)
  for (int n = 1; n < QUEUE_SIZE_ITEMS + 5; n++) {
    if (!intQueue.isFull()) {
      Serial.printf("Adding value: %i\r\n", n);
      intQueue.enqueue(n);
    } else {
      Serial.println("Queue is full!");
    }
  }

  printQueueStats();

  // Remove elements: (remove more than the queue size for demo purposes)
  for (int n = 1; n < QUEUE_SIZE_ITEMS + 5; n++) {
    if (!intQueue.isEmpty()) {
      int value = intQueue.dequeue();
      Serial.printf("Removed value: %i\r\n", value);
    } else {
      Serial.println("Queue is empty!");
    }
  }

  printQueueStats();

  // Loop forever
  while (true) {
#ifdef ESP8266
    ESP.wdtFeed();
#endif
  }
}
