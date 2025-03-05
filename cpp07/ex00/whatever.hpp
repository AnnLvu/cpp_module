/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:05:48 by alvutina          #+#    #+#             */
/*   Updated: 2025/02/06 11:46:40 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

// Swap function template
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Min function template
template <typename T>
T min(const T& a, const T& b) {
    return (b < a) ? b : a;
}

// Max function template
template <typename T>
T max(const T& a, const T& b) {
    return (a < b) ? b : a;
}

#endif
