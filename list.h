/*
List class

Written by Bernhard Firner
*/

#ifndef __LIST_H__
#define __LIST_H__

#include "node.h"

template <typename T>
class LList {

protected:

	Node<T>* head;
	Node<T>* tail;


public:

	LList() {
		head = nullptr;
		tail = nullptr;
	}
	
	 LList(const LList& other) {

		 std::cout << "Inside copy constructor\n";
		 Node<T>* orig = nullptr;
		 Node<T>* copy = nullptr;
		 if (other.head == nullptr) {
			 head = nullptr;
			 std::cout << "Inside if loop\n";
		 }
		 else {
			 head = new Node<T>();
			 head->setVal(other.head->getVal());
			 head->setPrev(other.head->getPrev());
			 head->setNext(other.head->getNext());
			 orig = head;
			 copy = other.head->getNext();
			 std::cout << "Inside else loop\n";
		 }

		 while (copy) {
			 std::cout << "Inside while loop\n";
			 Node<T>* temp = new Node<T>();
			 temp->setVal(copy->getVal());
			 temp->setPrev(copy->getPrev());
			 temp->setNext(copy->getNext());
			 orig->insert(temp);
			 copy = copy->getNext();
		 }
		
	}

	~LList() {
		//Keep deleting the second node until there is only one node (the head)
		while (nullptr != head->getNext()) {
			delete head->getNext();
		}
		//Now delete the head
		delete head;

		/*
		//Here is another way to delete all of the nodes
		Node<T>* target = head;
		while (nullptr != target) {
		Node<T>* next = target->getNext();
		delete target;
		target = next;
		}
		*/
	}

	void push_back(T val) {
		Node<T>* n = new Node<T>(val);
		if (nullptr == head) {
			head = n;
			tail = n;
		}
		else {
			tail->insert(n);
			tail = n;
		}
	}

	void push_front(T val) {
		Node<T>* n = new Node<T>(val);
		if (nullptr == head) {
			head = n;
			tail = n;
		}
		else {
			head->insertBefore(n);
			head = n;
		}
	}
	
	//Overloading = operator for the copy constructor

	LList& operator=(const LList& other){
		std::cout << "Inside list assign\n";
		head = other.head;
		tail = other.tail;
		return *this;

	}


	//friend class iterator;
	//Iterator class for the linked list
	class iterator {
	private:
		Node<T>* location;
		LList* container;
	public:
		//Remember the kind of thing this iterator will fetch with operator*
		typedef T value_type;

	
		//The iterator starts at some node
		iterator(Node<T>* start, LList* container) {
			location = start;
			iterator::container = container;
		}

		//prefix operator--
		iterator& operator--() {
			//If we are at the end then go to the tail (the last element)
			if (nullptr == location) {
				location = container->tail;
			}
			else {
				if (nullptr != location->getPrev()) {
					location = location->getPrev();
				}
				//otherwise we should really throw an exception because we can't go before the beginning
			}
			return *this;
		}

		//prefix operator++
		iterator& operator++() {
			if (nullptr != location) {
				location = location->getNext();
			}
			return *this;
		}

		//postfix operator++
		iterator operator++(int unused) {
			iterator cur = *this;
			++(*this);
			return cur;
		}

		T& operator*() {
			if (nullptr != location) {
				return location->getVal();
			}
		}

		bool operator!=(const iterator& other) {
			if (container != other.container) {
				//Then throw an exception and make your program crash
			}
			return location != other.location;
		}

	};

	//begin and end iterator functions
	iterator begin() {
		return iterator(head, this);
	}

	iterator end() {
		return iterator(nullptr, this);
	}
};



#endif
