/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:33:14 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 11:36:18 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug() {
    std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

int Harl::getLogLevelIndex(const std::string& level) const {
    if (level == "DEBUG") return 0;
    if (level == "INFO") return 1;
    if (level == "WARNING") return 2;
    if (level == "ERROR") return 3;
    return -1; // For unrecognized levels
}

void Harl::complain(const std::string& level) {
    int levelIndex = getLogLevelIndex(level);

    switch (levelIndex) {
        case 0:  // DEBUG
            debug();
        case 1:  // INFO
            info();
        case 2:  // WARNING
            warning();
        case 3:  // ERROR
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}