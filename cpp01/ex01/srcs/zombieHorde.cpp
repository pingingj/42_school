/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:50:56 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/01/20 14:55:10 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.hpp"

Zombie* zombieHorde(int n, std::string name)
{
	Zombie	*zombies;
	zombies = new Zombie[n];
	for(int	i = 0; i < n; i++)
	{
		zombies[i].setName(name);
		// zombies[i].announce();
	}
	return (zombies);
}