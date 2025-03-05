/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:02:45 by alvutina          #+#    #+#             */
/*   Updated: 2024/11/07 15:11:57 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    // Create a ClapTrap object
    ClapTrap claptrap("CLTP");
    claptrap.attack("Target 1");    // ClapTrap attacks "Target 1"
    claptrap.takeDamage(5);         // ClapTrap takes 5 damage
    claptrap.beRepaired(3);         // ClapTrap is repaired by 3 points

    // Create a ScavTrap object
    ScavTrap scavtrap("STP");
    scavtrap.attack("Target 2");    // ScavTrap attacks "Target 2"
    scavtrap.takeDamage(30);        // ScavTrap takes 30 damage
    scavtrap.beRepaired(10);        // ScavTrap is repaired by 10 points
    scavtrap.guardGate();           // ScavTrap enters Gatekeeper mode

    // Testing damage and recovery for ScavTrap
    scavtrap.attack("Target 3");    // ScavTrap attacks "Target 3"
    scavtrap.takeDamage(80);        // ScavTrap takes 80 damage
    scavtrap.beRepaired(20);        // ScavTrap is repaired by 20 points

    return 0;  // End of the program
}


