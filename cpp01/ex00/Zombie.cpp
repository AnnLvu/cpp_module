/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:32:38 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 10:32:40 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
    Zombie::name = name;
}

Zombie::~Zombie() {
    std::cout << name << " is destroyed." << std::endl;
}

void Zombie::announce() const {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
