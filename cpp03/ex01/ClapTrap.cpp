/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:02:43 by alvutina          #+#    #+#             */
/*   Updated: 2024/11/07 15:10:45 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructor
ClapTrap::ClapTrap(const std::string &name) 
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {  // Установим урон атаки в 0
    std::cout << "ClapTrap " << name << " has been created!" << std::endl;
}

// Destructor
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

// Take damage function
void ClapTrap::takeDamage(unsigned int amount) {//If the damage is greater than or equal to health
    if (amount >= hitPoints) {
        hitPoints = 0; // Health cannot go below 0
    } else {
        hitPoints -= amount; // Decrease health by damage amount
    }
    std::cout << "ClapTrap " << name << " takes " << amount << " damage!" 
              << " Hit points left: " << hitPoints << std::endl;
}

// Repair function
void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints > 0 && hitPoints > 0) { // Check if there is enough energy and health to repair
        hitPoints += amount; // Increase health by the repair amount
        std::cout << "ClapTrap " << name << " is repaired by " << amount 
                  << " points! Hit points now: " << hitPoints << std::endl;
        energyPoints--; // Decrease energy after repair
    } else {
        std::cout << "ClapTrap " << name << " cannot be repaired!" << std::endl;
    }
}


