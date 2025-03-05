/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:17:45 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 11:29:42 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;

    std::cout << "Testing DEBUG level:" << std::endl;
    harl.complain("DEBUG");

    std::cout << "\nTesting INFO level:" << std::endl;
    harl.complain("INFO");

    std::cout << "\nTesting WARNING level:" << std::endl;
    harl.complain("WARNING");

    std::cout << "\nTesting ERROR level:" << std::endl;
    harl.complain("ERROR");

    std::cout << "\nTesting invalid level:" << std::endl;
    harl.complain("UNKNOWN");

    return 0;
}
