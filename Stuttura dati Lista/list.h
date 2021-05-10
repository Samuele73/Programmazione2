#ifndef LIST_H
#define LIST_H

#include "node.h"

using namespace std;

template<class T>
class List {
	Node<T> * head;
	int length;

	public:

	List(Node<T> * head) : head(head), length(0) {}
	List() : List(NULL) {}

	void insert(Node<T> * n) {
		if(head == NULL) {
			head = n;
			length++;
			return;
		}

		Node<T> * current = head;
		while(current->getNext() != NULL) {
			current = current->getNext();
		}
		current->setNext(n);
		length++;
	}

	void insert(T value) {
		Node<T> * temp = new Node<T>(value);
		this->insert(temp);
	}

	void deleteNode(int i){
		if(i>=0 && i<length){
		    Node<T> *current = head;
		    if(i == 0){
			head = head->getNext();
			delete current;
			length--;
			return;
		    }
		    Node<T> *previous = head;
		    current = current->getNext();
		    for(int j=1; j<i; j++){

			current = current->getNext();
			previous = previous->getNext();
		    }
		    previous->setNext(current->getNext());
		    delete current;
		    length--;
		    return;
		}
		else{
		    cout<< "Indice fuori dalla lista. Reinseliscilo!"<< endl;
		    cin>> i;
		    cout<< endl;
		    deleteNode(i);
		    return;
		}
	}



	int getLength() {
		return this->length;
	}

	Node<T> * getHead() {
		return this->head;
	}

	friend ostream& operator<<(ostream& out, const List<T>& l) {
		out << "Lista head = " << l.head << endl;
		Node<T> * current = l.head;
		while(current != NULL) {
			out << "\t" << current->toString() << endl;
			current = current->getNext();
		}
		return out;
	}
};

#endif
