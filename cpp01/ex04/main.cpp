/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:54:13 by maalwis           #+#    #+#             */
/*   Updated: 2025/09/26 14:03:35 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
	if (ac == 4) {
		std::string s1 = av[2];
		std::string s2 = av[3];

		std::ifstream infile(av[1]);
		if (!infile || s1.empty())
		{
			std::cerr << "Put valid arguments\n";
			return (1);
		}
		std::string outFileName = std::string(av[1]) + ".replace";
		std::ofstream outfile(outFileName.c_str());
		if (!outfile) {
			std::cerr << ".replace outfile didn't create\n";
			return (1);
		}
		std::string line;
		while (std::getline(infile, line))
		{
			size_t	pos = line.find(s1);
			std::string	newLine;
			size_t	start = 0;
			if (pos < line.size()) {

				while (pos < line.size()) {
					newLine.append(line.substr(start, pos - start));
					newLine.append(s2);
					start = pos + s1.length();
					pos = line.find(s1, start);
				}
				newLine.append(line.substr(start));
				outfile << newLine << std::endl;
			}
			else
				outfile << line << std::endl;
		}
		infile.close();
		outfile.close();
	}
}
