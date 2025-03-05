/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:46:43 by alvutina          #+#    #+#             */
/*   Updated: 2025/03/03 11:19:12 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Description

    The `BitcoinExchange` program is designed to calculate the value of Bitcoin on specific dates using data from two files:
     one file contains Bitcoin exchange rates, and the other file contains dates and values for calculation.

   - **Methods**:
     - `void readExchangeRates(const std::string& filename)`:
      Reads exchange rates from a file and stores them in a `std::map` called `exchangeRates`.
     - `bool isValidDate(const std::string& date) const`:
     Checks if a string is a valid date in the format `YYYY-MM-DD`.
     - `float getExchangeRate(const std::string& date) const`:
     Returns the exchange rate for a given date. If the date is invalid or the exchange rate for that date is not found, an error message is displayed and `-1` is returned.
     - `void writeExchangeResults(const std::string& filename) const`:
     Reads a file with dates and values, calculates the Bitcoin value for each date, and outputs the results.
     
    Main Steps for Calculating Bitcoin Value on Each Date:

1. **Reading Exchange Rates**:
   - The `readExchangeRates` method reads the exchange rates file (`data.csv`) and stores them in a `std::map` called `exchangeRates`.

2. **Validating Dates**:
   - The `isValidDate` method checks if a string is a valid date in the format `YYYY-MM-DD`.

3. **Getting Exchange Rate**:
   - The `getExchangeRate` method returns the exchange rate for a given date.
   If the date is invalid or the exchange rate for that date is not found, an error message is displayed and `-1` is returned.

4. **Reading Dates and Values for Calculation**:
   - The `writeExchangeResults` method reads the file passed as a command-line argument, which contains dates and values for calculation.
   - For each line in the file, the method parses the date and value. If the value is greater than 1000 or less than 0,
   an error message is displayed and the line is skipped.

5. **Calculating Bitcoin Value**:
   - For each valid line, the method calls `getExchangeRate` to get the exchange rate for the specified date.
   - If the exchange rate is found (not `-1`), the Bitcoin value is calculated by multiplying the value by the exchange rate.
   - The result is displayed in the format `date => value = value * rate`.
*/
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    exchangeRates = other.exchangeRates;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        exchangeRates = other.exchangeRates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::readExchangeRates(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file)
    {
        std::cerr << "Error: could not open file: " << filename << std::endl;
        std::exit(1);
    }
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string date;
        float rate;
        if (std::getline(iss, date, ',') && (iss >> rate))
        {
            exchangeRates[date] = rate;
        }
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
    {
        return false;
    }
    int year, month, day;
    try
    {
        year = std::atoi(date.substr(0, 4).c_str());
        month = std::atoi(date.substr(5, 2).c_str());
        day = std::atoi(date.substr(8, 2).c_str());
    }
    catch (const std::exception&)
    {
        return false;
    }
    if (month < 1 || month > 12)
    {
        return false;
    }
    static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int maxDays = daysInMonth[month - 1];

    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
    {
        maxDays = 29;
    }
    if (day < 1 || day > maxDays)
    {
        return false;
    }
    return true;
}

float BitcoinExchange::getExchangeRate(const std::string& date) const
{
    if (!isValidDate(date))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return -1;
    }
    std::map<std::string, float>::const_iterator it = exchangeRates.lower_bound(date);
    if (it == exchangeRates.begin() && it->first != date)
    {
        std::cerr << "Error: no available exchange rate for date " << date << std::endl;
        return -1;
    }
    if (it == exchangeRates.end() || it->first != date)
    {
        --it;
    }
    return it->second;
}

void BitcoinExchange::writeExchangeResults(const std::string& filename) const
{
    std::ifstream file(filename.c_str());
    if (!file)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    bool isFirstLine = true;
    while (std::getline(file, line))
    {
        if (isFirstLine)
        {
            isFirstLine = false;
            if (line == "date | value")
            {
                continue;
            }
        }
        std::istringstream iss(line);
        std::string date, separator;
        float value;
        if (std::getline(iss, date, ' ') && std::getline(iss, separator, '|') && (iss >> value))
        {
            if (value > 1000)
            {
                std::cerr << "Error: too large a number." << std::endl;
                continue;
            }
            if (value < 0)
            {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }
            float rate = getExchangeRate(date);
            if (rate != -1)
            {
                std::cout << date << " => " << value << " = " << value * rate << std::endl;
            }
        } else
        {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
}