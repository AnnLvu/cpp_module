/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:16:53 by alvutina          #+#    #+#             */
/*   Updated: 2025/02/03 18:34:21 by cmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation Form", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!isSigned()) throw std::runtime_error("Form not signed");
    if (executor.getGrade() > getGradeToExecute())
        throw std::runtime_error("Grade too low to execute");

    std::ofstream file((getTarget() + "_shrubbery").c_str());
    file << "ASCII tree art" << std::endl;
    std::cout << "Shrubbery created at " << getTarget() << std::endl;
}
