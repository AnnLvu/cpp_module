/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:02:40 by alvutina          #+#    #+#             */
/*   Updated: 2024/11/07 15:02:15 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
protected: // Change access so that the derived class can access attributes
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;

public:
    // Constructor
    ClapTrap(const std::string &name);

    // Destructor
    ~ClapTrap();

    // Member functions
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
