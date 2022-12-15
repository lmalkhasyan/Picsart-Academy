#include "world.h"
#include <stdlib.h>

#include <stdio.h>

void World_construct(World_t *th)
{
	Frog_construct(&(th->f));
	const int start_time = 1;
	th->time = start_time;
}

void World_start(World_t *th)
{
	const int max_time = 24;
	const int last_day_hour = 12;
	while(1)
	{
		if(th->time > max_time)
			th->time = 1;
		if(th->time <= last_day_hour)
		{
			printf("Now Day [%d:00]", th->time);
			Sun_light(&th->s);
			Tree_synthesis(&th->t);
			Frog_breath(&th->f);
			system("sleep 1");			
			if(th->time % 4 == 0)
			{
				Frog_eat(&th->f, &th->g);
			}
			else
			{
				Frog_move(&th->f);
			}
				system("sleep 1");
			}
			else
			{
				printf("Now Night [%d:00]", th->time);
				Frog_breath(&th->f);
				Frog_sleep(&th->f);
				system("sleep 1");
			}
	++th->time;
	}
}

