#ifndef WORD_H
#define WORD_H

#include "frog.h"
#include "grass.h"
#include "sun.h"
#include "tree.h"

typedef struct World
{
	Sun_t s;
	Frog_t f;
	Tree_t t;
	Grass_t g;
	int time;
}World_t;

void World_construct(World_t *th);
void World_start(World_t *th);

			

#endif
