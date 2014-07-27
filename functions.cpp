#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <stdio.h> // file
#include <Windows.h> // beep
#include "instuments.h"
#include "stack.h"
#include "Date.h"

using namespace std;

char* Menu() {
	cout << " Choose instrument:" << endl
		<< "-------------------------------------" << endl
		<< "| 1. Strings | 2. Keyboard| 3. Wind |" << endl
		<< "-------------------------------------" << endl;
	int n;
	cin >> n;
	while(cin.fail()) 
		{
			cin.sync();
			cin.clear();
			cout << "Wrong. Try one more" << endl;
			cin >> n;
		} 
	char* p = new char[20];
	switch(n) {
		case 1:
			p = "Strings";
			break;  
		case 2:
			p = "Keyboards";
			break;  
		case 3:
			p = "Wind";
			break;  
		}
	
	return p;
}

void Main() {
	
	Date date("catalog.txt");

	bool profit = true;
	while (profit) {
		cout << "-------------------------------------" << endl
			 << "| 1. New | 2. Open catalog| 3. Exit |" << endl
			 << "-------------------------------------" << endl;
 
		char* _type;  
		int number;
		cin >> number;
		while(cin.fail()) 
		{
			cin.sync(); //atoi itoa
			cin.clear();
			cout << "Wrong. Try one more" << endl;
			cin >> number;
		} 

		switch (number) {
			case 1: 
				_type = Menu();
				date.InputToStack(_type);
				break;
			case 2: 
				date.OutputAll();
				cout << "Sort by type? 1.Yea 2. No" << endl;
				int n;
				cin >> n;
					if (n == 1) {
						_type = Menu();
						date.OutputByType(_type);
					}
				break;
			case 3:
				cout << "Exit";
				date.InputToFile();
				profit = false;
				break;
		} // switch (number)  	
	} // while (profit)
};