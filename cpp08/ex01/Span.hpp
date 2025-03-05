/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:54:29 by alvutina          #+#    #+#             */
/*   Updated: 2025/02/06 12:54:30 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int num);
    int shortestSpan() const;
    int longestSpan() const;

    template <typename InputIterator>
    void addRange(InputIterator begin, InputIterator end) {
        if (std::distance(begin, end) + _numbers.size() > _maxSize)
            throw std::overflow_error("Adding range exceeds Span capacity");
        _numbers.insert(_numbers.end(), begin, end);
    }

    void printNumbers() const;
    size_t getMaxSize() const;
    size_t getCurrentSize() const;
};

#endif
