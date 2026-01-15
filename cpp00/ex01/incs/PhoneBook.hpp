/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:49:05 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/01/14 22:39:54 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string	nickname;
		std::string	number;
		std::string	dark_s;
		int			index;
	public:
		void	 	set_first_name(std::string str);
		void		set_last_name(std::string str);
		void		set_nickname(std::string str);
		void		set_number(std::string str);
		void		set_dark_s(std::string str);
		void		set_index(int index);
		std::string get_first_name();
		std::string	get_last_name();
		std::string	get_nickname();
		std::string get_number();
		std::string get_dark_s();
		int			get_index();
		void 		print_info();
};

class PhoneBook
{
	private:
		Contact contacts[8];
	public:
		void	set_contact();
		Contact	get_contact();
		void	search_phonebook();
		int		total;
		int		index;
};



int		exit_phonebook();