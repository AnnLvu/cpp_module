/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:20:11 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/24 16:21:37 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <limits>  

PhoneBook::PhoneBook() : index(0) {} // Initializes the index to 0

void PhoneBook::addContact()
{
	Contact newContact; // Create a new contact object
	newContact.inputContactInfo();

	// If the new contact is not empty, add it to the contacts array
	if (!newContact.isEmpty())
	{
		contacts[index] = newContact; // Store new contact
		index = (index + 1) % 8; // Increment index and wrap around
	}
	else
	{
		std::cout << "Cannot add an empty contact!" << std::endl;
	}
}

void PhoneBook::searchContact() const
{
	// Display a list of saved contacts with their indices
	std::cout << std::endl;
	std::cout << "Index     | First Name | Last Name  | Nickname  " << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (!contacts[i].isEmpty())
		{
			contacts[i].displaySummary(i);
		}
	}

	int index;
	std::cout << "Enter index of contact to display: ";
	if (!(std::cin >> index))  // Check if input failed
    {
        std::cin.clear();  // Clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the rest of the line
        std::cout << "Invalid input! Please enter a valid number." << std::endl;
        return;  // Exit the function if input is invalid
    }

    std::cin.ignore(); // Clear the newline from the input buffer
	
	
	if (index >= 0 && index < 8 && !contacts[index].isEmpty())
	{
		contacts[index].displayContactInfo();
	} 
	else 
	{
		std::cout << "Invalid index!" << std::endl;
	}
}
