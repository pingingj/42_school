/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:08:04 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/01/20 16:50:37 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptrstr = &str;
	std::string& strref = str;

	std::cout << "str address = " << &str << std::endl;
	std::cout << "ptr str address = " << ptrstr << std::endl;
	std::cout << "strref address = " << &strref << std::endl << std::endl;
	
	std::cout << "str content = " << str << std::endl;
	std::cout << "ptr str content = " << *ptrstr << std::endl;
	std::cout << "str ref content = " << strref << std::endl;
}