/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:17:13 by alvutina          #+#    #+#             */
/*   Updated: 2025/02/03 18:28:35 by cmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для time(0)
#include "AForm.hpp"

class AForm;

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat(const std::string& name, int grade);
    virtual ~Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);

    const std::string& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();
    void signForm(AForm& form);
    void executeForm(const AForm& form) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
