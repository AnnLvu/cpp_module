/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:47:50 by alvutina          #+#    #+#             */
/*   Updated: 2025/03/03 10:47:51 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <limits>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);

    void sortVector(std::vector<int> &sequence);
    void sortDeque(std::deque<int> &sequence);

private:
    void mergeInsertionSort(std::vector<int> &sequence);
    void mergeInsertionSort(std::deque<int> &sequence);
    std::vector<int> generateJacobsthalSequence(int n);
};

#endif



