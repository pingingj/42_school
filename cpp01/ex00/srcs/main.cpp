/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:03:17 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/01/22 15:28:06 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.hpp"

int	main()
{
	Zombie *zombie_heap;
	Zombie zombie;
	Zombie zombie_stack("stack");

	zombie.announce();
	zombie_heap = newZombie("daniel");
	zombie_stack.announce();
	zombie_heap->announce();
	randomChump("hello");
	delete zombie_heap;
}