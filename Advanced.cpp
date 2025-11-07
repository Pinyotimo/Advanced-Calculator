#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

double evaluate(const std::string& expression);

int main() {
    std::string input;
    std::cout << "Advanced Calculator (type 'exit' to quit)\n";
    while (true) {
        std::cout << "Enter expression: ";
        std::getline(std::cin, input);
        if (input == "exit") break;
        try {
            double result = evaluate(input);
            std::cout << "Result: " << result << "\n";
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
    return 0;
}

// Simple implementation using std::stringstream
double evaluate(const std::string& expression) {
    std::stringstream ss(expression);
    double num, result;
    char op;

    ss >> result;
    while (ss >> op) {
        ss >> num;
        switch(op) {
            case '+': result += num; break;
            case '-': result -= num; break;
            case '*': result *= num; break;
            case '/': 
                if(num != 0)
                    result /= num;
                else
                    throw std::runtime_error("Division by zero");
                break;
            case '^':
                result = pow(result, num);
                break;
            default:
                throw std::runtime_error("Invalid operator");
        }
    }
    return result;
}

