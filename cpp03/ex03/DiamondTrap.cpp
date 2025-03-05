/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:24:23 by alvutina          #+#    #+#             */
/*   Updated: 2024/11/07 15:35:00 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), // Initialize ClapTrap's name
      FragTrap(name), // Initialize FragTrap (calls ClapTrap's constructor)
      ScavTrap(name) // Initialize ScavTrap (calls ClapTrap's constructor)
{
    this->name = name;
    hitPoints = 100; // FragTrap hit points
    energyPoints = 50; // ScavTrap energy points
    attackDamage = 30; // FragTrap attack damage
    std::cout << "DiamondTrap " << this->name << " has been created!" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->name << " has been destroyed!" << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "I am " << this->name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target); // Calls the attack function from ScavTrap
}

void DiamondTrap::takeDamage(unsigned int amount) {
    ClapTrap::takeDamage(amount); // Resolves ambiguity by calling ClapTrap's version
}

void DiamondTrap::beRepaired(unsigned int amount) {
    ClapTrap::beRepaired(amount); // Resolves ambiguity by calling ClapTrap's version
}


