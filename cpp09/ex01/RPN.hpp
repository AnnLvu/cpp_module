/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:47:15 by alvutina          #+#    #+#             */
/*   Updated: 2025/03/03 10:47:16 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>

class RPN {
public:
    RPN(const std::string &expr);
    RPN(const RPN &other);
    RPN& operator=(const RPN &other);
    ~RPN();

    void evaluate();
private:
    std::string expr_; //for saving the expression
    std::stack<int> operands_; //for saving the operands
    void processOperator(char op);
    void processOperand(const std::string &operand);
    bool isOperator(char c);
    bool isValidOperand(const std::string &str);
};

#endif
