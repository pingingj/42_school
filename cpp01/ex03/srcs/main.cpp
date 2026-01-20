/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:29:55 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/01/20 18:50:55 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/HumanA.hpp"
#include "../incs/HumanB.hpp"

int main()
{
	Weapon	wp("staff");
	Weapon	nuke("nuke");
	Weapon	sword("sword");
	HumanA	diogo("Diogo", wp);
	diogo.attack();
	HumanB	daniel("Daniel");
	daniel.attack();
	daniel.setWeapon(nuke);
	daniel.attack();
	HumanB	ricardo("Ricardo", sword);
	ricardo.attack();
	sword.setType("bazooka");
	ricardo.attack();

	// {
	// 	Weapon club = Weapon("crude spiked club");
	// 	HumanA bob("Bob", club);
	// 	bob.attack();
	// 	club.setType("some other type of club");
	// 	bob.attack();
	// }
	// {
	// 	Weapon club = Weapon("crude spiked club");
	// 	HumanB jim("Jim");
	// 	jim.setWeapon(club);
	// 	jim.attack();
	// 	club.setType("some other type of club");
	// 	jim.attack();
	// }
	return 0;
}