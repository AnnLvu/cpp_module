/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:44:26 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 14:49:52 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Конструктор
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    hitPoints = 100;       // Устанавливаем здоровье 100
    energyPoints = 50;     // Устанавливаем очки энергии 50
    attackDamage = 20;     // Устанавливаем урон атаки 20
    std::cout << "ScavTrap " << name << " has been created!" << std::endl;
}

// Деструктор
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " has been destroyed!" << std::endl;
}

// Переопределение функции атаки
void ScavTrap::attack(const std::string &target) {
    if (energyPoints > 0 && hitPoints > 0) {
        std::cout << "ScavTrap " << name << " attacks " << target 
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else {
        std::cout << "ScavTrap " << name << " cannot attack!" << std::endl;
    }
}

// Специальная функция
void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode!" << std::endl;
}
