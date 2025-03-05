/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:44:50 by alvutina          #+#    #+#             */
/*   Updated: 2024/11/07 15:13:53 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    // Constructor for ScavTrap
    ScavTrap(const std::string &name);

    // Destructor for ScavTrap
    ~ScavTrap();

    // Overridden attack method for ScavTrap
    void attack(const std::string &target);

    // Special function specific to ScavTrap
    void guardGate();
};

#endif
