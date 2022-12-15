#include "grass.h"
#include "frog.h"

#include <stdio.h>


void Frog_construct(Frog_t *th)
{
	const  int start_stomach = 5;
	th->stomach = start_stomach;
}


void Frog_breath(Frog_t *th) 
{ 
    printf("Frog is breathing\n");
}


void Frog_eat(Frog_t *th, Grass_t *obj) 
{
	const  int max_stomach = 100;
	if(th->stomach >= max_stomach)
		return ;
	th->stomach += 5;
    printf("Frog is eating stomach level = %d\n", th->stomach);
}

void Frog_sleep(Frog_t *th)
{
    printf("Frog is sleeping\n");
}

void Frog_move(Frog_t *th)
{
	if(!th->stomach)
		return;
	--(th->stomach);
        printf("Frog is moveing stomach level = %d\n", th->stomach);
}