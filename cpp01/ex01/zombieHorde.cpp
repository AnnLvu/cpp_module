/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:33:14 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 10:33:15 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0) return NULL;

    Zombie* horde = new Zombie[N];

    for (int i = 0; i < N; ++i) {
        horde[i].give_name(name);
        horde[i].announce();
    }

    return horde;
}
