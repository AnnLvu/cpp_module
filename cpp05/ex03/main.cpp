/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:17:23 by alvutina          #+#    #+#             */
/*   Updated: 2025/02/03 18:28:18 by cmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The task was to implement the Intern class with the ability to create forms
 dynamically using a function makeForm. Key requirements:

Dynamic Form Creation:
 The Intern should create a form object based on a given name (e.g., "robotomy request").

Clean Dispatching:
 Use an array of function pointers for form creation, avoiding if/else structures.

Error Handling:
If an unknown form name is provided, an explicit error message should be displayed.

Testing: Verify the intern creates valid forms, the forms can be signed and executed by a Bureaucrat,
 and handle invalid inputs gracefully.*/
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    srand(time(0));
    try {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm shrubbery("Garden");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Alice");

        std::cout << "\n--- Testing Bureaucrat and Forms ---\n" << std::endl;

        bob.signForm(shrubbery);
        bob.executeForm(shrubbery);

        bob.signForm(robotomy);
        bob.executeForm(robotomy);

        bob.signForm(pardon);
        bob.executeForm(pardon);

        std::cout << "\n--- Testing Intern ---\n" << std::endl;

        Intern someRandomIntern;
        AForm* form;

        // Test 1: Robotomy Request Form
        form = someRandomIntern.makeForm("robotomy request", "Bender");
        if (form) {
            bob.signForm(*form);
            bob.executeForm(*form);
            delete form;
        }

        // Test 2: Shrubbery Creation Form
        form = someRandomIntern.makeForm("shrubbery creation", "Park");
        if (form) {
            bob.signForm(*form);
            bob.executeForm(*form);
            delete form;
        }

        // Test 3: Presidential Pardon Form
        form = someRandomIntern.makeForm("presidential pardon", "Charlie");
        if (form) {
            bob.signForm(*form);
            bob.executeForm(*form);
            delete form;
        }

        // Test 4: Unknown Form
        form = someRandomIntern.makeForm("unknown form", "Target");
        if (!form) {
            std::cout << "Failed to create an unknown form." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
