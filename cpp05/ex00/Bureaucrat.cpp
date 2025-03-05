/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:15:57 by alvutina          #+#    #+#             */
/*   Updated: 2025/02/03 17:49:46 by cmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Исключения
// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

// Конструктор
// Constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

// Деструктор
// Destructor
Bureaucrat::~Bureaucrat() {}

// Конструктор копирования
// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

// Оператор присваивания
// Assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        _grade = other._grade;
    }
    return *this;
}

// Геттеры
// Getters
const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

// Методы
// Methods
void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

// Перегрузка оператора <<
// Operator overload <<
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
