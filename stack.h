#ifndef STACK_H_
#define STACK_H_
#include "stdafx.h"
#include <iostream>
#include "instuments.h"

using namespace std;

class Stack {
	
	struct Item {	
		Instrument* value;
		Item* prev;
	};

	Item *Begin;
	Item *End; 

public:

	int size; 
	Stack(Instrument *_value) {
		Begin = new Item;
		Begin->value = _value;
		Begin->prev = NULL;
		End = Begin;
		size = 0;
	};

	~Stack() {
		Item *item;
		item = End;
		while (item != NULL) {
			End = item->prev;
			delete item;
			item = End;
		};
	};

	void push(Instrument *_value) {
		Item *item = new Item;
		item->prev = End; 
		item->value = _value; 
		End = item;
		size++;
 	}

	Instrument* shift() { 
		Instrument* value = End->value;
		End = End->prev;
		return value;
	}

	Instrument* operator[] (int index) {
		int i = 0;
		Item* result = 0;
		Item* p = End;
		while (p != Begin) {
			if ((size - i) == index) {
				result = p;
				break;
			}
			p = p->prev;
			++i;
		} 

		if (result == 0) cout << "ERROR!! OUT OF RANGE" << endl;
		return result->value;
	}
};

#endif // STACK_H_