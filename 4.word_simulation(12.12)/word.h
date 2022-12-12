#ifndef WORD_H
#define WORD_H

#include "frog.h"
#include "grass.h"
#include "sun.h"
#include "tree.h"

class Word
{
	private:
	Sun s;
	Frog f;
	Tree t;
	Grass g;
	int time;
	public:
		Word()
		:time(1){}
		void start();
};
			

#endif
