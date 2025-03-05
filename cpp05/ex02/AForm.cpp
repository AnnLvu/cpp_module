/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:16:25 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/28 13:37:29 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target(target) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _target(other._target) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        _isSigned = other._isSigned;
        _target = other._target;
    }
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _isSigned;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

const std::string& AForm::getTarget() const {
    return _target;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << form.getName() << ", form grade to sign: " << form.getGradeToSign()
       << ", grade to execute: " << form.getGradeToExecute()
       << ", is signed: " << (form.isSigned() ? "yes" : "no");
    return os;
}