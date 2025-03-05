/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:19:13 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/24 13:31:27 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::inputContactInfo()
{
	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkestSecret);
}

void Contact::displayContactInfo() const
{
	// Displays the full details of the contact
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

void Contact::displaySummary(int index) const
{
	// Displays a summary of the contact formatted into a table
	std::cout << std::right << std::setw(10) << index 
				<< "|" << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0, 9) + '.' : firstName) 
				<< "|" << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 9) + '.' : lastName) 
				<< "|" << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + '.' : nickname) 
				<< std::endl;
}

bool Contact::isEmpty() const
{
	// Returns true if all fields of the contact are empty
	return (firstName.empty() || lastName.empty() || nickname.empty() ||
			phoneNumber.empty() || darkestSecret.empty());
}
