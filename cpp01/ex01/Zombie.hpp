/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:33:10 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 10:33:11 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
private:
    std::string name;  // Private attribute for the zombie's name

public:
    Zombie();
    Zombie(std::string name); // Constructor to set the zombie's name
    ~Zombie(); // Destructor to print a message when the zombie is destroyed

    void announce() const; // Method to announce the zombie
    void give_name(std::string name);
    Zombie*	newZombie( std::string name );
};
Zombie* zombieHorde(int N, std::string name);

#endif
