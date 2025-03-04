#include "Functions.hpp"

int main() {
    Base* obj = generate();  // Generate a random object

    std::cout << "Identifying by pointer: ";
    identify(obj);  // 🔹 Calls identify(Base *p)

    std::cout << "Identifying by reference: ";
    identify(*obj);

    delete obj;  
    return 0;
}
