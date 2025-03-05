/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:46:51 by alvutina          #+#    #+#             */
/*   Updated: 2025/03/03 10:46:52 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <cstdlib>
#include <limits>

class BitcoinExchange {
private:
    std::map<std::string, float> exchangeRates;
    bool isValidDate(const std::string& date) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    
    void readExchangeRates(const std::string& filename);
    void writeExchangeResults(const std::string& filename) const;
    float getExchangeRate(const std::string& date) const;
};

#endif
