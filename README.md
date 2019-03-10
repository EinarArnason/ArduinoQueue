# ArduinoQueue
A lightweight linked list type queue implementation, meant for microcontrollers.
Written as a C++ template class.

## Constructor:
```
DataQueue<T> intQueue(maximum_number_of_items);
```

## How to use:
Include the header file on your code:
```
#include <Queue.h>
```

Then create the queue according to your needs, examples:

* To create a queue of **int**, capable of holding 20 items:
```
DataQueue<int> intQueue(20);
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
int number = intQueue.dequeue()    // Will return number 1 and remove it from the queue
int number = intQueue.front()    // Will return number 123 but leave it still in the queue
int number = intQueue.dequeue()    // Will return number 123 and remove it from the queue
```

You can use also the following functions for getting queue properties:
```
bool state = intQueue.isEmpty();    // Returns true if the queue is empty, false otherwise
bool state = intQueue.isFull();    // Returns true if the queue is full, false otherwise
uint8_t number = intQueue.count()    // Returns the number of items on the queue
```

## Notes
Note that while the Queue class cleans up the nodes in memory after destructor or dequeue is called, it keeps a copy of the item being queued. So for example if you are queuing pointers, you will need to keep track of the memory behind them.

Note that this library was made in order to be lightweight and the maximum number of items is stored in an 8 bit unsigned number, so the **maximum number of items is 255**. If you wish to have a bigger queue *(be careful with the memory requirements!)* you may change the internal item counters from `uint8_t` *(up to 255 items)* to `uint16_t` *(up to 65.534 items)* or `uint32_t` *(up to 4.294.967.294 items)*