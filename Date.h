#ifndef DATE_H_
#define DATE_H_

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <stdio.h> // file
#include <io.h> // access
#include <Windows.h> // beep
#include "instuments.h"
#include "stack.h"

using namespace std;

class Date {
   
	Stack S;
	int count;
	char file[100];

public:	
	
	Date (const char* _file) : S(0), count(1) {
		strcpy(file, _file);

		char temp[15];
		char buf[100];
		int value;
		if (access(filename, 0) == -1) {
			cout << "Create catalog at first." << endl;
		}
		else {
			FILE* pfile = fopen(file, "r");
			while (!feof(pfile)) {
				fscanf(pfile, "%s %s %d\n", temp, buf, &value);
			
					Instrument* ins;

					if (strcmp(temp, "Keyboards") == 0) {
						ins = new Keyboards;
					}
					if (strcmp(temp, "Strings") == 0) {
						ins = new Strings;
					}
					if (strcmp(temp, "Wind") == 0) {
						ins = new Wind;
					}
					ins->sound = value;
					strcpy (ins->type, temp);
					strcpy (ins->name, buf);
					S.push(ins);
					count++;
				} // while
		fclose(pfile);
		} // else
	}

	void OutputAll() {
		
		for (int j = 1; j < count; j++) {
			cout << j << ". " << S[j]->type << " " << S[j]->name << " " << S[j]->sound << endl;
		}

		cout << "Choose instrument:" << endl; 
		int _sound;
		cin >> _sound;
		while(cin.fail()) 
		{
			cin.sync();
			cin.clear();
			cout << "Wrong. Try one more" << endl;
			cin >> _sound;
		} 
		
		if (_sound > count + 1) {
			cout << "Out of range" << endl;
		}
		else {
			S[_sound]->Sound(S[_sound]->sound);
		}
	}

	void InputToStack(const char* _type) {
		
		char _name[100];
		int _sound;

		cout << "Enter name" << endl;
		cin >>  _name;
		cout << "Enter sound" << endl; 
		cin >> _sound;
		while(cin.fail()) 
		{
			cin.sync();
			cin.clear();
			cout << "Wrong. Try one more" << endl;
			cin >> _sound;
		} 
		
		Instrument* ins;

			if (strcmp(_type, "Keyboards") == 0) {
				ins = new Keyboards;
			}
			if (strcmp(_type, "Strings") == 0) {
				ins = new Strings;
			}
			if (strcmp(_type, "Wind") == 0) {
				ins = new Wind;
			}

		ins->sound = _sound;
		strcpy (ins->type, _type);
		strcpy (ins->name, _name);
		S.push(ins);

		S[count]->Sound(S[count]->sound);
		
		count++;
	}

	void OutputByType(const char* _type) {
		
		int i = 0;
		int *value = new int[count];
		for (int j = 1; j < count; j++) {	
			if (strcmp(S[j]->type, _type) == 0) {
				i++;
				cout << i << ". " << " " << S[j]->name << " " << S[j]->sound << endl;
				value[i] = j;
			}
		}
		
		cout << "Choose instrument:" << endl; 
		int _sound;
		cin >> _sound;
		while(cin.fail()) 
		{
			cin.sync();
			cin.clear();
			cout << "Wrong. Try one more" << endl;
			cin >> _sound;
		} 
		if (_sound > i) {
			cout << "Out of range" << endl;
		}
		else {
			int j = value[_sound];  
			S[j]->Sound(S[j]->sound);
		}
	}
	
	void InputToFile(){
		
		FILE* pfile = fopen(filename, "w");
		for (int j = 1; j < count; j++) {
			fprintf(pfile, "%s %s %d\n", S[j]->type, S[j]->name, S[j]->sound);
		}
		fclose(pfile);
		S.~Stack();
	}
};

void Main();
#endif // DATE_H_