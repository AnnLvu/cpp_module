/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:31:52 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 12:55:20 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

 // Default constructor: Initializes the fixed-point number to zero.
Fixed::Fixed() : fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// Destructor: Called when a Fixed object goes out of scope to clean up resources.
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// Copy constructor: Initializes a new Fixed object as a copy of 'other'.
Fixed::Fixed(const Fixed &other)
{
   std::cout << "Copy constructor called" << std::endl;
    this->fixedPointValue = other.fixedPointValue;// Используем оператор присваивания для копирования значения
}

// Copy assignment operator: Assigns the value of 'other' to this Fixed object.
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
	{
        this->fixedPointValue = other.getRawBits(); // Копируем значение fixedPointValue
    }
    return *this;
}

// Getter for the raw fixed-point value: returns the current value.
int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPointValue;
}

// Setter for the raw fixed-point value: sets the value of the fixed-point number.
void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw;
}
