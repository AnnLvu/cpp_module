/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:06:06 by alvutina          #+#    #+#             */
/*   Updated: 2025/02/04 14:06:07 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    std::cout << "Filling arrays with random values..." << std::endl;
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "Testing copy constructor and assignment operator..." << std::endl;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    std::cout << "Verifying if data is correctly copied..." << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "Testing out-of-bounds access..." << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Caught exception: " << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Caught exception: " << e.what() << '\n';
    }
    std::cout << "Filling numbers with new random values..." << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    std::cout << "Test complete!" << std::endl;
    return 0;
}
