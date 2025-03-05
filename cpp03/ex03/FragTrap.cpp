/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:48:30 by alvutina          #+#    #+#             */
/*   Updated: 2024/11/07 14:48:36 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructor
FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    hitPoints = 100;       // Set hit points to 100
    energyPoints = 100;    // Set energy points to 100
    attackDamage = 30;     // Set attack damage to 30
    std::cout << "FragTrap " << name << " has been constructed!" << std::endl;
}

// Destructor
FragTrap::~FragTrap() {
    std::cout << "FragTrap " << name << " has been destroyed!" << std::endl;
}

// Override attack method
void FragTrap::attack(const std::string &target) {
    if (energyPoints > 0 && hitPoints > 0) {
        std::cout << "FragTrap " << name << " attacks " << target 
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else {
        std::cout << "FragTrap " << name << " cannot attack!" << std::endl;
    }
}

// Special function for high fives
void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}
