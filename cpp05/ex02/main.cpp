/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:16:37 by alvutina          #+#    #+#             */
/*   Updated: 2025/02/03 18:17:20 by cmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The task was to implement a hierarchy of forms (AForm) and specific derived classes
 (ShrubberyCreationForm, RobotomyRequestForm, and PresidentialPardonForm).
 These forms require a bureaucrat (Bureaucrat) to sign and execute them.
 Each form has specific grade requirements for signing and execution:

ShrubberyCreationForm:
 Creates a file <target>_shrubbery with ASCII trees inside.
Requires grade 145 to sign and 137 to execute.

RobotomyRequestForm:
 Makes drilling noises and performs a robotomy on the target with a 50% success rate.
 Requires grade 72 to sign and 45 to execute.

PresidentialPardonForm:
Announces that the target has been pardoned by Zaphod Beeblebrox.
Requires grade 25 to sign and 5 to execute.

The base class AForm must be abstract and contain shared functionality.
Exceptions should be thrown for insufficient grades or unsigned forms.
Additionally, a Bureaucrat can attempt to sign or execute a form,
with appropriate success or error messages printed to the console.*/
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

    // Инициализация генератора случайных чисел
    srand(time(0));
    try {
        Bureaucrat bob("Bob", 2);
        ShrubberyCreationForm formA("home");
        RobotomyRequestForm formB("target1");
        PresidentialPardonForm formC("target2");

        bob.signForm(formA);
        bob.executeForm(formA);

        bob.signForm(formB);
        bob.executeForm(formB);

        bob.signForm(formC);
        bob.executeForm(formC);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        Bureaucrat alice("Alice", 25);
        PresidentialPardonForm formD("target3");
        alice.signForm(formD);
        alice.executeForm(formD);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
