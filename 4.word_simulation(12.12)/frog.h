#ifndef FROG_H
#define FROG_H

#include "grass.h"

#include <iostream>

class Frog
{
	private:
		int stomach;
		static const  int start_stomach = 5;
		static const  int max_stamoch = 100;
	public:
		Frog()
		:stomach(start_stomach){}
		void breath() 
		{ 
			std::cout << "Frog is breathing" << std::endl;
		}
		void eat(Grass & obj) 
		{
			if(stomach >= max_stamoch)
				return ;
			stomach += 5;
			std::cout << "Frog is eating stomach level = " << stomach << std::endl;
		}
		void sleep()
		{
			std::cout << "Frog is sleeping" << std::endl;
		}
		void move()
		{
			if(!stomach)
				return;
			--stomach;
			std::cout << "Frog is moveing stomach level = " << stomach << std::endl;
		}
};

#endif
