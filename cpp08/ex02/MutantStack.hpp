/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:54:37 by alvutina          #+#    #+#             */
/*   Updated: 2025/02/06 12:54:38 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <iostream>
#include <list>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack();
    MutantStack(const MutantStack &other);
    MutantStack &operator=(const MutantStack &other);
    ~MutantStack();

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin();
    iterator end();
};

#include "MutantStack.tpp"

#endif
