/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:17:31 by alvutina          #+#    #+#             */
/*   Updated: 2025/02/03 18:31:11 by cmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request Form", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (!isSigned()) throw GradeTooLowException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::cout << "Drilling noises..." << std::endl;
    if (rand() % 2)
        std::cout << getTarget() << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy failed for " << getTarget() << std::endl;
}
