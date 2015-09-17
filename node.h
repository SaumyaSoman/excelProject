/*
Node.h
Node class for a linked list

Written by Bernhard Firner
*/

//Preprocessor guards
#ifndef __NODE_H__
#define __NODE_H__

template <typename T>
class Node {
private:
	//The value being held
	T val;
	//Pointers to the next and previous nodes
	Node<T>* next;
	Node<T>* prev;
public:
	//Constructor
	Node() {
		next = nullptr;
		prev = nullptr;
	}

	Node(T val) {
		Node::val = val;
		next = nullptr;
		prev = nullptr;
	}
	
	Node(const Node& other) {
		std::cout << "Inside node copy\n";
		val = other.val;
		next = other.next;
		prev = other.prev;
	}

	Node& operator=(const Node& other) {
		std::cout << "Inside node assign\n";
		val = other.val;
		next = other.next;
		prev = other.prev;
		return *this;
	}

	//Return a reference to the value
	T& getVal() {
		return val;
	}

	void insert(Node* n) {
		if (nullptr != next) {
			next->prev = n;
		}
		n->next = next;

		n->prev = this;
		next = n;
	}

	void insertBefore(Node* n) {
		if (nullptr != prev) {
			prev->next = n;
		}
		n->prev = prev;

		n->next = this;
		prev = n;
	}

	Node* getPrev() {
		return prev;
	}

	Node* getNext() {
		return next;
	}

	void setNext(Node * next) {
		Node::next = next;
	}
	void setPrev(Node* prev) {
		Node::prev = prev;
	}

	void setVal(T val) {
		Node::val = val;
	}

	~Node() {
		//Clean up the links
		if (nullptr != next) {
			next->prev = prev;
		}
		if (nullptr != prev) {
			prev->next = next;
		}
	}

};

#endif
