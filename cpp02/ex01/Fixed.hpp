/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:58:16 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 12:58:17 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> // for roundf

class Fixed
{
public:
    Fixed(); // Default constructor
    Fixed(const int value); // Constructor that takes an integer
    Fixed(const float value); // Constructor that takes a float
    Fixed(const Fixed &other); // Copy constructor
    Fixed &operator=(const Fixed &other); // Copy assignment operator
    ~Fixed(); // Destructor

    int getRawBits() const; // Get the raw value
    void setRawBits(int const raw); // Set the raw value
    float toFloat() const; // Convert fixed-point to float
    int toInt() const; // Convert fixed-point to int

private:
    int fixedPointValue; // Stores the fixed-point value
    static const int fractionalBits = 8; // Number of fractional bits
};

// Overloading the insertion operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP
