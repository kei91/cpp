#ifndef INSTRUMENTS_H_
#define INSTRUMENTS_H_

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <Windows.h>

using namespace std;

#define filename "catalog.txt"

class Instrument { 

public: 
	char type[15];
	char name[100];
	int sound;

	virtual void Sound(int _sound) = 0;
};

class Strings: public Instrument { 
	
 public:

	void Sound(int _sound) {
		sound = _sound;
		Beep(sound + 359, 225);
		Beep(sound + 359, 225);
		Sleep (200);
		Beep(sound + 359, 225);
		Sleep (200);
		Beep(sound + 223, 225);
		Beep(sound + 359, 225);
		Sleep (200);
		Beep(sound + 484, 225);
		Sleep (300);
		Beep(sound + 92, 300);
	}
};

class Keyboards: public Instrument { 
  
 public: 

	void Sound(int _sound) {
		sound = _sound;
		Beep(sound + 47, 500); 
		Beep(sound + 217, 500);
		Beep(sound + 217, 500);
		Beep(sound + 170, 500);
		Beep(sound + 217, 500);
		Beep(sound + 129, 500);
		Beep(sound + 47, 500);
		Beep(sound + 47, 500);
		Beep(sound + 47, 500);
		Beep(sound + 217, 500);
		Beep(sound + 217, 500);
		Beep(sound + 170, 500);
		Beep(sound + 217, 500);
		Beep(sound + 297, 500);
	}
 };

class Wind: public Instrument { 
  
 public: 

	void Sound(int _sound) {
		sound = _sound;
		Beep(sound, 500);
		Beep(sound + 23,500); 
		Beep(sound + 87,500); 
		Beep(sound + 159,500); 
		Beep(sound + 198,500); 
		Beep(sound + 284,500); 
	}	
};

#endif // INSTRUMENTS_H