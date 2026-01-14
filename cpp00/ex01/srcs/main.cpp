/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:26:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/01/14 19:44:13 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PhoneBook.hpp"

int	main()
{
	// int	i;
	std::string	input;
	PhoneBook book;
	
	// i = 0;
	while(1)
	{
		std::cout << "Welcome to the phonebook, choose an option. ADD, SEARCH, EXIT" << std::endl;
		std::cin >> input; 
		if (input == "ADD")
			std::cout << "placeholder" << std::endl;
		else if (input == "SEARCH")
		{
			std::cout << "placeholder" << std::endl;
		}
		else if (input == "EXIT")
		{
			std::cout << "placeholder" << std::endl;
		}
		else
			std::cout << "Input doesnt match any of the options" << std::endl;
	}
}