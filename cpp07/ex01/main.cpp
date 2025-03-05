/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:05:58 by alvutina          #+#    #+#             */
/*   Updated: 2025/02/06 11:17:17 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    const double decimals[4] = {1.13, 2.13452, 3.31234, 4.12344};
    std::string names[3] = {"Alice", "Bob", "Charlie"};

    std::cout << "===== Testing with pointer to first element of array =====\n";
    iter(&numbers[0], 5, printFunction<int>);


    std::cout << "===== Testing with integers (before increment) =====\n";
    iter(numbers, 5, printFunction<int>);

    std::cout << "===== Incrementing integers =====\n";
    iter(numbers, 5, increment<int>);

    std::cout << "===== Testing with integers (after increment) =====\n";
    iter(numbers, 5, printFunction<int>);

    std::cout << "===== Testing with decimals (const, cannot modify) =====\n";
    iter(decimals, 4, printFunction<double>);

    std::cout << "===== Testing with strings =====\n";
    iter(names, 3, printFunction<std::string>);

    
    return 0;
}