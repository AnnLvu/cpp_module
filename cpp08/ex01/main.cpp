/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:54:24 by alvutina          #+#    #+#             */
/*   Updated: 2025/02/06 12:54:25 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Numbers in Span: ";
        sp.printNumbers();

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        Span bigSpan(10000);  // Максимальный размер Span
        std::vector<int> range;  // Создаем пустой вектор
        // Добавляем 10000 чисел в диапазон
        for (int i = 0; i < 10000; ++i) {
            range.push_back(i);  // Добавляем элементы по одному
        }
        // Проверяем, что размер диапазона не превышает оставшуюся емкость Span
        if (range.size() > bigSpan.getMaxSize() - bigSpan.getCurrentSize()) {
            throw std::overflow_error("Error: Range size exceeds the capacity of Span");
        }
        // Добавляем диапазон в Span
        bigSpan.addRange(range.begin(), range.end());

        std::cout << "Big Span shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Big Span longest: " << bigSpan.longestSpan() << std::endl;

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;  // Вывод ошибки
    }

    return 0;
}


