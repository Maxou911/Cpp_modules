/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitcoin.Exchange.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:22:33 by maalwis           #+#    #+#             */
/*   Updated: 2026/03/18 13:58:04 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitcoin.Exchange.hpp"

Btc::Btc() {}
Btc::~Btc() {}
Btc::Btc(const Btc &copy)
{
	std::cout << BOLDPURPLE << "COPY CALLED\n" RESET;
	this->_date = copy._date;
	this->_map = copy._map;
	this->_rate = copy._rate;
	this->_value = copy._value;
}

Btc &Btc::operator=(const Btc &other)
{
	std::cout << BOLDPURPLE << "OPERATOR CALLED\n" RESET;
	if (this != &other)
	{
		this->_date = other._date;
		this->_map = other._map;
		this->_rate = other._rate;
		this->_value = other._value;
	}
	return *this;
}

bool	is_number(std::string &input)
{
	size_t	i;
	size_t dot = 0;

	i = 0;
	if (input.empty())
	{
		std::cerr << ERROR << ": no value\n";
		return (false);
	}
	while (i < input.length())
	{
		if (input[i] == '.')
		{
			dot += 1;
			if (dot > 1)
				return false;
		}
		else if (!isdigit(input[i]))
		{
			if (input[i] == '-')
				break;
			return false;
		}
		i++;
	}
	if (input.find_first_of("0123456789") == std::string::npos)
		return false;
	return (true);
}

bool	Btc::is_float_valid(std::string &value)
{
	if (!is_number(value))
	{
		std::cerr << ERROR << ": bad value => " << RED << value << RESET << '\n';
		return false;
	}
	if (std::atof(value.c_str()) <= 0)
	{
		std::cout << ERROR << ": not a positive number => " << RED << value << RESET << '\n';
		return false;
	}
	else if (std::atof(value.c_str()) >= 1000)
	{
		std::cout << ERROR << ": too large a number => " << RED << value << RESET << '\n';
		return false;
	}
	return true;
}

std::string	trim(std::string string)
{
	size_t pos = 0;
	while ((pos = string.find(" ")) != std::string::npos)
		string.erase(pos, 1);
	return string;
}

bool is_valid_date(std::string _year, std::string _month, std::string _day)
{
	int year = atoi(_year.c_str());
	int month = atoi(_month.c_str());
	int day = atoi(_day.c_str());

	if (year < 2009 || year > 2022)
		return false;
	if (month < 1 || month > 12)
		return false;

	if (month == 2)
	{
		if (year % 4 == 0)
		{
			if (day < 1 || day > 29)
				return false;
		}
		else
		{
			if (day < 1 || day > 28)
				return false;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day < 1 || day > 30)
			return false;
	}
	else
	{
		if (day < 1 || day > 31)
			return false;
	}
	return true;
}

bool	Btc::check_date(std::string &date)
{
	std::string year = date.substr(0,4);
	std::string month = date.substr(5,2);
	std::string day = date.substr(8,2);

	date = trim(date);
	if (date.empty() || date.length() != 10)
		return false;
	else if (date.substr(0,2) != "20")
		return false;
	else if (year.length() != 4 || !is_number(year))
		return false;
	else if (date.find_first_of('-') != 4 || date.find_last_of('-') != 7)
		return false;
	else if (month.length() != 2 || !is_number(month))
		return false;
	else if (day.length() != 2 || !is_number(day))
		return false;
	if (!is_valid_date(year, month, day))
		return false;
	return true;
}
float	Btc::return_input(void)
{
	return (_rate * std::atof(_value.c_str()));
}

bool	Btc::check_input_file(std::string &line)
{
	size_t pos_bar;

	if (line.empty())
		return false;
	pos_bar = line.find("|");
	if (pos_bar == std::string::npos)
	{
		std::cerr << ERROR << ": bad input => " << RED << line << RESET << '\n';
		return false;
	}
	_date = line.substr(0, pos_bar);
	if (!check_date(_date))
	{
		std::cerr << ERROR << ": incorrect date => " << RED << _date << RESET << '\n';
		return false;
	}
	_value = get_value(line);
	if (!is_float_valid(_value))
		return false;
	return true;
}

std::string Btc::get_value(std::string line)
{
	std::string value;
	size_t pos_bar;

	line = trim(line);
	pos_bar = line.find("|");
	value = line.substr(pos_bar + 1);
	return (value);
}

map::iterator	Btc::find_date(std::string &date)
{
	map::iterator it = _map.upper_bound(date);
	if (it == _map.begin())
		return _map.end();
	it--;
	return (it);
}
bool	Btc::check_data_file(const std::string &line)
{
	std::string date;
	std::string rate;
	size_t coma = line.find(',');
	if (coma == std::string::npos)
		return false;
	date = line.substr(0, coma);
	rate = line.substr(coma + 1);
	if (!check_date(date))
		return false;
	_date = date;
	_rate = std::atof(rate.c_str());
	return true;
}

void	Btc::parse_data_file(void)
{
	std::ifstream data_file("data.csv");
	if (!data_file)
	{
		std::cerr << "Put valid data file\n";
		return ;
	}
	std::string line;
	std::getline(data_file,line);
	while (std::getline(data_file, line))
	{
		if (check_data_file(line))
			_map.insert(std::make_pair(_date, _rate));
	}
}

void	Btc::parse_input_file(char **av)
{
	std::ifstream infile(av[1]);
	if (!infile)
	{
		std::cerr << ERROR << ": Put valid infile\n";
		return ;
	}
	std::string line;
	std::getline(infile,line);
	while (std::getline(infile, line))
	{
		if (check_input_file(line))
		{
			map::iterator it = find_date(_date);
			if (it == _map.end())
			{
				std::cout << ERROR << ": No previous dates\n";
				continue ;
			}
			_rate = it->second;
			float result = return_input();
			std::cout << "✅ " << _date << " => " << _value << " = " << GREEN << result << RESET << std::endl;
		}
	}
	infile.close();
}
