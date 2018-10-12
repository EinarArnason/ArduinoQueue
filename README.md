# ArduinoQueue
A lightweight linked list type queue implementation, meant for microcontrollers.
Written as a C++ template class.

## Example:
`Queue<int> intQueue;`

all the T's will then be replaced by int.

Note that while the Queue class cleans up the nodes in memory after destructor or dequeue is called, it keeps a copy of the item being queued. So for example if you are queuing pointers, you will need to keep track of the memory behind them.
