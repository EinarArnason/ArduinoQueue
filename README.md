# ArduinoQueue
A lightweight linked list type queue implementation, meant for microcontrollers.
Written as a C++ template class.

## Constructors:
Creates a queue up to *<maximum_number_of_items>* items:
```
DataQueue<T> intQueue(maximum_number_of_items);
```
Creates a queue up to *<maximum_size_in_bytes>* bytes:
```
DataQueue<T> intQueue(0, maximum_size_in_bytes);
```
Creates a queue up to *<maximum_number_of_items>* items or *<maximum_size_in_bytes>* bytes, whatever comes first:
```
DataQueue<T> intQueue(maximum_number_of_items, maximum_size_in_bytes);
```

## How to use:
Include the header file on your code:
```
#include <Queue.h>
```

Then create the queue according to your needs, examples:

* To create a queue of ***int***, capable of holding 20 items:
```
DataQueue<int> intQueue(20);
```

* To create a queue of ***int***, capable of holding 20 items or a maximum size of 10 bytes *(whatever comes first)*:
```
DataQueue<int> intQueue(20, 10);
```

* To create a queue of your ***defined structure***, capable of holding 50 items:
```
struct car {
    char brand[10];
    char model[10];
    int nr_doors;
};
DataQueue<car> myCarsQueue(50);
```

Finally use the following functions:
```
intQueue.enqueue(1);    // Adds number 1 to the queue
intQueue.enqueue(123);    // Adds number 123 to the queue
int number = intQueue.dequeue();    // Will return number 1 and remove it from the queue
int number = intQueue.front();    // Will return number 123 but leave it still in the queue
int number = intQueue.dequeue();    // Will return number 123 and remove it from the queue
```

You can use also the following functions to get more queue properties:
```
bool state = intQueue.isEmpty();    // Returns true if the queue is empty, false otherwise
bool state = intQueue.isFull();    // Returns true if the queue is full, false otherwise
unsigned int n = intQueue.item_count();    // Returns the number of items currently on the queue
unsigned int n = intQueue.item_size();    // Returns the size of the item being stored (bytes)
unsigned int n = intQueue.max_queue_size();    // Returns the maximum possible size of the queue (items)*
unsigned int n = intQueue.max_memory_size();    // Returns the maximum possible size of the queue (bytes)*
```

## Notes
Note that while the Queue class cleans up the nodes in memory after destructor or dequeue is called, it keeps a copy of the item being queued. So for example if you are queuing pointers, you will need to keep track of the memory behind them.

*For example if you create a queue of *int* on an ESP8266, where each *int* has a size of 4 bytes and you specify the queue sizes to be up to 10 items and 10 bytes on the constructor, actually the real values will be 2 items and 8 bytes. These will be the values returned by *max_queue_size()* and *max_memory_size()*.