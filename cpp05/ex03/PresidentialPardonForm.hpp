/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:17:29 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/28 13:48:52 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    virtual ~PresidentialPardonForm();

    void execute(const Bureaucrat& executor) const;
};

#endif
