/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:02:45 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 14:04:14 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() 
{
    ClapTrap claptrap("CLTP");

    claptrap.attack("Target 1");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);
    claptrap.attack("Target 2");
    claptrap.takeDamage(10); // This will bring hit points to 0
    claptrap.beRepaired(5);   // This will show that it can't be repaired
    claptrap.attack("Target 3"); // Can't attack because of 0 hit points

    return 0;
}
