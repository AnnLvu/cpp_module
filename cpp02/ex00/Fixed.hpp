/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:31:49 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 12:52:18 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
    Fixed();                                // Default constructor
    Fixed(const Fixed &other);             // Copy constructor
    Fixed &operator=(const Fixed &other); // Copy assignment operator
    ~Fixed();                            // Destructor:

    int getRawBits() const;           // Method to retrieve the raw fixed-point value
    void setRawBits(int const raw);  // Method to set the raw fixed-point value
private:
    int fixedPointValue;                  // Integer to store the raw value of the fixed-point number
    static const int fractionalBits = 8; // Constant for the number of fractional bits (always 8)
};

#endif 
