/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:13:45 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/01/14 19:17:20 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string	nickname;
		std::string	number;
		std::string	dark_s;
	public:
		void	 	set_first_name(std::string str);
		void		set_last_name(std::string str);
		void		set_nickname(std::string str);
		void		set_number(std::string str);
		void		set_dark_s(std::string str);
		std::string get_first_name();
		std::string	get_last_name();
		std::string	get_nickname();
		std::string get_number();
		std::string get_dark_s();
};
