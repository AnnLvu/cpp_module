/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:47:53 by alvutina          #+#    #+#             */
/*   Updated: 2024/11/07 15:34:01 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
    // Constructor
    FragTrap(const std::string &name);

    // Destructor
    ~FragTrap();

    // Override the attack function
    void attack(const std::string &target);

    // Special function for high fives
    void highFivesGuys();
};

#endif
