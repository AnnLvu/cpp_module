/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:33:52 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 10:33:53 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
private:
    std::string type;

public:
    Weapon();
    Weapon(const std::string& type);
    ~Weapon();
    const std::string& getType() const;
    void setType(const std::string& newType);
};

#endif
/*Weapon class:

It has a private string attribute type, which holds the weapon type.
It provides a getType() function to access the type and a setType() function to modify it.
*/
/*Класс Weapon:

Имеет приватный атрибут type для хранения типа оружия.
Включает функции getType() для получения значения типа оружия и setType() для его изменения.
*/
