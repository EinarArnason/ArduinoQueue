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
class Queue {
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
public:
	Queue() {
		head = NULL;
		tail = NULL;
	}

	~Queue() {
		for (Node* node = head; node != NULL; node = head) {
			head = node->next;
			delete node;
		}
	}

	// Returns false if memory is full, otherwise true
	bool enqueue(T item) {
		Node* node = new Node;
		if (node == NULL) {
			return false;
		}

		node->item = item;

		if (head == NULL) {
			head = node;
			tail = node;
			return true;
		}

		tail->next = node;
		tail = node;

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
		if (head == NULL) {
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

		return item;
	}

	bool isEmpty() {
		return head == NULL;
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
		if (head == NULL) {
			return T();
		}

		T item = head->item;

		return item;
	}
};