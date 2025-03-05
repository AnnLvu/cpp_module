/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:59:05 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 13:01:27 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixedPointValue = other.fixedPointValue; // Copy the raw value directly
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->fixedPointValue = other.fixedPointValue; // Directly copy the value
    }
    return *this; // Return the current object
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = value << fractionalBits; // Convert integer to fixed-point
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(value * (1 << fractionalBits)); // Convert float to fixed-point
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPointValue; // Return the raw value
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw; // Set the raw value
}

float Fixed::toFloat() const
{
    return static_cast<float>(this->fixedPointValue) / (1 << fractionalBits); // Convert fixed-point to float
}

int Fixed::toInt() const
{
    return this->fixedPointValue >> fractionalBits; // Convert fixed-point to integer
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat(); // Output the floating-point representation
    return out; // Return the output stream
}
