/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:05:55 by alvutina          #+#    #+#             */
/*   Updated: 2025/02/06 11:13:49 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

// Template function to print array elements
// This function takes a constant reference to an element and prints it.
template <typename T>
void printFunction(const T& element) {
    std::cout << element << std::endl;
}

// Template function to increment an element (modifiable version)
// This function takes a reference to an element and increments it.
template <typename T>
void increment(T& element) {
    ++element;
}

// Template function iter for modifiable arrays
// This function iterates over an array and applies the given function to each element.
// The function pointer takes a reference to allow modification of elements.
template <typename T>
void iter(T* array, size_t size, void (*func)(T&)) {
    for (size_t i = 0; i < size; ++i) {
        func(array[i]);  // Apply the function to each element
    }
}

// Template function iter for constant arrays
// This overload is for read-only operations, ensuring elements are not modified.
// The function pointer takes a constant reference to prevent modification.
template <typename T>
void iter(const T* array, size_t size, void (*func)(const T&)) {
    for (size_t i = 0; i < size; ++i) {
        func(array[i]);  // Apply the function to each element
    }
}

#endif

