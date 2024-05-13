#include <iostream>
#include <regex>
#include <string>

int main(){
    double answer;
    std::string continueToken = "";

    while (true){
        double a, b;
        std::string operation = "";
        std::regex operationRe("^(\\s*[+\\-*/%]|a|abs)$");
        std::regex valueRe("^[0-9]+$");

        if (std::regex_match(continueToken, valueRe)){
            a = std::stod(continueToken);
        }
        else if (std::regex_match(continueToken, operationRe)) {
            a = answer;
            operation = continueToken;
        } else if (continueToken != "") {

        }

        if (continueToken == "") {
            std::cout << "enter value a\n";
            while (!(std::cin >> a)) {
                std::cout << "invalid value, enter number\n";
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
            }
        }

        if (operation == "") {
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
        }

        if (operation != "abs" && operation != "a") {
            std::cout << "enter value b\n";
            while (!(std::cin >> b)) {
                std::cout << "invalid value, enter number\n";
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
            }
        }

        switch (operation[0]) {
        case '+':
            answer = a + b;
            break;
        case '-':
            answer = a - b;
            break;
        case '/':
            if (b == 0) { 
                std::cout << "can't divide by zero\n";
                answer = 0;
            }
            else { 
                answer = a / b;
            }
                break;
        case '*':
            answer = a * b;
            break;
        case '%':
            if (b == 0) {
                std::cout << "can't divide by zero\n";
                answer = 0;
            } 
            else{
                answer = fmod(a, b);
            }
            break;
        case 'a':
            answer = abs(a);
            break;
        default:
            answer = 0;
            std::cout << "wrong data\n";
        }

        std::cout << "answer is " << answer << '\n';

        std::cout << "To continue write operation or value, other to stop\n";
        std::cin >> continueToken;
    }

    return 0;
}
