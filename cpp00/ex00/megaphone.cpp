/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:28:39 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/24 12:03:52 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // Includes the standard input/output stream library for using std::cout
#include <cctype>  // Includes the C++ header for character classification and conversion functions, like std::toupper
#include <string>  // Include the string library to use std::string

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			// Convert the current argument to a std::string for easier manipulation
			std::string s(argv[i]); // Convert the argument to a string
			for (size_t j = 0; j < s.length(); j++)
			{
				std::cout << (char)std::toupper(s[j]);
			}
		}
		std::cout << std::endl; 
	}
	return (0);
}