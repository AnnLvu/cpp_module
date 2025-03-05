/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:38:18 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 11:34:19 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACER_HPP
#define FILEREPLACER_HPP

#include <string>
#include <fstream>
#include <iostream>

class FileReplacer
{
public:
    FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2);
    bool replace();

private:
    std::string filename;
    std::string s1;
    std::string s2;

    std::string replaceOccurrences(const std::string& line) const;
};

#endif 
/*
1. Constructor FileReplacer – Takes three parameters:
a filename (filename), the search string (s1), and the replacement string (s2). 
These values are used for replacing text in the file.
2. replace() method – This is the primary method that performs the replacement.
It returns true if successful, and false if an error occurs.
3. Private variables filename, s1, and s2 
– These store the filename and the strings for search and replacement.
4. Private method replaceOccurrences –
This method performs the replacement of all occurrences of s1 with s2 in a given string (line).
*/
/*
* Конструктор FileReplacer – принимает три параметра: 
имя файла (filename), строку для поиска (s1) и строку для замены (s2), 
которые будут использоваться для замены текста в файле.
* Метод replace() – основной метод, который выполняет замену строк в файле.
Возвращает true, если операция успешна, и false в случае ошибки.
* Приватные переменные filename, s1, и s2 – хранят имя файла и строки для поиска и замены.
* Приватный метод replaceOccurrences – выполняет замену всех вхождений s1 на s2 в переданной строке line.
*/