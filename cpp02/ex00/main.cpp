/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:30:12 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 12:52:44 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
Fixed a;
Fixed b( a );
Fixed c;
c = b;
std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;
return 0;
}

/*"Default constructor called" выводится дважды, потому что вы вызываете конструктор по умолчанию дважды:
При создании Fixed a;
При создании Fixed c; (это нормально, так как c - это новый объект, который также должен вызывать конструктор).
*/
/*
"The 'Default constructor called' message is printed twice because the default constructor is invoked for two different objects:
1. When creating the object 'Fixed a;', the default constructor is called to initialize 'a'.
2. When creating the object 'Fixed c;', the default constructor is called again to initialize 'c'.
This behavior is expected and normal, as each object of the 'Fixed' class requires its own separate initialization."
*/
