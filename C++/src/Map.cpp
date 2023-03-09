#include "../include/Map.hpp"

Map::Map()
{

}

Map::~Map()
{

}

Map::Map(const char *str)
{
	std::ifstream		infile(str);
	std::string 		line;
	if (infile.is_open())
	{
		size_t j = 0;
		while (std::getline(infile, line))
		{
			std::vector<char> tmp;
			_map.push_back(tmp);
			if (j == 0)
			{
				std::stringstream	linestr(line);

				linestr >> _columns >> _rows;
			}
			if (j > 1)
			{
				for (size_t i = 0; i < line.size() - 1; ++i)
				{
					if (line[i] != ' ')
						_map[j - 2].push_back(line[i]);
				}
			}
			++j;
		}
		for (int i = 0; i < 2; ++i)
			_map.pop_back();
	}
	infile.close();
}

void	Map::showMap()
{
	for (size_t i = 0; i < _map.size(); ++i)
	{
		for (size_t j = 0; j < _map[i].size(); ++j)
		{
			std::cout << _map[i][j];
		}
		std::cout << std::endl;
	}
}

unsigned int	Map::getRows() const
{
	return (_rows);
}

unsigned int	Map::getColumns() const
{
	return (_columns);
}
