/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:38:33 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 11:11:18 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"
/*
1. result – итоговая строка с замененными вхождениями s1.
pos – текущая позиция для поиска.
found – позиция найденного вхождения s1.
2. line.find(s1, pos) – ищет s1, начиная с позиции pos. Если s1 найден, возвращает позицию; если нет – npos.
result += line.substr(pos, found - pos); – добавляет часть строки от pos до найденного s1.
result += s2; – добавляет s2 вместо s1.
pos = found + s1.length(); – обновляет позицию pos для продолжения поиска после замененного s1.
3. добавляет остаток строки после последнего s1.
*/
/*
1. result – The final string with s1 replaced by s2.
pos – The current position in the string for searching.
found – The position where s1 was found
2. line.find(s1, pos) – Searches for s1 starting from pos. If found, returns its position; otherwise returns npos.
result += line.substr(pos, found - pos); – Adds text from pos up to s1.
result += s2; – Adds s2 instead of s1.
pos = found + s1.length(); – Updates pos to continue searching after the replaced s1.
3. Appends the rest of the string after the last s1 occurrence.
*/
FileReplacer::FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2)
    : filename(filename), s1(s1), s2(s2) {}

std::string FileReplacer::replaceOccurrences(const std::string& line) const
{
    std::string result;
    std::size_t pos = 0;
    std::size_t found;

    while ((found = line.find(s1, pos)) != std::string::npos) {
        result += line.substr(pos, found - pos); // Add text before `s1`
        result += s2; // Replace `s1` with `s2`
        pos = found + s1.length(); // Move past `s1`
    }
    result += line.substr(pos); // Add remaining text
    return result;
}
/*
1. std::ifstream inputFile(filename.c_str()); – открывает исходный файл для чтения.
Если не удалось открыть файл, выводится ошибка, и метод возвращает false.
2. создает новый файл <filename>.replace для записи.
3. Если файл создать не удалось, выводится ошибка, 
исходный файл закрывается, и метод возвращает false.
4. считывает файл построчно.
5. outputFile << replaceOccurrences(line) << std::endl; – записывает в новый файл строку,
обработанную методом replaceOccurrences.
6. inputFile.close() и outputFile.close() закрывают файлы после завершения записи.
*/
/*
1. std::ifstream inputFile(filename.c_str()); – Opens the source file for reading.
If the file cannot be opened, displays an error and returns false.
2. Creates a new file <filename>.replace for writing.
3. If the file cannot be created, displays an error, closes the input file, and returns false.
4.  Reads the file line by line.
5. outputFile << replaceOccurrences(line) << std::endl;
– Writes the processed line to the new file.
6. Closing Files: inputFile.close() and outputFile.close() close the files after writing
*/
bool FileReplacer::replace()
{
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
	{
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return false;
    }

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile.is_open())
	{
        std::cerr << "Error: Could not create file " << filename << ".replace" << std::endl;
        inputFile.close();
        return false;
    }

    std::string line;
    while (std::getline(inputFile, line))
	{
        outputFile << replaceOccurrences(line) << std::endl;
    }

    inputFile.close();
    outputFile.close();
    return true;
}
