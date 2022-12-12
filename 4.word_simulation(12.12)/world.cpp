#include "world.h"

#include <cstdlib>
#include <iostream>

void World::start()
{
	const int max_time = 24;
	const int last_day_hour = 12;
	while(1)
	{
		if(time > max_time)
			time = 1;
		if(time <= last_day_hour)
		{
			std::cout << "Now Day [" << time << ":00] ";
			s.light();
			t.synthesis();
			f.breath();
			system("sleep 1");			
			if(time % 4 == 0)
			{
				f.eat(g);
			}
			else
			{
				f.move();
			}
				system("sleep 1");
			}
			else
			{
				std::cout << "Now Night [" << time << ":00] ";
				f.breath();
				f.sleep();
				system("sleep 1");
			}
	++time;
	}
}

