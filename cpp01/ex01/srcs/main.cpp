/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:03:17 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/01/20 14:58:56 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.hpp"

int	main()
{
	int	n = 10;
	Zombie *zombies;
	zombies = zombieHorde(n, "daniel");
	for(int	i = 0; i < n; i++)
	{
		std::cout << i << " ";
		zombies[i].announce();
	}
	delete []zombies;
}