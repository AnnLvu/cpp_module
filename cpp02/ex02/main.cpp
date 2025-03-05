/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:11:25 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 13:31:35 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;

Fixed const b1( Fixed( 4.06f ) / Fixed( 2 ));
std::cout << b1 << std::endl;
Fixed const b2( Fixed( 4.06f ) * Fixed( 2 ));
std::cout << b2 << std::endl;

// Тестирование операторов сравнения
    std::cout << "\nComparison Operators:\n";
    std::cout << "a > b: " << (a > b) << std::endl;        // true или false в зависимости от значения a
    std::cout << "a < b: " << (a < b) << std::endl;        // true или false
    std::cout << "a >= b: " << (a >= b) << std::endl;      // true или false
    std::cout << "a <= b: " << (a <= b) << std::endl;      // true или false
    std::cout << "a == b: " << (a == b) << std::endl;      // true или false
    std::cout << "a != b: " << (a != b) << std::endl;      // true или false

    // Тестирование арифметических операторов
    std::cout << "\nArithmetic Operations:\n";
    Fixed sum = a + b;                                   // Сумма
    Fixed diff = a - b;                                  // Разность
    Fixed product = a * b;                               // Умножение
    Fixed quotient = a / b;                              // Деление

    std::cout << "a + b = " << sum << std::endl;        // Сумма a и b
    std::cout << "a - b = " << diff << std::endl;       // Разность a и b
    std::cout << "a * b = " << product << std::endl;    // Умножение a и b
    std::cout << "a / b = " << quotient << std::endl;   // Деление a и b
return 0;
}