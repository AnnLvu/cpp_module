/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:16:22 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/28 10:16:23 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 2);
        Form formA("FormA", 3, 5);

        std::cout << bob << std::endl;
        std::cout << formA << std::endl;

        bob.signForm(formA);
        std::cout << formA << std::endl;

        Bureaucrat alice("Alice", 150);
        Form formB("FormB", 140, 150);
        alice.signForm(formB);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

