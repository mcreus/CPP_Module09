/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:37:44 by mcreus            #+#    #+#             */
/*   Updated: 2023/11/03 15:52:12 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
	*this = other;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &)
{
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	
}

void	BitcoinExchange::recoveryData()
{
	std::ifstream	fichier("data.csv");
	std::string		_lineFile;
	int				cut;
	long double			value;

	if (fichier.is_open())
	{
		getline(fichier, _lineFile);
		while (getline(fichier, _lineFile))
		{
			this->_yearFile = _lineFile.substr(0, 4);
			this->_monthFile = _lineFile.substr(5, 2);
			this->_dayFile = _lineFile.substr(8, 2);
			this->_dateFile = this->_yearFile + this->_monthFile + this->_dayFile;
			this->_valueFile = _lineFile.substr(11, (_lineFile.length() - 1));
			cut = std::atoi(this->_dateFile.c_str());
			value = std::atof(this->_valueFile.c_str());
			_file.insert(std::pair<int, long double>(cut, value));
		}
		fichier.close();
	}
	else
	{
		std::cerr << "Error : Could not open file for map container" << std::endl;
	}
}

void	BitcoinExchange::checkFile(char *file)
{
	std::ifstream		fichier(file);
	float				value = 0;
	
	recoveryData();
	if (fichier.is_open())
	{
		getline(fichier, _linetext);
		while (getline(fichier, _linetext))
		{
			this->_yearText = _linetext.substr(0, 4);
			this->_monthText = _linetext.substr(5, 2);
			this->_dayText = _linetext.substr(8, 2);
			this->_dateText = this->_yearText + this->_monthText + this->_dayText;
			if (_linetext.length() > 13 && _linetext.length() < 24)
			{
				this->_valueText = _linetext.substr(13, (_linetext.length() - 1));
				value = std::atof(_valueText.c_str());
				if (value < 0)
					std::cerr << "Error: Number don't be negative" << std::endl;
				else if (value > 2147483647.0)
					std::cerr << "Error: Number too hight" << std::endl;
				else
				{
					if (checkDateText() == 1)
						std::cout << _linetext.substr(0,10) << std::endl;
					else
					{
						std::cout << _linetext.substr(0, 10) ;
						compareAll();
					}
				}
			}
			else
			{
				std::cerr << "Error: No value" << std::endl;
			}
		}
		fichier.close();
	}
	else
	{
		std::cerr << "Error : Could not open file" << std::endl;
	}
}

int	BitcoinExchange::checkDateText()
{
	int	yearText;
	int	monthText;
	int	dayText;
	int	dateText;
	
	yearText = std::atoi(this->_yearText.c_str());
	monthText = std::atoi(this->_monthText.c_str());
	dayText = std::atoi(this->_dayText.c_str());
	dateText = std::atoi(this->_dateText.c_str());
	if (yearText < 2009)
	{
		std::cerr << "Error: Date too small, Bitcoin does not exist on this time => ";
		return (1);
	}
	else if (yearText > 2023 && monthText > 11 && dayText > 02)
	{
		std::cerr << "Error: Date does not exist => ";
		return (1);
	}
	else if (monthText < 01 || monthText > 12)
	{
		std::cerr << "Error: Month does not exist => ";
		return (1);
	}
	else if (dayText < 01 || dayText > 31)
	{
		std::cerr << "Error: Day does not exist => ";
		return (1);
	}
	return (0);
}

void	BitcoinExchange::compareAll()
{
	int								dateText;
	long double						value = 0.0;
	long double							valueText = 0.0;
	std::map<int, long double>::iterator	it = _file.begin();
	std::map<int, long double>::iterator	ite = _file.end();

	valueText = std::atof(this->_valueText.c_str());
	dateText = std::atoi(this->_dateText.c_str());
	while (it != ite)
	{
		if (dateText == it->first)
		{
			value = valueText * it->second;
			std::cout << " => " << this->_valueText << " = " << std::fixed << std::setprecision(5) << value << std::endl;
			break ;
		}
		if (dateText < it->first)
		{
			it--;
			value = valueText * it->second;
			std::cout << " => " << this->_valueText << " = " << std::fixed << std::setprecision(5) << value << std::endl;
			break ;
		}
		++it;
	}
}