/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:44:50 by alvutina          #+#    #+#             */
/*   Updated: 2024/11/07 14:46:29 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    // Конструктор
    ScavTrap(const std::string &name);

    // Деструктор
    ~ScavTrap();

    // Переопределение метода атаки
    void attack(const std::string &target);

    // Специальная функция
    void guardGate();
};

#endif
