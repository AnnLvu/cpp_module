/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:02:45 by alvutina          #+#    #+#             */
/*   Updated: 2024/11/07 15:07:53 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    // Create ClapTrap object
    ClapTrap claptrap("CLTP");
    claptrap.attack("Target 1");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);

    // Create ScavTrap object 
    ScavTrap scavtrap("STP");
    scavtrap.attack("Target 2");
    scavtrap.takeDamage(30);
    scavtrap.beRepaired(10);
    scavtrap.guardGate();

    // Testing damage and recovery ScavTrap
    scavtrap.attack("Target 3");
    scavtrap.takeDamage(80);
    scavtrap.beRepaired(20);

     // Create FragTrap object
    FragTrap fragtrap("FRAG");
    fragtrap.attack("Target 4");
    fragtrap.takeDamage(40);
    fragtrap.beRepaired(25);
    fragtrap.highFivesGuys();

     // Additional tests for FragTrap
    fragtrap.attack("Target 5");
    fragtrap.takeDamage(50);
    fragtrap.beRepaired(30);

     // Another call to highFivesGuys to check if it's working correctly
    fragtrap.highFivesGuys();

    return 0;
}

