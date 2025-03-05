/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:17:42 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 11:34:08 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>


class Harl 
{
public:
    void complain(const std::string& level);

private:
    void debug();
    void info();
    void warning();
    void error();
};

#endif