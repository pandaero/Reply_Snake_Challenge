#ifndef SNAKE_HPP
# define SNAKE_HPP

# include <vector>
# include <string>
# include <fstream>
# include <sstream>
# include <iostream>

class	Snake
{
	private:
		unsigned int				_index;
		unsigned int				_length;
		std::stringstream			_moves;
	
	public:
		Snake();
		Snake(const Snake &);
		~Snake();
		Snake & operator=(const Snake &);
		
		Snake(unsigned int, unsigned int);

		unsigned int	getIndex();
		unsigned int	getLength();
		std::string		getMoves();

		void			startPoint(int, int);
		void			moveNorth();
		void			moveEast();
		void			moveSouth();
		void			moveWest();
		void			warpPoint(int, int);
};

std::vector<Snake>	createSnakes(const char *);
void				printSnakes(std::vector<Snake>);

#endif
