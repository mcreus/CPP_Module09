#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <iomanip>
# include <map>
# include <algorithm>
# include <fstream>
# include <string>
# include <cstdlib>

class BitcoinExchange
{
    public:

		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &other);
		BitcoinExchange	&operator=(BitcoinExchange const &);
		~BitcoinExchange();
		void	recoveryData();
		void	checkFile(char *file);
		int		checkDateText();
		void	compareAll();
		class NotGoodDate : public std::exception
		{
			virtual const char	*what() const throw()
			{
				return ("Error : Not a good date!!!\n");
			}
		};

		class NotInput : public std::exception
		{
			virtual const char	*what() const throw()
			{
				return ("Error : Not input on your program!!!\n");
			}
		};

		class DoesNotExist : public std::exception
		{
			virtual const char	*what() const throw()
			{
				return ("Error : File does not exist\n");
			}
		};
		
		class NotGoodValue : public std::exception
		{
			virtual const char	*what() const throw()
			{
				return ("Error : Not good value!!!\n");
			}
		};
		
		class FileDoesNotExist : public std::exception
		{
			virtual const char	*what() const throw()
			{
				return ("Error : File not opened\n");
			}
		};

	private:

		std::map<int, long double>				_file;
		std::string							_lineFile;
		std::string							_linetext;
		std::string							_dateText;
		std::string							_dateFile;
		std::string							_yearText;
		std::string							_yearFile;
		std::string							_monthText;
		std::string							_monthFile;
		std::string							_dayText;
		std::string							_dayFile;
		std::string							_valueText;
		std::string							_valueFile;

};

#endif