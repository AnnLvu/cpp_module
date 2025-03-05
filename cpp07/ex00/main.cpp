/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:05:42 by alvutina          #+#    #+#             */
/*   Updated: 2025/02/06 11:46:21 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
    std::cout << "===== INT TEST =====" << std::endl;
    int a = 2, b = 3;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "After swap:  a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
    std::cout << std::endl;

    std::cout << "===== STRING TEST =====" << std::endl;
    std::string c = "chaine1", d = "chaine2";
    std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "After swap:  c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
    std::cout << std::endl;

    std::cout << "===== DOUBLE TEST =====" << std::endl;
    double x = 4.5, y = 2.3;
    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    ::swap(x, y);
    std::cout << "After swap:  x = " << x << ", y = " << y << std::endl;
    std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
    std::cout << "max(x, y) = " << ::max(x, y) << std::endl;
    std::cout << std::endl;

    std::cout << "===== CHAR TEST =====" << std::endl;
    char ch1 = 'A', ch2 = 'Z';
    std::cout << "Before swap: ch1 = " << ch1 << ", ch2 = " << ch2 << std::endl;
    ::swap(ch1, ch2);
    std::cout << "After swap:  ch1 = " << ch1 << ", ch2 = " << ch2 << std::endl;
    std::cout << "min(ch1, ch2) = " << ::min(ch1, ch2) << std::endl;
    std::cout << "max(ch1, ch2) = " << ::max(ch1, ch2) << std::endl;
    std::cout << std::endl;

    std::cout << "===== BOOL TEST =====" << std::endl;
    bool bool1 = true, bool2 = false;
    std::cout << "Before swap: bool1 = " << bool1 << ", bool2 = " << bool2 << std::endl;
    ::swap(bool1, bool2);
    std::cout << "After swap:  bool1 = " << bool1 << ", bool2 = " << bool2 << std::endl;
    std::cout << "min(bool1, bool2) = " << ::min(bool1, bool2) << std::endl;
    std::cout << "max(bool1, bool2) = " << ::max(bool1, bool2) << std::endl;
    std::cout << std::endl;

    std::cout << "===== FLOAT TEST =====" << std::endl;
    float f1 = 1.234f, f2 = 5.678f;
    std::cout << "Before swap: f1 = " << f1 << ", f2 = " << f2 << std::endl;
    ::swap(f1, f2);
    std::cout << "After swap:  f1 = " << f1 << ", f2 = " << f2 << std::endl;
    std::cout << "min(f1, f2) = " << ::min(f1, f2) << std::endl;
    std::cout << "max(f1, f2) = " << ::max(f1, f2) << std::endl;
    std::cout << std::endl;

    return 0;
}
