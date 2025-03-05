/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:33:29 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 10:33:30 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon) {}


HumanA::~HumanA(){}

void HumanA::attack() const {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
