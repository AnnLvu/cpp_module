/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:16:04 by alvutina          #+#    #+#             */
/*   Updated: 2025/02/03 17:55:29 by cmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;

        bob.incrementGrade();
        std::cout << bob << std::endl;

        bob.incrementGrade(); // Исключение // Exception
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "---------------------" << std::endl;

    try {
        Bureaucrat alice("Alice", 150);
        std::cout << alice << std::endl;

        alice.decrementGrade(); // Исключение // Exception
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
