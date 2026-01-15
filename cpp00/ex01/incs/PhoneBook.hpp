/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:49:05 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/01/15 03:46:29 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cctype>

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
		Contact	get_contact(int index);
		void	search_phonebook();
		void	prompt_index();
		int		total;
		int		index;
};


int			exit_phonebook();
bool		validate_str(std::string input, bool (*func)(int));
std::string	set_value(std::string prompt, bool (*func)(int));
bool		is_alpha(int c);
bool		is_digit(int c);
bool		is_alphanum(int c);