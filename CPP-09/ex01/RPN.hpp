#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN {
public:
    RPN();
    ~RPN();
    static int evaluate(const std::string &expression);
};

#endif
