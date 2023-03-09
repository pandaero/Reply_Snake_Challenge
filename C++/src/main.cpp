#include "../include/Snake.hpp"
#include "../include/Map.hpp"
#include "../include/Input_Maps.hpp"

#include <iostream>

int	main()
{
	std::cout << "----- ----- ----- ----- -----" << std::endl;
	std::cout << "----- ---- Map 00 ----- -----" << std::cout;
	{
		Map		map(MAP00);
		Snake *	snakes = createSnakes(MAP00);


	}
	std::cout << "----- ----- ----- ----- -----" << std::endl;

	return (0);
}
