/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:06:03 by alvutina          #+#    #+#             */
/*   Updated: 2025/02/06 11:33:00 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <cstdlib>
#include <iostream>

template <typename T>
class Array {
private:
    T* _array;    // Pointer to the array of elements
    unsigned int _size;    // The size of the array

public:
    // Конструктор по умолчанию: создает пустой массив
    // Default constructor: Creates an empty array
    Array() : _array(NULL), _size(0) {}

    // Конструктор с параметром: создает массив из n элементов, инициализированных по умолчанию
    // Constructor with a parameter: Creates an array of n elements, initialized with default values
    Array(unsigned int n) : _array(new T[n]()), _size(n) {}

    // Copy constructor: Performs a deep copy of the array
    // Конструктор копирования: копирует массив (глубокое копирование)
    Array(const Array<T>& other) : _array(NULL), _size(0) {
        *this = other;  // Используем оператор присваивания // Use the assignment operator to copy data
    }

    // Assignment operator: Creates a deep copy of the array
    // Оператор присваивания: создает глубокую копию
    Array<T>& operator=(const Array<T>& other) {
        if (this != &other) { // Prevent self-assignment
            delete[] _array;   // Free the existing memory
            _size = other._size; // Set the size to the size of the other array
            _array = new T[_size];  // Allocate new memory for the array
            for (unsigned int i = 0; i < _size; ++i) {
                _array[i] = other._array[i];  // Copy each element from the other array
            }
        }
        return *this;
    }

    // Destructor: Frees the allocated memory
    ~Array() {
        delete[] _array;
    }

    // Оператор доступа по индексу
    // Subscript operator for access by index
    T& operator[](int index) {
        if (index < 0 || index >= static_cast<int>(_size)) {
            throw std::out_of_range("Index out of range");
        }
        return _array[index];
    }

    // Константный доступ (для чтения)
    // Const subscript operator for read-only access by index
    const T& operator[](int index) const {
        if (index < 0 || index >= static_cast<int>(_size)) {
            throw std::out_of_range("Index out of range");
        }
        return _array[index];
    }

    // Функция для получения размера массива
    // Function to get the size of the array
    unsigned int size() const {
        return _size;
    }
};

#endif
