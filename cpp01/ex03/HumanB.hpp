/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:33:37 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 10:33:38 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon* weapon;

public:
    HumanB(const std::string& name);
    ~HumanB();
    void setWeapon(Weapon& weapon);
    void attack() const;
};

#endif
/*HumanB: It may or may not have a weapon, so it stores a Weapon pointer,
which is set later by the setWeapon() method.*/
/*HumanB: Этот класс может не иметь оружия, поэтому он использует указатель на Weapon,
который можно задать позже через метод setWeapon().*/
