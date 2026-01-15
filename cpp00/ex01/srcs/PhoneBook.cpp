/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:38:29 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/01/15 03:46:44 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PhoneBook.hpp"

void	PhoneBook::set_contact()
{
	this->contacts[index].set_first_name(set_value("First name:", is_alpha));
	this->contacts[index].set_last_name(set_value("Last name:", is_alpha));
	this->contacts[index].set_nickname(set_value("Nickname:", is_alphanum));
	this->contacts[index].set_number(set_value("Phone number:", is_digit));
	this->contacts[index].set_dark_s(set_value("Darkest secret:", is_alphanum));
	this->contacts[index].set_index(index);
	if (total < 8)
		total++;
	index++;
	if (index == 8)
		index = 0;
}

Contact	PhoneBook::get_contact(int index)
{
	std::cout << "First name:" << this->contacts[index].get_first_name() << std::endl;
	std::cout << "Last name:" << this->contacts[index].get_last_name() << std::endl;
	std::cout << "Nickname name:" << this->contacts[index].get_nickname() << std::endl;
	std::cout << "Phone number:" << this->contacts[index].get_number() << std::endl;
	std::cout << "Darkest secret:" << this->contacts[index].get_dark_s() << std::endl;
	return (this->contacts[index]);
}

void	PhoneBook::prompt_index()
{
	std::string	input;
	int			i;
	
	while(input.empty() && std::cin)
	{
		input = set_value("Choose an index:", NULL);
		i = 0;
		while (input[i])
		{
			if (std::isdigit(input[i]) == false || input[i] - '0' > total - 1)
			{
				std::cout << "Invalid index" << std::endl;
				prompt_index();
				return ;
			}
			i++;
		}
	}
	get_contact(input[0] - '0');
}

void	PhoneBook::search_phonebook()
{
	int	i;

	i = 0;
	if (total == 0)
	{
		std::cout << "No contacts" << std::endl;
		return ;
	}
	std::cout << std::setfill('-');
	std::cout << std::setw(45) << "" << std::endl;
	std::cout << std::setfill(' ');
	std::cout << "|";
	std::cout << std::setw(10) << "Index";
	std::cout << "|";
	std::cout << std::setw(10) << "First name";
	std::cout << "|";
	std::cout << std::setw(10) << "Last name";
	std::cout << "|";
	std::cout << std::setw(10)  << "Nickname";
	std::cout << "|"  << std::endl;
	while(i < total)
	{
		this->contacts[i].print_info();
		i++;
	}
	std::cout << std::setfill('-');
	std::cout << std::setw(45) << "" << std::endl;
	prompt_index();
}

int		exit_phonebook()
{
	if (std::cin.eof())
		std::cout << std::endl;
	std::cout << "Goodbye!" << std::endl;
	return (1);
}