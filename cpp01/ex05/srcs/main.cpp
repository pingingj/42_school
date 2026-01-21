/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:57:44 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/01/21 19:18:31 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Harl.hpp"

int	main()
{
	Harl	harl;
	harl.complain("DEBUG");
	harl.complain("WARNING");
	harl.complain("NOT FOUND");
	harl.complain("ERROR");
	harl.complain("INFO");
}