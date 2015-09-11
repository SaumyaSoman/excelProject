#ifndef LLIST_CPP
#define LLIST_CPP

#include <iostream>

template <typename T>
class Node {
public:
	//The value
	T val;
	//The pointers to next and previous nodes
	Node<T>* next;
	Node<T>* prev;

	Node(){
		next = nullptr;
		prev = nullptr;
	};

	//Initialize with the stored value
	Node(T value) {
		val = value;
		next = nullptr;
		prev = nullptr;
	}

	//copy constructor
	Node(Node& other){
		val = other.val;
		next = other.next;
		prev = other.prev;
	}

	Node& operator=(Node& other){
		val = other.val;
		next = other.next;
		prev = other.prev;
		return *this;
	}

	//Return a reference so that the value can be modified
	T& getVal() {
		return val;
	}

	//Insert a new node after this one
	void insert(Node* n) {
		//Fix the link between the new node and next
		if (nullptr != next) {
			next->prev = n;
		}
		n->next = next;

		//Fix the link from this node to the next one
		n->prev = this;
		next = n;
	}

	//Insert a new node before this node
	//Return a pointer to the new node
	Node* insertBefore(Node* n) {
		//Fix the link between prev and the new node
		if (nullptr != prev) {
			prev->next = n;
		}
		n->prev = prev;

		//Fix the link from this node to the new one
		n->next = this;
		prev = n;
	}

	~Node() {
		if (nullptr != prev) {
			prev->next = next;
		}
		if (nullptr != next) {
			next->prev = prev;
		}
	}

	Node* getNext() {
		return next;
	}

	Node* getPrev() {
		return prev;
	}
};

template <typename T>
class LList {
private:
	Node<T> *head;
	Node<T> *tail;

public:
	LList() {
		head = nullptr;
		tail = nullptr;
	}

	LList(T& other){

		cout << "inside copy const LList " << endl;
		Node<T> * p1 = nullptr;
		Node<T> * p2 = nullptr;

		cout << "inside copy const LList again " << endl;
		if (other.head == nullptr){
			cout << "inside copy const LList else loop " << endl;
			head = nullptr;
		}
		else{
			head = new Node<T>();
			head->val = other.head->val;
			head->next = other.head->next;
			head->prev = other.head->prev;

			p1 = head;
			p2 = other.head->next;
		}

		while (p2){
			p1->next = new Node<T>();
			p1 = p1->next;
			p1->val = p2->val;
			p1->next = p2->next;
			p1->prev = p2->prev;

			p2 = p2->next;
		}
	}

	LList<T>& operator=(LList<T>& other){
		head = other.head;
		tail = other.tail;

		return *this;
	}

	void push_back(T val) {

		Node<T>* n = new Node<T>(val);

		if (nullptr == head) {
			head = n;
			tail = head;
		}
		else {
			tail->insert(n);
			tail = n;
		}
	}

	int size(){
		int length = 0;
		Node<T>* node = this->head;
		while (node != NULL)
		{
			++length;
			node = node->next;
		}
		return length;
	}

	Node<T>* getHead(){
		return head;
	}

	void setHead(Node<T> * newHead){
		head = newHead;
	}

	class iterator {
	private:
		Node<T>* location;
	public:
		//Define the value_type. This helps with other templates.
		typedef T value_type;

		//Constructor
		iterator(Node<T>* start) {
			location = start;
		}

		//Increment operator: prefix version
		iterator& operator++() {
			//We should throw an error here, but for simplicity we'll just stop
			//at the end of the list. To learn more, read about exceptions.
			if (nullptr != location) {
				location = location->getNext();
			}
			//Return a reference to this iterator, so use * to convert from a pointer
			return *this;
		}

		//Increment operator: postfix version
		//The postfix version is distinguished by an unnused integer argument
		iterator operator++(int unnused) {
			iterator copy = *this;
			++(*this);
			//Return the copy that is still in the previous location
			return copy;
		}

		//to return distant location in list
		iterator& operator+(int offset) {
			for (int i = 0; i < offset; i++){
				//cout << (*location)->getValue() << " ";
				location = location->getNext();
			}
			//Return a reference to this iterator, so use * to convert from a pointer
			return *this;
		}


		//operator* will get a reference to the value at the iterator's location
		T& operator*() {
			//If we are at the end then we cannot return a value
			if (nullptr != location) {
				return location->getVal();
			}
			//Again, we should throw an exception to be "correct" here, but for
			//simplicity we will do nothing
		}

		//operator!= checks if two iterators are at the same location
		//Takes a const iterator& to guarantee we will not modify the other iterator
		bool operator!=(const iterator& other) {
			return location != other.location;
		}

		//Get the distance from one iterator to another
		int operator-(const iterator& other) {
			//Easily defined as a recursive function
			if (*this != other) {
				return 1 + (++(*this) - other);
			}
			else {
				return 0;
			}
		}
	};

	//Return an iterator to the beginning
	iterator begin() {
		return iterator(head);
	}

	//Return one past the last element
	iterator end() {
		return iterator(nullptr);
	}
};
#endif LLIST_CPP