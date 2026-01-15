/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 03:38:45 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/01/15 03:47:26 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PhoneBook.hpp"

bool		validate_str(std::string input, bool (*func)(int))
{
	int	i;

	i = 0;
	if (func == NULL)
		return (true);
	while (input[i])
	{
		if (func(input[i]) == false)
		{
			std::cout << "Invalid input" << std::endl;
			return (false);
		}
		i++;
	}
	return (true);
}

std::string	set_value(std::string prompt, bool (*func)(int))
{
	std::string	input;

	while(input.empty() && std::cin)
	{

		std::cout << prompt;
		std::getline(std::cin, input);
		if (!input.empty())
		{
			if (validate_str(input, func) == true)
				return (input);
			input.clear();
		}
	}
	return (input);
}

bool		is_alpha(int c)
{
	return (std::isalpha(c));
}

bool		is_digit(int c)
{
	return (std::isdigit(c));
}

bool		is_alphanum(int c)
{
	return (std::isalpha(c) || std::isdigit(c));
}