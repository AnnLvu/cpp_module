/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:47:09 by alvutina          #+#    #+#             */
/*   Updated: 2025/03/03 11:38:27 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Description

The `RPN` program is designed to evaluate mathematical expressions written in reverse Polish notation.
The program takes an expression as a command-line argument, processes it, and outputs the result.
1.Class `RPN`:
     - Constructors and Destructor:
     - `RPN(const std::string &expr)`: Initializes the object with the given expression.
     - `RPN(const RPN &other)`: Copy constructor.
     - `RPN& operator=(const RPN &other)`: Assignment operator.
     - `~RPN()`: Destructor.

   - Methods:
     - `bool isOperator(char c)`: Checks if a character is a valid operator (`+`, `-`, `*`, `/`).
     - `bool isValidOperand(const std::string &str)`: Checks if a string is a valid operand (a digit less than 10).
     - `void processOperator(char op)`: Processes an operator by applying it to the top two operands on the stack.
     - `void processOperand(const std::string &operand)`: Processes an operand by pushing it onto the stack.
     - `void evaluate()`: Evaluates the expression stored in the object.

1. Initialization:
   - An `RPN` object is created with the given expression.
2. **Evaluation of the Expression**:
   - The `evaluate` method splits the expression into tokens using `std::istringstream`.
   - For each token:
     - If the token is an operator (`+`, `-`, `*`, `/`), the `processOperator` method is called.
     - If the token is an operand (a digit less than 10), the `processOperand` method is called.
3. **Processing Operators**:
   - The `processOperator` method pops the top two operands from the stack,
   applies the operator, and pushes the result back onto the stack.
4. **Processing Operands**:
   - The `processOperand` method checks if the token is a valid operand and pushes it onto the stack.
5. **Checking the Result**:
   - After processing all tokens, the `evaluate` method checks that there is exactly one operand left on the stack.
   If not, an error is reported.
   - If the expression is valid, the result (the top of the stack) is printed.
*/
#include "RPN.hpp"

RPN::RPN(const std::string &expr) : expr_(expr) {}

RPN::RPN(const RPN &other) : expr_(other.expr_), operands_(other.operands_) {}

RPN& RPN::operator=(const RPN &other)
{
    if (this != &other) {
        expr_ = other.expr_;
        operands_ = other.operands_;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::isValidOperand(const std::string &str)
{
    for (size_t i = 0; i < str.length(); ++i) {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    int num = atoi(str.c_str());
    return (num < 10);
}

void RPN::processOperator(char op)
{
    if (operands_.size() < 2)
    {
        std::cerr << "Error\n";
        exit(1);
    }
    int b = operands_.top(); operands_.pop();
    int a = operands_.top(); operands_.pop();
    int result = 0;
    if (op == '+')
        result = a + b;
    else if (op == '-')
        result = a - b;
    else if (op == '*')
        result = a * b;
    else if (op == '/')
    {
        if (b == 0)
        {
            std::cerr << "Error\n";
            exit(1);
        }
        result = a / b;
    }
    operands_.push(result);
}

void RPN::processOperand(const std::string &operand)
{
    if (isValidOperand(operand)) {
        operands_.push(atoi(operand.c_str()));
    } else {
        std::cerr << "Error\n";
        exit(1);
    }
}

void RPN::evaluate()
{
    std::istringstream iss(expr_);
    std::string token;
    while (iss >> token) {
        if (token.length() == 1 && isOperator(token[0])) {
            processOperator(token[0]);
        } else {
            processOperand(token);
        }
    }

    if (operands_.size() != 1) {
        std::cerr << "Error\n";
        exit(1);
    }
    std::cout << operands_.top() << std::endl;
}
