/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:58:44 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/01/13 15:44:10 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

int main(int argc, char **argv)
{
	std::string	str;
	int	i;

	i = 1;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	while (argv[i])
	{
		str = argv[i];
		std::transform(str.begin(), str.end(), str.begin(),::toupper);
		std::cout << str;
		i++;
	}
	std::cout << std::endl;
}