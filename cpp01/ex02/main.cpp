/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:33:22 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 10:33:23 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
    // A string variable initialized
    std::string brain = "HI THIS IS BRAIN";

    // A pointer to the string.
    std::string *stringPTR = &brain;

    //  A reference to the string.
    std::string &stringREF = brain;

    // The memory address of the string variable.
    std::cout << "Memory address of the string variable: " << &brain << std::endl;
    // The memory address held by stringPTR.
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    // The memory address held by stringREF.
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

    // The value of the string variable.
    std::cout << "Value of the string variable: " << brain << std::endl;
    // The value pointed to by stringPTR.
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    // The value pointed to by stringREF.
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

    return 0;
}
