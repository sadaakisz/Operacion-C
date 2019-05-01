#pragma once
#include "Personaje.h"

class SList {
	struct Node {
		Personaje *pers;
		Node* next;
		Node* prev;

		Node(Personaje *pers = nullptr, Node* next = nullptr, Node* prev = nullptr ): pers(pers), next(next), prev(prev) {
		}
	};
	int length;
	Node* first;
	Node* last;

public:
	SList() : length(0), first(nullptr), last(nullptr) {};
	~SList() {
		Node* aux;
		while (first != nullptr) {
			Node *aux = first;
			first = first->next;
			delete aux;
		}
	};

	bool isEmpty() { return first == nullptr; }
	int size() { return length; }
	void addFirst(Personaje *pers) {
		first = new Node(pers, first, nullptr);
		length++;
	}
	void addLast(Personaje *pers) {
		last = new Node(pers, nullptr, last);
		length++;
	}
	void insert(Personaje *pers, int pos) {
		if (pos == 0) addFirst(pers);
		else if (pos > 0 && pos <= length) {
			Node* aux = first;
			for (int i = 1; i < pos; i++) {
				aux = aux->next;
			}
			aux->next = new Node(pers, aux->next, aux);
			if (pos == length) last = aux->next;
		}
		length++;
	}
	void append(Personaje *pers) {
		insert(pers, length);
	}
	Personaje* getAt(int pos) {
		if (length > 0 || pos < length) {
			Node* aux = first;
			for (int i = 0; i < pos; i++) {
				aux = aux->next;
			}
			return aux->pers;
		}
		cout<<"No se hallo el personaje";
	}
	Personaje* getAt2(int pos) {
		if (length > 0 || pos < length) {
			Node* aux = last;
			for (int i = 0; i < pos; i++) {
				aux = aux->prev;
			}
			return aux->pers;
		}
		cout << "No se hallo el personaje";
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
			else if (pos == length - 1) {
				Node* aux = last;
				last = last->prev;
				delete aux;
			}
			--length;
		}
	}
	void modFirst(Personaje *pers) {
		if (length > 0) {
			Node* aux = first;
			aux->pers = pers;
		}
	}
	void modPos(Personaje *pers, int pos) {
		if (pos == 0) modFirst(pers);
		else if (pos<length&&length > 0) {
			Node* aux = first;
			for (int i = 1; i < pos; i++) {
				aux = aux->next;
			}
			aux->next->pers = pers;
		}
	}
	void modLast(Personaje *pers) {
		if (length > 0) {
			Node* aux = last;
			aux->pers = pers;
		}
	}
	int getFirst() {
		getAt(0);
	}
	int getLast() {
		getAt(length - 1);
	}
	int findPos(Personaje *pers) {
		Node* aux = first;
		int pos = 0;
		while (aux != nullptr) {
			if (aux->pers == pers) {
				return pos;
			}
			++pos;
			aux = aux->next;
		}
		return -1;
	}
};
