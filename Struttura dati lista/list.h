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

	void insertInOrder(T value) {
		Node<T> * temp = new Node<T>(value);
		if(head == NULL) {
			this->insert(temp);
			return;
		}
		if(head->getValue() >= value) {
			temp->setNext(head);
			head = temp;
			length++;
			return;
		}

		Node<T> * prev = head;
	       	Node<T>	* current = head->getNext();

		while(current != NULL) {
			if(prev->getValue() < value && current->getValue() >= value) {
				prev->setNext(temp);
				temp->setNext(current);
				length++;
				return;
			}
			else {
				prev = current;
				current = current->getNext();
			}
		}

		prev->setNext(temp);
		length++;
		return;
	}

	bool search(T value) {
		if(head == NULL) {
			return false;
		}

		Node<T> * temp = head;
		while(temp != NULL) {
			if(temp->getValue() == value)
				return true;

			temp = temp->getNext();
		}

		return false;
	}

	Node<T> * deleteNode(T value) {
		if(this->search(value)) {
			if(head->getValue() == value) {
				Node<T> * temp = head;
				head = head->getNext();
				length--;
				return temp;
			}
			Node<T> * prev = head;
			Node<T> * current = head->getNext();
			while(current != NULL) {
				if(current->getValue() == value) {
					prev->setNext(current->getNext());
					length--;
					return current;
				}
				prev = current;
				current = current->getNext();
			}
		}

		return NULL;
	}


    //PROVA IMPLEMENTAZIONE SELECTION SORT (Errore stack overflow. Programma ritorna -1073741819)
	void selectionSort(bool cd){
        //Node<T> *p = head;
        selectionSort(cd, length);
	}
     //Node<T> *selection
	void selectionSort(bool cd, int s){
        if(cd == true){
            if(s == 1){
                return;
            }
            cout<< "ciao";
            Node<T> *max = head;
            Node<T> *current = head->getNext();
            T tmp;
            int i= 1;
            while(i < s){
                if(current->getValue() > max->getValue()){
                    max = current;
                }
                current = current->getNext();
                i++;
                cout<< i;
            }
            cout<< "s4";
            tmp = max->getValue();
            max->setValue(current->getValue());
            current->setValue(tmp);
            //cout<< "ciao";
            selectionSort(1, --s);
        }
	}

	int getLength() {
		return this->length;
	}


	void bubbleSort(bool cd){ // cd TRUE = Ordinamento crescente   cd FALSE = Ordinamento dcrescente
        bool ord = true;
        while(ord == true){
            ord = false;
            Node<T> *previous = head;
            Node<T> *current = previous->getNext();
            T tmp;
            while(current != NULL && cd){
                if(previous->getValue() > current->getValue()){
                    tmp = previous->getValue();
                    previous->setValue(current->getValue());
                    current->setValue(tmp);
                    ord = true;
                }
                previous = current;
                current = current->getNext();
            }
            while(current != NULL &&  cd == false ){
                if(previous->getValue() < current->getValue()){
                    tmp = previous->getValue();
                    previous->setValue(current->getValue());
                    current->setValue(tmp);
                    ord = true;
                }
                previous = current;
                current = current->getNext();
            }
        }
        return;
    }

	friend ostream& operator<<(ostream& out, const List<T>& l) {
		out << "Lista di lunghezza " << l.length << " head = " << l.head << endl;
		Node<T> * current = l.head;
		while(current != NULL) {
			out << "\t" << current->toString() << endl;
			current = current->getNext();
		}
		return out;
	}
};

#endif
