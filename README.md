# ArduinoQueue

[![Build Status](https://travis-ci.org/EinarArnason/ArduinoQueue.svg?branch=dev)](https://travis-ci.org/EinarArnason/ArduinoQueue)

A lightweight linked list type queue implementation, meant for microcontrollers.
Written as a C++ template class.

## Constructors

Creates a queue up to _<maximum_number_of_items>_ items:

```C++
ArduinoQueue<T> intQueue(maximum_number_of_items);
```

Creates a queue up to _<maximum_size_in_bytes>_ bytes:

```C++
ArduinoQueue<T> intQueue(0, maximum_size_in_bytes);
```

Creates a queue up to _<maximum_number_of_items>_ items or _<maximum_size_in_bytes>_ bytes, whatever comes first:

```C++
ArduinoQueue<T> intQueue(maximum_number_of_items, maximum_size_in_bytes);
```

## How to use

Include the header file on your code:

```C++
#include <ArduinoQueue.h>
```

Then create the queue according to your needs, examples:

- To create a queue of **_int_**, capable of holding 20 items:

```C++
ArduinoQueue<int> intQueue(20);
```

- To create a queue of **_int_**, capable of holding 20 items or a maximum size of 10 bytes _(whatever comes first)_:

```C++
ArduinoQueue<int> intQueue(20, 10);
```

- To create a queue of your **_defined structure_**, capable of holding 50 items:

```C++
struct car {
    char brand[10];
    char model[10];
    int nr_doors;
};
ArduinoQueue<car> myCarsQueue(50);
```

Finally use the following functions:

```C++
intQueue.enqueue(1);    // Adds number 1 to the queue
intQueue.enqueue(123);    // Adds number 123 to the queue
int number = intQueue.dequeue();    // Will return number 1 and remove it from the queue
int number = intQueue.getHead();    // Will return number 123 but leave it still in the queue
int number = intQueue.dequeue();    // Will return number 123 and remove it from the queue
```

You can use also the following functions to get more queue properties:

```C++
bool state = intQueue.isEmpty();    // Returns true if the queue is empty, false otherwise
bool state = intQueue.isFull();    // Returns true if the queue is full, false otherwise
unsigned int n = intQueue.itemCount();    // Returns the number of items currently on the queue
unsigned int n = intQueue.itemSize();    // Returns the size of the item being stored (bytes)
unsigned int n = intQueue.maxQueueSize();    // Returns the maximum possible size of the queue (items)*
unsigned int n = intQueue.maxMemorySize();    // Returns the maximum possible size of the queue (bytes)*
```

## Thread safety

This library is **not** thread safe. Mutexes are often hardware specific on the way they are optimized to operate. So for the sake of performance and portability, it is left out.

## Memory safety

The memory for the queue nodes are dynamically allocated. Note that while the Queue class cleans up the nodes in memory after destructor or dequeue is called, it keeps a copy of the item being queued. So for example if you are queuing pointers, you will need to keep track of the memory behind them.

## Performance

CPU: Intel i7-6500U  
RAM: DDR4L

Benchmark result (1000 samples):  
Enqueued 1000000 ints in average 0.018749799 seconds  
Dequeued 1000000 ints in average 0.016496857 seconds  
Allocated 15.2588 MB (16 bytes per item)
