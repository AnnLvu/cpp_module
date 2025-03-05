/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:33:17 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 11:35:50 by alvutina         ###   ########.fr       */
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
	
	 int getLogLevelIndex(const std::string& level) const;

};

#endif