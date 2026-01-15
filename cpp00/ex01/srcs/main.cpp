/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:26:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/01/15 14:23:54 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PhoneBook.hpp"

int	main(int argc, char **argv)
{
	(void)argv;
	std::string	input;
	PhoneBook book;

	if (argc > 1)
	{
		std::cout << "No arguments needed for phonebook" << std::endl;
		return (1);
	}
	std::cout << "Welcome to phonebook, choose an option. ADD, SEARCH, EXIT" << std::endl;
	while(std::cin)
	{
		std::cout << "Input:";
		std::getline(std::cin, input);
		if (std::cin.eof() || input == "EXIT")
			return (exit_phonebook());
		else if (input == "ADD")
			book.set_contact();
		else if (input == "SEARCH")
			book.search_phonebook();
		else
			std::cout << "Input doesnt match any of the options" << std::endl;
	}
	exit_phonebook();
}
