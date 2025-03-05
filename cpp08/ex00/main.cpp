/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:54:21 by alvutina          #+#    #+#             */
/*   Updated: 2025/02/06 12:54:22 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
    std::vector<int> numbers;
    for (int i = 0; i < 10; ++i)
        numbers.push_back(i);

    try {
        std::vector<int>::iterator it = easyfind(numbers, 5);
        std::cout << "Found in vector: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(numbers, 42);
        std::cout << "Found in vector: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    try {
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << "Found in list: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::deque<int> deq;
    deq.push_back(1);
    deq.push_back(2);
    deq.push_back(3);
    deq.push_back(4);
    deq.push_back(5);

    try {
        std::deque<int>::iterator it = easyfind(deq, 3);
        std::cout << "Found in deque: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::vector<int> emptyVec;
    try {
        std::vector<int>::iterator it = easyfind(emptyVec, 1);
        std::cout << "Found in empty vector: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

