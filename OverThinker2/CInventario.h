#pragma once
#include "CObjeto.h"

class CInventario {
	struct Node {
		CObjeto *obj;
		Node* next;
		Node* prev;

		Node(CObjeto *obj=nullptr, Node* next = nullptr, Node* prev = nullptr)
			:obj(obj), next(next), prev(prev) {}
	};
	int length;
	Node* first;

public:
	CInventario() : length(0), first(nullptr) {}
	CInventario(CObjeto* obj): length(1), first(new Node(obj, first, nullptr)){}
	~CInventario() {
		Node* aux;
		while (first != nullptr) {
			Node *aux = first;
			first = first->next;
			delete aux;
		}
	};

	bool isEmpty() { return first == nullptr; }

	int size() { return length; }

	void addFirst(CObjeto *obj) {
		first = new Node(obj, first, nullptr);
		length++;
	}

	CObjeto* getAt(int pos) {
		if (length > 0 || pos < length) {
			Node* aux = first;
			for (int i = 0; i < pos; i++) {
				aux = aux->next;
			}
			return aux->obj;
		}
		else
			cout << "No se encontro el objeto."<<endl;
	}

	void deleteAt(int pos) {
		if (pos >= 0 && pos < length) {
			if (pos == 0) {
				Node* aux = first;
				first = first->next;
				delete aux;
			}
			else if (pos >= 0 && pos < length - 1) {
				Node* aux = first;
				for (int i = 1; i < pos; i++) {
					aux = aux->next;
				}

				Node* aux2 = aux->next;
				aux->next = aux->next->next;
				delete aux2;
			}
			--length;
		}
	}

	/*void modFirst(int obj) {
		if (length > 0) {
			Node* aux = first;
			aux->obj = obj;
		}
	}

	void modPos(int obj, int pos) {
		if (pos == 0) modFirst(obj);
		else if (pos<length&&length > 0) {
			Node* aux = first;
			for (int i = 1; i < pos; i++) {
				aux = aux->next;
			}
			aux->next->obj = obj;
		}
	}

	void modLast(int obj) {
		if (length > 0) {
			Node* aux = last;
			aux->obj = obj;
		}
	}*/

	int getFirst() {
		getAt(0);
	}

	int getLast() {
		getAt(length - 1);
	}

	/*int findPos(int obj) {
		Node* aux = first;
		int pos = 0;
		while (aux != nullptr) {
			if (aux->obj == obj) {
				return pos;
			}
			++pos;
			aux = aux->next;
		}
		return -1;
	}*/

	void verObjetos() {
		for (short i = 0; i < length; i++) {			
			cout<<this->getAt(i)->getNombre() << endl;
			cout << this->getAt(i)->getTipo() << endl << endl;
		}
	}

};