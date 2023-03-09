#include "../include/Map.hpp"
#include "../include/Snake.hpp"
#include "../include/Input_Maps.hpp"

int	main()
{
	Map		Map(MAP00);

	std::cout << "Map: " << std::endl;
	Map.showMap();

	std::cout << "Rows   : " << Map.getRows() << std::endl;
	std::cout << "Columns: " << Map.getColumns() << std::endl;

	std::vector<Snake>	snakes = createSnakes(MAP00);

	std::cout << std::endl << "Snakes: " << std::endl;
	printSnakes(snakes);

	return (0);
}