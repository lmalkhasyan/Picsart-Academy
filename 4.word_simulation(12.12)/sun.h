#ifndef SUN_H
#define SUN_H

#include <iostream>

class Sun
{
	public:
		Sun() = default;
		void light()
		{
			std::cout << "Sun is shining" << std::endl;
		}
};

#endif
