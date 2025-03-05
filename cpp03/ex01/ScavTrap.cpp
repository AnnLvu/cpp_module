/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:44:26 by alvutina          #+#    #+#             */
/*   Updated: 2024/11/07 15:13:05 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructor
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " has been created!" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " has been destroyed!" << std::endl;
}

// Override attack function
void ScavTrap::attack(const std::string &target) {
    if (energyPoints > 0 && hitPoints > 0) {  // Check if there is enough energy and health to attack
        std::cout << "ScavTrap " << name << " attacks " << target 
                  << ", causing " << attackDamage << " points of damage!" << std::endl; // Print attack details
        energyPoints--;  // Reduce energy points after attack
    } else {
        std::cout << "ScavTrap " << name << " cannot attack!" << std::endl; // Print a message if no energy or health to attack
    }
}

// Special function for ScavTrap
void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode!" << std::endl;
}
