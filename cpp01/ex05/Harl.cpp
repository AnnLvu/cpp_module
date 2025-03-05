/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:17:40 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 11:28:26 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Harl.cpp

#include "Harl.hpp"

void Harl::debug() 
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
    std::cout << "I really do!" << std::endl;
}

void Harl::info() 
{
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
    std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() 
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
    std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() 
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(const std::string& level)
{
    // Array of member function pointers
    void (Harl::*complaints[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    for (int i = 0; i < 4; i++)
	{
        if (levels[i] == level)
		{
            (this->*complaints[i])();  // Call the appropriate function via pointer
            return;
        }
    }
    std::cout << "Invalid complaint level: " << level << std::endl;
}
