/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:16:15 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/28 10:30:46 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Исключения   // Exceptions
const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

// Конструктор  // Constructor
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

// Деструктор // Destructor
Form::~Form() {}

// Конструктор копирования  // Copy constructor
Form::Form(const Form& other)
    : _name(other._name),
      _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute) {}

// Оператор присваивания // Assignment operator
Form& Form::operator=(const Form& other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

// Геттеры // Getters
const std::string& Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _isSigned;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

// Методы // Methods
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

// Перегрузка оператора << // Operator overload <<
std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName()
       << " [signed: " << (form.isSigned() ? "yes" : "no")
       << ", grade to sign: " << form.getGradeToSign()
       << ", grade to execute: " << form.getGradeToExecute() << "]";
    return os;
}
