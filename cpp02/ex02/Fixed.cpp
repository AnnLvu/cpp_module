/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:11:21 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 13:17:39 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : fixedPointValue(0) {}

// Int constructor
Fixed::Fixed(const int value) {
    fixedPointValue = value << fractionalBits; // Convert int to fixed-point value
}

// Float constructor
Fixed::Fixed(const float value) {
    fixedPointValue = roundf(value * (1 << fractionalBits)); // Convert float to fixed-point value
}

// Copy constructor
Fixed::Fixed(const Fixed &other) {
    fixedPointValue = other.fixedPointValue; // Copy the raw value
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        fixedPointValue = other.fixedPointValue; // Copy the raw value
    }
    return *this;
}

// Destructor
Fixed::~Fixed() {}

// Convert fixed-point value to float
float Fixed::toFloat() const {
    return static_cast<float>(fixedPointValue) / (1 << fractionalBits);
}

// Convert fixed-point value to int
int Fixed::toInt() const {
    return fixedPointValue >> fractionalBits;
}

// Overloaded comparison operators
bool Fixed::operator>(const Fixed &other) const {
    return fixedPointValue > other.fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const {
    return fixedPointValue < other.fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const {
    return fixedPointValue >= other.fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const {
    return fixedPointValue <= other.fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const {
    return fixedPointValue == other.fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const {
    return fixedPointValue != other.fixedPointValue;
}

// Overloaded arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result.fixedPointValue = fixedPointValue + other.fixedPointValue;
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result.fixedPointValue = fixedPointValue - other.fixedPointValue;
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    result.fixedPointValue = (fixedPointValue * other.fixedPointValue) >> fractionalBits; // Correctly scale
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed result;
    result.fixedPointValue = (fixedPointValue << fractionalBits) / other.fixedPointValue; // Correctly scale
    return result;
}

// Overloaded increment and decrement operators
Fixed &Fixed::operator++() { // Pre-increment
    fixedPointValue += 1; // Increment by the smallest representable value (1 in this case)
    return *this;
}

Fixed Fixed::operator++(int) { // Post-increment
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed &Fixed::operator--() { // Pre-decrement
    fixedPointValue -= 1; // Decrement by the smallest representable value (1 in this case)
    return *this;
}

Fixed Fixed::operator--(int) { // Post-decrement
    Fixed temp = *this;
    --(*this);
    return temp;
}

// Static member functions for min and max
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

// Overloaded insertion operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat(); // Output the float representation
    return out;
}
