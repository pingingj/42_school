/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:38:29 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/01/14 19:43:07 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PhoneBook.hpp"

void	PhoneBook::set_contact(int index)
{
	std::cout << index << std::endl;
}

Contact	PhoneBook::get_contact(int	index)
{
	return (this->contacts[index]);
}