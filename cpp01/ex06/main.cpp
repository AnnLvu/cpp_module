/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:33:19 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 11:36:44 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include "Harl.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <log_level>" << std::endl;
        return 1;
    }

    std::string level = argv[1];
    Harl harl;
    harl.complain(level);

    return 0;
}
