/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:54:26 by alvutina          #+#    #+#             */
/*   Updated: 2025/02/06 12:54:27 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
    if (_numbers.size() >= _maxSize)
        throw std::overflow_error("Span is already full");
    _numbers.push_back(num);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");
std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; ++i) {
        int span = sorted[i + 1] - sorted[i];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

    return maxVal - minVal;
}

void Span::printNumbers() const {
    for (size_t i = 0; i < _numbers.size(); ++i)
        std::cout << _numbers[i] << " ";
    std::cout << std::endl;
}

size_t Span::getMaxSize() const {
    return _maxSize;
}

size_t Span::getCurrentSize() const {
    return _numbers.size();
}
