/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:24:00 by alvutina          #+#    #+#             */
/*   Updated: 2024/11/07 15:36:37 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
    std::string name;  // DiamondTrap's name

public:
    // Constructor
    DiamondTrap(const std::string &name);

    // Destructor
    ~DiamondTrap();

    // Special function
    void whoAmI();

    // Overridden attack function
    void attack(const std::string &target);

     // Inherit takeDamage and beRepaired from ClapTrap (no need to redefine)
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif

