#ifndef WORD_H
#define WORD_H

#include "frog.h"
#include "grass.h"
#include "sun.h"
#include "tree.h"

class World
{
	private:
	Sun s;
	Frog f;
	Tree t;
	Grass g;
	int time;
	static const int start_time = 1;
	public:
		World()
		:time(start_time){}
		void start();
};
			

#endif
