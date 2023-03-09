#ifndef MAP_HPP
# define MAP_HPP

# include <fstream>
# include <sstream>
# include <vector>
# include <iostream>

class	Map
{
	private:
		unsigned int						_rows;
		unsigned int						_columns;
		std::vector<std::vector <char> >	_map;

	public:
		Map();
		~Map();

		Map(const char *str);
		void	showMap();

		unsigned int	getRows() const;
		unsigned int	getColumns() const;
};
#endif
