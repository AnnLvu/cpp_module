/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:17:17 by alvutina          #+#    #+#             */
/*   Updated: 2025/02/03 18:33:25 by cmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    // Array of known forms
    static const std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    // Function pointers for creating forms
    typedef AForm* (*FormCreator)(const std::string&);
    static const FormCreator formCreators[] = {
        &createShrubberyForm,
        &createRobotomyForm,
        &createPresidentialForm
    };

    for (size_t i = 0; i < 3; ++i) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }

    std::cerr << "Error: Unknown form name \"" << formName << "\"." << std::endl;
    return NULL;
}

// Static helper functions for creating forms
AForm* Intern::createShrubberyForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}
