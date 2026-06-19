/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:55:43 by maalwis           #+#    #+#             */
/*   Updated: 2025/12/12 14:15:17 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Character.hpp"

Character::Character() {}
Character::Character(const std::string &name) : _name(name), _trashIndex(0)
{
	std::cout << name << " constructed\n";
	for (int i = 0; i < 4; i++)
	{
		_materia[i] = NULL;
		_trash[i] = NULL;
	}
}
Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i] != NULL)
			delete _materia[i];
		if (_trash[i] != NULL)
			delete _trash[i];
	}
	std::cout << _name << " deleted\n";
}

std::string const &Character::getName() const {return (_name);}


Character::Character(const Character &copy) : _name(copy._name), _trashIndex(copy._trashIndex)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy._materia[i])
			_materia[i] = copy._materia[i]->clone();
		else
			_materia[i] = NULL;
		_trash[i] = copy._trash[i];
	}
	std::cout << "Character copy constructor called\n";
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (_materia[i])
				delete _materia[i];
			if (other._materia[i])
				_materia[i] = other._materia[i]->clone();
			else
				_materia[i] = NULL;
			_trash[i] = other._trash[i];
		}
		_trashIndex = other._trashIndex;
	}
	std::cout << "Character assignment operator called\n";
	return (*this);
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4 ; i++)
	{
		if (!_materia[i])
		{
			_materia[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3 && _materia[idx])
	{
		_trash[_trashIndex++] = _materia[idx];
		_materia[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx <= 3)
	{
		if (_materia[idx])
		{
			_materia[idx]->use(target);
		}
	}
}