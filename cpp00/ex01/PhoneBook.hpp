/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:18:19 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/24 14:50:34 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8]; // Array to hold a maximum of 8 contacts
	int index;           // Index to track the oldest contact for replacement
public:
	// Constructor initializes the phonebook
	PhoneBook();
	// Adds a new contact to the phonebook
	void addContact();
	// Displays a list of contacts and allows searching for a specific one
	 void searchContact() const;
};

#endif
