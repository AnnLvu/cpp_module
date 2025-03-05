/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:16:19 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/28 10:31:08 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form {
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    // Исключения // Exceptions
    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };

    // Конструктор, деструктор и копирование // Constructor, destructor and copying
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    ~Form();
    Form(const Form& other);
    Form& operator=(const Form& other);

    // Геттеры // Getters
    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Методы // Methods
    void beSigned(const Bureaucrat& bureaucrat);
};

// Перегрузка оператора << // Operator overload <<
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
