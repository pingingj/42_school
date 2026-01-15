/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:17:28 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/01/15 00:50:08 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PhoneBook.hpp"

std::string	change_print(std::string value)
{
	std::string result;
	
	result = value;
	if (value.length() > 10)
	{
		result = result.substr(0, 10);
		result[9] = '.';
	}
	return (result);
}

void	Contact::print_info()
{
	std::cout << "|";
	std::cout << std::setw(10) << this->index;
	std::cout << "|";
	std::cout << std::setw(10) << change_print(this->first_name);
	std::cout << "|";
	std::cout << std::setw(10) << change_print(this->last_name);
	std::cout << "|";
	std::cout << std::setw(10) << change_print(this->nickname);
	std::cout << "|" << std::endl;
}


void	Contact::set_first_name(std::string str)
{
	this->first_name = str;
}

void	Contact::set_last_name(std::string str)
{
	this->last_name = str;
}

void	Contact::set_nickname(std::string str)
{
	this->nickname = str;
}

void	Contact::set_number(std::string str)
{
	this->number = str;
}

void	Contact::set_dark_s(std::string str)
{
	this->dark_s = str;
}

void	Contact::set_index(int index)
{
	this->index = index;
}

std::string	Contact::get_first_name()
{
	return (this->first_name);
}

std::string	Contact::get_last_name()
{
	return (this->last_name);
}

std::string	Contact::get_nickname()
{
	return (this->nickname);
}

std::string	Contact::get_number()
{
	return (this->number);
}

std::string	Contact::get_dark_s()
{
	return (this->dark_s);
}

int		Contact::get_index()
{
	return (this->index);
}
