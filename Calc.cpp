#include <iostream>
#include <regex>

int main(){
    while (true){
        double a, b;
        std::string operation;
        std::regex operationRe("^\\s*[+\\-*/%]$");

        std::cout << "enter value a\n";
        while (!(std::cin >> a)) {
            std::cout << "invalid value, enter number\n";
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }

        std::cout << "enter operation\n";
        while (true) {
            if (!(std::cin >> operation)) {
                std::cout << "invalid value, enter operation\n";
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
            }
            else {
                if (!std::regex_match(operation, operationRe)) {
                    std::cout << "invalid value, enter operation\n";
                    std::cin.clear();
                    std::cin.ignore(INT_MAX, '\n');
                }
                else {
                    break;
                }
            }
        }

        std::cout << "enter value b\n";
        while (!(std::cin >> b)) {
            std::cout << "invalid value, enter number\n";
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }

        switch (operation[0]) {
        case '+':
            std::cout << "answer " << a + b << '\n';
            break;
        case '-':
            std::cout << "answer " << a - b << '\n';
            break;
        case '/':
            if (b < 0) { 
                std::cout << "answer " << "can't divide by zero\n";
            }
            else { 
                std::cout << "answer " << a / b << '\n';
            }
                break;
        case '*':
            std::cout << "answer " << a * b << '\n';
            break;
        case '%':
            if (b < 0) {
                std::cout << "answer " << "can't divide by zero\n";
            } 
            else{
                std::cout << "answer " << fmod(a, b) << '\n';
            }
            break;
        default:
            std::cout << "wrong data\n";
        }

        std::cout << "To continue write +\n";
        char continueToken;

        std::cin >> continueToken;
        if (continueToken != '+') {
            break;
        }
    }
}
