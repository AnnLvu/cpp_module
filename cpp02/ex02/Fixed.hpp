/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:11:23 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 13:17:18 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
    Fixed();                         // Default constructor
    Fixed(const int value);          // Int constructor
    Fixed(const float value);        // Float constructor
    Fixed(const Fixed &other);       // Copy constructor
    Fixed &operator=(const Fixed &other); // Copy assignment operator
    ~Fixed();                        // Destructor

    // Member functions for conversions
    float toFloat() const;           // Converts fixed-point value to float
    int toInt() const;               // Converts fixed-point value to int

    // Operator overloads
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    Fixed &operator++();             // Pre-increment
    Fixed operator++(int);           // Post-increment
    Fixed &operator--();             // Pre-decrement
    Fixed operator--(int);           // Post-decrement

    // Static member functions
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

    // Overloaded insertion operator
    friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

private:
    int fixedPointValue;             // Integer to store the fixed-point value
    static const int fractionalBits = 8; // Constant for the number of fractional bits
};

#endif
