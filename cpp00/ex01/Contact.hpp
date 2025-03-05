/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:16:13 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/24 13:31:49 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip> // For std::setw

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	// Prompts the user to input the contact's information
	void inputContactInfo();
	// Displays the full contact information
	void displayContactInfo() const;
	// Displays a summary of the contact with an index
	void displaySummary(int index) const;
	 // Checks if the contact is empty (all fields are empty)
	bool isEmpty() const;
};

#endif
