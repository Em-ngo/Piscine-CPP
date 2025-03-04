#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 50);
        Bureaucrat bob("Bob", 150);

        Form form1("form_1", 100, 50);
        Form form2("form_2", 40, 20);

        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;

        std::cout << "\n";

        alice.signForm(form1);  // Alice can sign
        bob.signForm(form1);    // Bob cannot sign
        alice.signForm(form2);  // Alice cannot sign (grade too low)

        std::cout << "\n";

        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}