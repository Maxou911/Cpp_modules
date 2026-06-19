/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:27:53 by maalwis           #+#    #+#             */
/*   Updated: 2025/12/12 14:07:27 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class AMateria;

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria	*_materia[4];
		AMateria	*_trash[4];
		int			_trashIndex;
	public:
		Character();
		Character(const std::string &name);
		Character(const Character &copy);
		Character &operator=(const Character &other);
		~Character();
		
		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};

#endif