/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:38:29 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/01/14 23:52:44 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PhoneBook.hpp"

std::string	set_value(std::string prompt)
{
	std::string	input;

	while(input.empty() && std::cin)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (!input.empty())
			return (input);
	}
	return (input);
}

void	PhoneBook::set_contact()
{
	this->contacts[index].set_first_name(set_value("First name:"));
	this->contacts[index].set_last_name(set_value("Last name:"));
	this->contacts[index].set_nickname(set_value("Nickname:"));
	this->contacts[index].set_number(set_value("Phone number:"));
	this->contacts[index].set_dark_s(set_value("Darkest secret:"));
	this->contacts[index].set_index(index);
	if (total < 8)
		total++;
	index++;
	if (index == 8)
		index = 0;
}

Contact	PhoneBook::get_contact()
{
	std::cout << "First name:" << this->contacts[index].get_first_name() << std::endl;
	std::cout << "Last name:" << this->contacts[index].get_first_name() << std::endl;
	std::cout << "Nickname name:" << this->contacts[index].get_first_name() << std::endl;
	std::cout << "Phone number:" << this->contacts[index].get_first_name() << std::endl;
	std::cout << "Darkest secret:" << this->contacts[index].get_first_name() << std::endl;
	return (this->contacts[index]);
}

void	PhoneBook::search_phonebook()
{
	int	i;

	i = 0;
	std::cout << std::setfill('_');
	std::cout << std::setw(44) << "" << std::endl;
	std::cout << std::setfill(' ');
	std::cout << std::setw(10) << "Index";
	std::cout << "|";
	std::cout << std::setw(10) << "First name";
	std::cout << "|";
	std::cout << std::setw(10) << "Last name";
	std::cout << "|";
	std::cout << std::setw(10)  << "Nickname";
	std::cout << "|"  << std::endl;
	std::cout << std::setfill(' ');
	while(i < total)
	{
		this->contacts[i].print_info();
		i++;
	}
	std::cout << std::setfill('_');
	std::cout << std::setw(44) << "|" << std::endl;
}

int		exit_phonebook()
{
	if (std::cin.eof())
		std::cout << std::endl;
	std::cout << "Goodbye!" << std::endl;
	return (1);
}