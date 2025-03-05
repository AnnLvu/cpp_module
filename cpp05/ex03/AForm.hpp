/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:17:07 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/28 13:46:59 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
protected:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
    const std::string _target;

public:
    AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target);
    virtual ~AForm();

    AForm(const AForm& other);
    AForm& operator=(const AForm& other);

    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    const std::string& getTarget() const;

    void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    virtual void execute(const Bureaucrat& executor) const = 0; // Pure virtual method
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
