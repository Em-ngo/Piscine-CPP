#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>

class RPN {

private:
    RPN(RPN const &);
    RPN &operator=(RPN const &);

public:
    RPN();
    ~RPN();
    static int evaluate(const std::string &expression);
};

#endif
