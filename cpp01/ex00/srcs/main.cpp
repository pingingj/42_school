/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:03:17 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/01/16 19:15:32 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.hpp"

int	main()
{
	Zombie *zombie;
	Zombie zombie_stack("stack hoe");
	zombie = newZombie("daniel");
	zombie_stack.announce();
	zombie->announce();
	randomChump("hello");
	delete zombie;
}