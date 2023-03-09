#include "../include/Snake.hpp"

Snake::Snake()
{

}

Snake::Snake(const Snake & other):
	_index(other._index),
	_length(other._length)
{
	std::stringstream	_moves(other._moves.str());
}

Snake::~Snake()
{

}

Snake &	Snake::operator=(const Snake & other)
{
	if (this == &other)
	{
		new (this) Snake(other);
	}
	return (*this);
}

Snake::Snake(unsigned int index, unsigned int length):
	_index(index),
	_length(length)
{

}

unsigned int	Snake::getIndex()
{
	return (_index);
}

unsigned int	Snake::getLength()
{
	return (_length);
}

std::string	Snake::getMoves()
{
	return (_moves.str());
}

//Function creates a vector containing information about snakes from an input file.
std::vector<Snake>	createSnakes(const char *file)
{
	std::vector<Snake>	snakes;

	std::fstream	infile(file);
	if (infile.is_open())
	{
		std::string	line;

		int	lineno = 0;
		while (getline(infile, line))
		{
			if (lineno == 1)
			{
				std::stringstream	linestream(line);
				unsigned int	snakelen;

				int	snakeno = 1;
				while (linestream >> snakelen)
				{
					snakes.push_back(Snake(snakeno, snakelen));
					++snakeno;
				}
			}
			++lineno;
		}
	}
	else
		std::cout << "Couldn't open file for snake input." << std::endl;
	return (snakes);
}

void	Snake::startPoint(int colindex, int rowindex)
{
	if (_moves.str().size() == 0)
		_moves << colindex << " " << rowindex;
	else
		_moves << colindex << " " << rowindex;
}

void	Snake::warpPoint(int colindex, int rowindex)
{
	_moves << " " << colindex << " " << rowindex;
}

void	Snake::moveNorth()
{
	_moves << " U";
}

void	Snake::moveEast()
{
	_moves << " R";
}

void	Snake::moveSouth()
{
	_moves << " D";
}

void	Snake::moveWest()
{
	_moves << " L";
}

void	printSnakes(std::vector<Snake> snakes)
{
	for (size_t i = 0; i < snakes.size(); ++i)
		std::cout << "Snake " << snakes[i].getIndex() << ": " << snakes[i].getLength() << " long, moves: " << snakes[i].getMoves() << std::endl;
}
