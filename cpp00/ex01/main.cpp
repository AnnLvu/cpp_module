/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:20:49 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/24 13:33:50 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook phoneBook; // Create a PhoneBook instance
	std::string command; // Variable to store user commands

	// Continuously prompt the user for commands until EXIT is entered
	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (command == "ADD")
		{
			phoneBook.addContact();  // Call method to add a contact
		}
		else if (command == "SEARCH") 
		{
			phoneBook.searchContact(); // Call method to search for a contact
		}
		else if (command == "EXIT")
		{
			break; // Exit the program
		}
		else
		{
		std::cout << "Invalid command!" << std::endl;
		}
	}
	return (0);
}
