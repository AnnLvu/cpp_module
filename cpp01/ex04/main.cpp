/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:40:22 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 11:11:54 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"
/* 1. Проверяет количество аргументов командной строки.
Если их не 4, выводит инструкцию по использованию программы.
2. Инициализация переменных
3. Проверка s1 на пустоту
4. Создается объект FileReplacer и вызывается метод replace. 
Если метод возвращает false, программа завершает выполнение с ошибкой.
5. При успешной замене выводится сообщение о создании файла.
*/
/* 1. Checks that there are exactly 4 command-line arguments. If not, displays usage instructions.
2. Initialize variables
3. Check if s1 is empty
4. A FileReplacer object is created and replace() is called.
If it returns false, the program exits with an error.
5. On success, a message indicates that the new file has been created.
*/
int main(int argc, char* argv[])
{
    if (argc != 4)
	{
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
	{
        std::cerr << "Error: s1 cannot be an empty string" << std::endl;
        return 1;
    }

    FileReplacer replacer(filename, s1, s2);
    if (!replacer.replace())
	{
        return 1;
    }

    std::cout << "File created: " << filename << ".replace" << std::endl;
    return 0;
}
