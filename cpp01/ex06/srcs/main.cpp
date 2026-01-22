/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:57:44 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/01/22 14:36:00 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "1 argument needed for Harl { DEBUG, INFO, WARNING, ERROR }" << std::endl;
		return (1);
	}
	Harl harl;
	harl.complain(argv[1]);
}