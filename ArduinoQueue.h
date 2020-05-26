/*
        Author: Einar Arnason
        email: einsiarna@gmail.com

        A lightweight linked list type queue implementation,
        meant for microcontrollers.

        Usage and further info:
        https://github.com/EinarArnason/ArduinoQueue
*/

#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#elif defined(ARDUINO) && ARDUINO < 100
#include "WProgram.h"
#endif

template <typename T>
class ArduinoQueue {
  class Node {
   public:
    T item;
    Node *next;

    Node() { next = nullptr; }

    ~Node() { next = nullptr; }
  };

  Node *_head;
  Node *_tail;
  unsigned int _max_items;
  unsigned int _max_memory;
  unsigned int _items_cnt;

 public:
  ArduinoQueue(unsigned int max_items = 100, unsigned int max_memory = 0) {
    _head = nullptr;
    _tail = nullptr;

    /*
            If the max memory has not
            been defined or is 0, then
            the queue size is set by
            the max number of items:
    */
    if (max_memory == 0) {
      _max_items = max_items;
      _max_memory = max_items * sizeof(T);
    }
    /*
            If the max memory has been
            set then the queue size is
            defined by the memory size
            when the max items is 0.
            If the user gave a max item
            size, then the queue size
            will be capped by the number
            of items.
    */
    else {
      _max_items = max_memory / sizeof(T);
      _max_memory = _max_items * sizeof(T);
      if (max_items != 0) {
        if (_max_items > max_items) _max_items = max_items;
      }
    }
    _items_cnt = 0;
  }

  ~ArduinoQueue() {
    for (Node *node = _head; node != nullptr; node = _head) {
      _head = node->next;
      delete node;
    }
  }

  /*
          Push an item to the queue.
          Returns false if memory is
          full, or true if the item
          was added to queue.
  */
  bool enqueue(T item) {
    if (_items_cnt == _max_items) {
      return false;
    }
    Node *node = new Node;
    if (node == nullptr) {
      return false;
    }

    node->item = item;

    if (_head == nullptr) {
      _head = node;
      _tail = node;
      _items_cnt++;
      return true;
    }

    _tail->next = node;
    _tail = node;
    _items_cnt++;
    return true;
  }

  /*
          Pop the front of the queue.
          Because exceptions are not
          usually implemented for
          microcontrollers, if queue
          is empty, a dummy item is
          returned.
  */
  T dequeue() {
    if ((_items_cnt == 0) || (_head == nullptr)) {
      return T();
    }

    Node *node = _head;
    _head = node->next;
    T item = node->item;
    delete node;
    node = nullptr;

    if (_head == nullptr) {
      _tail = nullptr;
    }

    _items_cnt--;
    return item;
  }

  /*
          Returns true if the queue
          is empty, false otherwise.
  */
  bool isEmpty() { return _head == nullptr; }

  /*
          Returns true if the queue
          is full, false otherwise.
  */
  bool isFull() { return _items_cnt == _max_items; }

  /*
          Returns the number of items
          currently in the queue.
  */
  unsigned int item_count() { return _items_cnt; }

  /*
          Returns the size of the
          queue item in bytes.
  */
  unsigned int item_size() { return sizeof(T); }

  /*
          Returns the size of the queue
          (maximum number of items)
  */
  unsigned int max_queue_size() { return _max_items; }

  /*
          Returns the size of the queue
          (maximum size in bytes)
  */
  unsigned int max_memory_size() { return _max_memory; }

  /*
          Get the item in the front
          of the queue.
          Because exceptions are not
          usually implemented for
          microcontrollers, if queue
          is empty, a dummy item is
          returned.
  */
  T head() {
    if ((_items_cnt == 0) || (_head == nullptr)) {
      return T();
    }

    T item = _head->item;
    return item;
  }

  T tail() {
    if ((_items_cnt == 0) || (_head == nullptr)) {
      return T();
    }

    T item = _tail->item;
    return item;
  }

  T front() { return head(); }
};
