/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:54:34 by alvutina          #+#    #+#             */
/*   Updated: 2025/02/06 12:54:35 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void testMutantStack() {
    std::cout << "Testing MutantStack:" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "Stack size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "Iterating through MutantStack:" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
}

void testList() {
    std::cout << "Testing std::list:" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);

    std::cout << "Top element: " << lst.back() << std::endl;

    lst.pop_back();
    std::cout << "List size after pop: " << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();

    std::cout << "Iterating through std::list:" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
}

int main() {
    testMutantStack();
    std::cout << "-----------------" << std::endl;
    testList();
    return 0;
}
