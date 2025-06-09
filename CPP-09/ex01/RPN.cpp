#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <cstdlib> 

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(RPN const &) {}

RPN &RPN::operator=(RPN const &) {
    return *this;
}


int RPN::evaluate(const std::string& expression) {

    std::stack<int> stack;
    std::stringstream ss(expression); 
    std::string token;

    while (ss >> token) {
        if (std::isdigit(token[0]) && token.size() == 1) {
            stack.push(token[0] - '0');
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2) {
                throw std::runtime_error("Error : Not enough operands.\n");
            }

            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            int result = 0;

            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else if (token == "/") {
                if (b == 0) throw std::runtime_error("Error : Division by zero.");
                result = a / b;
            }

            stack.push(result);
        } else {
            throw std::runtime_error("Error.");
        }
    }

    if (stack.size() != 1) {
        throw std::runtime_error("Error : Invalid RPN expression.");
    }

    return stack.top(); 
}