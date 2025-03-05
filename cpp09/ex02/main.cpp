/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:47:40 by alvutina          #+#    #+#             */
/*   Updated: 2025/03/03 12:09:51 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


bool isValidNumber(const std::string &str) {
    // Проверяем, состоит ли строка только из цифр
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] < '0' || str[i] > '9') {
            return false;  // Если символ не цифра, возвращаем false
        }
    }
    return true;  // Если все символы цифры, возвращаем true
}

long long stringToLongLong(const std::string &str) {
    long long num;
    std::stringstream ss(str);
    ss >> num;  // Преобразуем строку в long long
    return num;
}

bool isEmptyOrWhitespace(const std::string &str) {
    // Проверяем, является ли строка пустой или состоит только из пробелов
    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isspace(str[i])) {
            return false;  // Если найден не пробельный символ, возвращаем false
        }
    }
    return true;  // Если все символы пробельные, возвращаем true
}

bool isOutOfRange(int num) {
    // Проверяем, не выходит ли число за пределы допустимого диапазона int
    if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max()) {
        return true;
    }
    return false;
}

bool isOutOfRange(long long num) {
    // Проверяем, выходит ли число за пределы диапазона для int
    if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max()) {
        return true;
    }
    return false;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: Not enough arguments.\n";
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    // Чтение входных данных
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        // Если строка пустая или состоит только из пробелов, выводим ошибку
        if (isEmptyOrWhitespace(arg)) {
            std::cerr << "Error: Invalid input (empty or whitespace string).\n";
            return 1;
        }

        // Разбиваем строку на числа
        std::istringstream iss(arg);
        std::string number;

        while (iss >> number) {
            // Проверяем, что строка содержит только положительные числа
            if (!isValidNumber(number)) {
                std::cerr << "Error: Invalid input (negative numbers, letters, or special characters are not allowed).\n";
                return 1;
            }

            // Преобразуем строку в long long
            long long num = stringToLongLong(number);

            // Проверяем, что число лежит в пределах допустимого диапазона для int
            if (isOutOfRange(num)) {
                std::cerr << "Error: Number out of range for int" << "\n";
                return 1;
            }

            // Преобразуем в int, если всё в порядке
            vec.push_back(static_cast<int>(num));
            deq.push_back(static_cast<int>(num));
        }
    }

    // Выводим исходную последовательность
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << "\n";

    // Сортируем и выводим для vector
    PmergeMe sorter;
    sorter.sortVector(vec);

    // Сортируем и выводим для deque
    sorter.sortDeque(deq);

    return 0;
}



