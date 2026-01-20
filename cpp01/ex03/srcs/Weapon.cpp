/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:53:11 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/01/20 17:18:07 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Weapon.hpp"

const std::string&	Weapon::getType()
{
	const std::string& str = this->type;
	return (str);
}

void	Weapon::setType(std::string value)
{
	this->type = value;
}

Weapon::Weapon(std::string type)
{
	this->setType(type);
	std::cout << "Weapon of the type " << this->getType() << " was constructed" << std::endl;
}

Weapon::Weapon()
{
	std::cout << "Default weapon constructor" << std::endl;
}
