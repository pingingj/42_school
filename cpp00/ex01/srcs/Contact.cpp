/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:17:28 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/01/14 18:35:16 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../incs/Contact.hpp>

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