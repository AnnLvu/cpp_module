/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:54:15 by alvutina          #+#    #+#             */
/*   Updated: 2025/02/06 12:54:16 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <deque>

template <typename T>
typename T::iterator easyfind(T &container, int value);

#include "easyfind.tpp"

#endif
