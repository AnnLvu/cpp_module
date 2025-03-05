/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:47:47 by alvutina          #+#    #+#             */
/*   Updated: 2025/03/03 12:00:43 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Description

The `PmergeMe` program is designed to sort a sequence of positive integers using the merge-insert sort algorithm (Ford-Johnson algorithm).
The program takes a sequence of integers as command-line arguments, processes them,
and outputs the sorted sequence along with the time taken to sort using two different containers: `std::vector` and `std::deque`.

   - **Methods**:
     - `void sortVector(std::vector<int> &sequence)`: Sorts the sequence using `std::vector` and measures the time taken.
     - `void sortDeque(std::deque<int> &sequence)`: Sorts the sequence using `std::deque` and measures the time taken.
     - `void mergeInsertionSort(std::vector<int> &sequence)`: Implements the merge-insert sort algorithm for `std::vector`.
     - `void mergeInsertionSort(std::deque<int> &sequence)`: Implements the merge-insert sort algorithm for `std::deque`.
     - `std::vector<int> generateJacobsthalSequence(int n)`: Generates the Jacobsthal sequence for insertion optimization.

1. **Initialization**:
   - An `PmergeMe` object is created.

2. **Sorting the Sequence**:
   - The `sortVector` and `sortDeque` methods sort the sequence using `std::vector` and `std::deque` respectively,
   and measure the time taken.

3. **Merge-Insertion Sort Algorithm**:
   - The `mergeInsertionSort` method splits the sequence into pairs, sorts each pair, and recursively sorts the main sequence.
   - The Jacobsthal sequence is generated to optimize the insertion of elements.
   - The second elements of the pairs are inserted into the sorted main sequence using binary search.

4. **Output**:
   - The sorted sequence and the time taken for sorting using each container are printed.

 Detailed Steps of the Algorithm

1. Splitting into Pairs:
   - The sequence is split into pairs of elements. If the sequence has an odd number of elements, the last element remains unpaired.

2. Sorting Each Pair:
   - Each pair is sorted so that the first element is greater than or equal to the second element.

3. Creating the Main Sequence:
   - The main sequence is created from the first elements of each pair. If there is an unpaired element, it is added to the end of the main sequence.

4. Recursive Sorting of the Main Sequence:
   - The `mergeInsertionSort` method is called recursively to sort the main sequence.

5. Generating the Jacobsthal Sequence:
   - The Jacobsthal sequence is generated to determine the order in which the second elements of the pairs will be inserted into the main sequence.

6. Inserting the Second Elements of the Pairs:
   - The second elements of the pairs are inserted into the sorted main sequence using binary search, following the order determined by the Jacobsthal sequence.

7. Final Sorting:
   - The final sorted sequence is obtained after all the second elements of the pairs have been inserted into the main sequence.
   */
#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { (void)other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other) { (void)other; return *this; }

void PmergeMe::sortVector(std::vector<int> &sequence)
{
    clock_t start = clock();  // Начало замера времени
    mergeInsertionSort(sequence);  // Сортируем
    clock_t end = clock();  // Конец замера времени

    // Выводим отсортированную последовательность для vector
    std::cout << "After: ";
    for (size_t i = 0; i < sequence.size(); ++i)
        std::cout << sequence[i] << " ";
    std::cout << "\n";

    // Выводим время для vector в микросекундах (us)
    double duration = (double)(end - start) / CLOCKS_PER_SEC * 1000000;  // Микросекунды
    std::cout << "Time to process a range of " << sequence.size()
              << " elements with std::vector: "
              << duration << " us\n";
}

void PmergeMe::sortDeque(std::deque<int> &sequence) {
    clock_t start = clock();  // Начало замера времени
    mergeInsertionSort(sequence);  // Сортируем
    clock_t end = clock();  // Конец замера времени

    // Выводим отсортированную последовательность для deque
    // std::cout << "After: ";
    // for (size_t i = 0; i < sequence.size(); ++i)
    //     std::cout << sequence[i] << " ";
    // std::cout << "\n";

    // Выводим время для deque в микросекундах (us)
    double duration = (double)(end - start) / CLOCKS_PER_SEC * 1000000;  // Микросекунды
    std::cout << "Time to process a range of " << sequence.size()
              << " elements with std::deque: "
              << duration << " us\n";
}

void PmergeMe::mergeInsertionSort(std::vector<int> &sequence)
{
    if (sequence.size() < 2)
        return;

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < sequence.size(); i += 2)
        pairs.push_back(std::make_pair(sequence[i], sequence[i + 1]));

    for (size_t i = 0; i < pairs.size(); ++i)
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);

    std::vector<int> mainSeq;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainSeq.push_back(pairs[i].first);

    if (sequence.size() % 2)
        mainSeq.push_back(sequence.back());

    mergeInsertionSort(mainSeq);

    std::vector<int> jacobsthal = generateJacobsthalSequence(mainSeq.size());
    for (size_t i = 0; i < pairs.size(); ++i)
        mainSeq.insert(std::lower_bound(mainSeq.begin(), mainSeq.end(), pairs[i].second), pairs[i].second);

    sequence.assign(mainSeq.begin(), mainSeq.end());
}

void PmergeMe::mergeInsertionSort(std::deque<int> &sequence)
{
    if (sequence.size() < 2)
        return;

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < sequence.size(); i += 2)
        pairs.push_back(std::make_pair(sequence[i], sequence[i + 1]));

    for (size_t i = 0; i < pairs.size(); ++i)
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);

    std::deque<int> mainSeq;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainSeq.push_back(pairs[i].first);

    if (sequence.size() % 2)
        mainSeq.push_back(sequence.back());

    mergeInsertionSort(mainSeq);

    std::vector<int> jacobsthal = generateJacobsthalSequence(mainSeq.size());
    for (size_t i = 0; i < pairs.size(); ++i)
        mainSeq.insert(std::lower_bound(mainSeq.begin(), mainSeq.end(), pairs[i].second), pairs[i].second);

    sequence.assign(mainSeq.begin(), mainSeq.end());
}

std::vector<int> PmergeMe::generateJacobsthalSequence(int n)
{
    std::vector<int> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    while (jacob.back() < n)
        jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);
    return jacob;
}

