#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {

}

ScalarConverter::~ScalarConverter() {

}

ScalarConverter::ScalarConverter(const ScalarConverter &) {

}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) {
    return *this;
}

bool ScalarConverter::isPseudoLiteral(const std::string &literal) {
    return literal == "nan" || literal == "nanf" ||
           literal == "+inf" || literal == "-inf" ||
           literal == "+inff" || literal == "-inff";
}

std::string ScalarConverter::detectType(const std::string &literal) {
    if (isPseudoLiteral(literal)) {
        return "pseudo-literal";
    }
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        return "char";
    }
    char *end;
    strtol(literal.c_str(), &end, 10); // str to integer
    if (*end == '\0') {
        return "int";
    }
    strtof(literal.c_str(), &end); // str to float
    if (*end == 'f' && *(end + 1) == '\0' && literal.find('.') != std::string::npos) {
        return "float";
    }
    strtod(literal.c_str(), &end); // str to double
    if (*end == '\0' && literal.find('.') != std::string::npos) {
        return "double";
    }
    return "invalid";
}

void ScalarConverter::printChar(double value) {
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 255) {
        std::cout << "char: impossible\n";
        return;
    }
    char c = static_cast<char>(value);
    if (std::isprint(c)) {
        std::cout << "char: '" << c << "'\n";
    } else {
        std::cout << "char: Non displayable\n";
    }
}

void ScalarConverter::printInt(double value) {
    if (std::isnan(value) || std::isinf(value) ||
        value < std::numeric_limits<int>::min() ||
        value > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible\n";
        return;
    }
    std::cout << "int: " << static_cast<int>(value) << "\n";
}

void ScalarConverter::printFloat(double value) {
    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(value) << "f\n";
}

void ScalarConverter::printDouble(double value) {
    std::cout << "double: " << std::fixed << std::setprecision(1) << value << "\n";
}

std::string intToString(int value) {
    std::stringstream ss;
    ss << value;  // Convert integer to string
    return ss.str();
}

std::string doubleToString(double value) {
    std::stringstream ss;
    ss << value;  // Convert double to string
    return ss.str();
}

void ScalarConverter::convert(const std::string &literal) {
    std::string type = detectType(literal);

    if (type == "char") {
        char c = literal[0]; 
        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << static_cast<float>(c) << ".0f\n";
        std::cout << "double: " << static_cast<double>(c) << ".0\n";
    } 
    else if (type == "int") {
        int i = std::atoi(literal.c_str());
        std::cout << "char: " << (i >= 32 && i <= 126 ? "'" + std::string(1, static_cast<char>(i)) + "'" : "impossible") << "\n";
        std::cout << "int: " << i << "\n";
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f\n";
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << "\n";
    } 
    else if (type == "float") {
        float f = strtof(literal.c_str(), NULL);
        std::cout << "char: " << (f >= 32 && f <= 126 ? "'" + std::string(1, static_cast<char>(f)) + "'" : "impossible") << "\n";
        std::cout << "int: " << (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min() ? "impossible" : intToString(static_cast<int>(f))) << "\n";
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << "\n";
    } 
    else if (type == "double") {
        double d = strtod(literal.c_str(), NULL);
        std::cout << "char: " << (d >= 32 && d <= 126 ? "'" + std::string(1, static_cast<char>(d)) + "'" : "impossible") << "\n";
        std::cout << "int: " << (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min() ? "impossible" : intToString(static_cast<int>(d))) << "\n";
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f\n";
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
    } 
    else if (type == "pseudo-literal") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << literal << "f\n";
        std::cout << "double: " << literal << "\n";
    } 
    else {
        std::cout << "Error: Invalid input\n";
    }
}

