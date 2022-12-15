#ifndef FROG_H
#define FROG_H

#include "grass.h"

typedef struct Frog
{
	int stomach;
} Frog_t;

void Frog_construct(Frog_t *th);
void Frog_breath(Frog_t *th);
void Frog_eat(Frog_t *th, Grass_t *obj);
void Frog_sleep(Frog_t *th);
void Frog_move(Frog_t *th);

#endif
