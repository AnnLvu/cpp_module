/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:16:01 by alvutina          #+#    #+#             */
/*   Updated: 2025/02/03 17:52:14 by cmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

public:
    // Исключения
    // Exceptions
    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };

    // Конструктор, деструктор и копирование
    // Constructor, destructor and copying
    Bureaucrat(const std::string& name, int grade);
    virtual ~Bureaucrat();
    Bureaucrat(const Bureaucrat& other);

    Bureaucrat& operator=(const Bureaucrat& other);

    // Геттеры
    // Getters
    const std::string& getName() const;
    int getGrade() const;

    // Методы
    // Methods
    void incrementGrade();
    void decrementGrade();
};

// Перегрузка оператора <<
// Operator overload <<
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
