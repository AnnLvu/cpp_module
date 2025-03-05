/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:02:43 by alvutina          #+#    #+#             */
/*   Updated: 2024/11/07 15:16:28 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructor for ClapTrap
ClapTrap::ClapTrap(const std::string &name) 
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {  // Установим урон атаки в 0
    std::cout << "ClapTrap " << name << " has been created!" << std::endl;
}

// Destructor for ClapTrap
ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
}

// Attack function
void ClapTrap::attack(const std::string &target) {
    if (energyPoints > 0 && hitPoints > 0) {
        std::cout << "ClapTrap " << name << " attacks " << target 
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else {
        std::cout << "ClapTrap " << name << " cannot attack!" << std::endl;
    }
}


// Function to handle taking damage
void ClapTrap::takeDamage(unsigned int amount) {
    if (amount >= hitPoints) {
        hitPoints = 0; // If the damage is greater than or equal to current health, health becomes 0
    } else {
        hitPoints -= amount; // Otherwise, reduce health by the amount of damage
    }
    std::cout << "ClapTrap " << name << " takes " << amount << " damage!" 
              << " Hit points left: " << hitPoints << std::endl;
}

// Function to repair ClapTrap
void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints > 0 && hitPoints > 0) {  // Check if ClapTrap has energy points and is alive to repair
        hitPoints += amount;  // Increase health by the repair amount
        std::cout << "ClapTrap " << name << " is repaired by " << amount 
                  << " points! Hit points now: " << hitPoints << std::endl;  // Print message showing repair details
        energyPoints--;  // Reduce energy points by 1 after repair
    } else {
        std::cout << "ClapTrap " << name << " cannot be repaired!" << std::endl;  // Print message if repair is not possible
    }
}
