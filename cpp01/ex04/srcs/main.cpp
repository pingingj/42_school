/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:54:11 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/01/21 18:20:33 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	sed(char **argv, std::ifstream &file)
{
	std::string replaced;
	std::string to_replace = argv[2];
	size_t		skip = to_replace.length();
	std::string	line = argv[1];
	line += ".replace";
	std::ofstream replacedfile(line.c_str());
	while(std::getline(file, line))
	{
		size_t	start = 0;
		size_t	pos = 0;
		pos = line.find(argv[2],start);
		if (pos == line.npos)
			replacedfile << line;
		else
		{
			while(pos != line.npos)
			{
				replacedfile << line.substr(start, pos - start);
				replacedfile << argv[3];
				start = pos + skip;
				pos = line.find(argv[2],start);
			}
			replacedfile << line.substr(start, line.length());
		}
		if(!file.eof())
			replacedfile << std::endl;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Only 3 arguments needed, filename, string to replace, replaced string" << std::endl;
		return (1);
	}
	std::ifstream file(argv[1]);
	if (!file.is_open())
	{
		std::cout << "Error opening input file" << std::endl;
		return (1);
	}
	sed(argv, file);
}