#include "word.h"

#include <cstdlib>
#include <iostream>

void Word::start()
{
	while(1)
	{
		if(time > 24)
			time = 1;
		if(time <= 12)
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

