/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:33:32 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 10:33:33 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
private:
    std::string name;
    Weapon& weapon;

public:
    HumanA(const std::string& name, Weapon& weapon);
    ~HumanA();
    void attack() const;
};

#endif
/*HumanA: It always has a weapon, so it stores a Weapon reference.
The weapon is passed via the constructor.*/
/*HumanA: Этот класс всегда имеет оружие, поэтому он использует ссылку на Weapon.
Оружие передается через конструктор.*/
