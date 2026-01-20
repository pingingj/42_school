/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:23:24 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/01/20 18:44:46 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/HumanB.hpp"

void	HumanB::attack()
{
	if (!this->weapon)
	{
		std::cout << this->name << " doesn't have a weapon" << std::endl;
		return ;
	}
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
	std::cout << this->name << " has picked up a" << this->weapon->getType() << std::endl;
}

HumanB::HumanB(std::string name, Weapon &weapon)
{
	this->weapon = &weapon;
	this->name = name;
	std::cout << this->name << " has been created and picked up a " << this->weapon->getType() << std::endl;
}

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
	std::cout << this->name << " has been created" << std::endl;
}