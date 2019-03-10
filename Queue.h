/*
	Author: Einar Arnason
	email: einsiarna@gmail.com

	A lightweight linked list type queue implementation,
	meant for microcontrollers.
*/

#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

template <typename T>
class DataQueue {
	class Node {
	public:
		T item;
		Node* next;

		Node() {
			next = NULL;
		}

		~Node() {
			next = NULL;
		}
	};
	Node* head;
	Node* tail;
  uint8_t max_items;
  uint8_t items;
public:
	DataQueue(int m_size = 100) {
		head = NULL;
		tail = NULL;
    if (m_size > 255) m_size = 255;
    if (m_size < 0) m_size = 0;
    max_items = m_size;
    items = 0;
	}

	~DataQueue() {
		for (Node* node = head; node != NULL; node = head) {
			head = node->next;
			delete node;
		}
	}

	// Returns false if memory is full, otherwise true
	bool enqueue(T item) {
    if (items == max_items) {
      return false;
    }
    
		Node* node = new Node;
		if (node == NULL) {
			return false;
		}

		node->item = item;

		if (head == NULL) {
			head = node;
			tail = node;
      items++;
			return true;
		}

		tail->next = node;
		tail = node;
    items++;
    
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
		if ((items == 0) || (head == NULL)) {
			return T();
		}

		Node* node = head;
		head = node->next;
		T item = node->item;
		delete node;
		node = NULL;

		if (head == NULL) {
			tail = NULL;
		}

    items--;
		return item;
	}

  /*
		Returns true if the queue
    is empty, false otherwise.
	*/
	bool isEmpty() {
		return head == NULL;
	}
  
  /*
		Returns true if the queue
    is full, false otherwise.
	*/
  bool isFull() {
		return items == max_items;
	}

  /*
		Returns the number of items
    in the queue.
	*/
  uint8_t count() {
    return items;
  }

	/*
		Get the front of the queue.
		Because exceptions are not
		usually implemented for
		microcontrollers, if queue
		is empty, a dummy item is
		returned.
	*/
	T front() {
		if ((items == 0) || (head == NULL)) {
			return T();
		}

		T item = head->item;

		return item;
	}
};