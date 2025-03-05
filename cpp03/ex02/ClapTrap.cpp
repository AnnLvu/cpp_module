/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:02:43 by alvutina          #+#    #+#             */
/*   Updated: 2024/11/07 15:04:55 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include "ClapTrap.hpp"

// Constructor
ClapTrap::ClapTrap(const std::string &name) 
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
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

// Damage Receive Function
void ClapTrap::takeDamage(unsigned int amount) {
    if (amount >= hitPoints) {
        hitPoints = 0; // health not below 0
    } else {
        hitPoints -= amount;
    }
    std::cout << "ClapTrap " << name << " takes " << amount << " damage!" 
              << " Hit points left: " << hitPoints << std::endl;
}

// Repaired Function
void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints > 0 && hitPoints > 0) {
        hitPoints += amount; // Adding restored health points
        std::cout << "ClapTrap " << name << " is repaired by " << amount 
                  << " points! Hit points now: " << hitPoints << std::endl;
        energyPoints--; // reduce energy points
    } else {
        std::cout << "ClapTrap " << name << " cannot be repaired!" << std::endl;
    }
}


