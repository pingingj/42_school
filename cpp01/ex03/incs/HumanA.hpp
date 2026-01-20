/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:53:06 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/01/20 18:39:37 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "../incs/Weapon.hpp"

class HumanA
{
	private:
		Weapon &weapon;
		std::string	name;
	public:
		void	attack();
		HumanA(std::string name, Weapon &weapon);
};
#endif