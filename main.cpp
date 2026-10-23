#include <iostream>
#include <limits>

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    double num1 = 0.0;
    double num2 = 0.0;
    char op = ' ';

    std::cout << "=================================\n";
    std::cout << "      Simple C++ Calculator      \n";
    std::cout << "=================================\n";
    std::cout << "Supported operations: +, -, *, /\n";
    std::cout << "Enter 'q' when prompted for operator to exit.\n\n";

    while (true) {
        // Read first number
        std::cout << "Enter first number: ";
        if (!(std::cin >> num1)) {
            std::cout << "Error: Invalid number. Try again.\n\n";
            clearInputBuffer();
            continue;
        }

        // Read operator
        std::cout << "Enter operator (+, -, *, / or 'q' to quit): ";
        std::cin >> op;

        if (op == 'q' || op == 'Q') {
            std::cout << "\nExiting calculator. Goodbye!\n";
            break;
        }

        if (op != '+' && op != '-' && op != '*' && op != '/') {
            std::cout << "Error: Unsupported operator '" << op << "'.\n\n";
            clearInputBuffer();
            continue;
        }

        // Read second number
        std::cout << "Enter second number: ";
        if (!(std::cin >> num2)) {
            std::cout << "Error: Invalid number. Try again.\n\n";
            clearInputBuffer();
            continue;
        }

        // Calculate and display result
        std::cout << "\nResult: ";
        switch (op) {
            case '+':
                std::cout << num1 << " + " << num2 << " = " << (num1 + num2) << "\n";
                break;
            case '-':
                std::cout << num1 << " - " << num2 << " = " << (num1 - num2) << "\n";
                break;
            case '*':
                std::cout << num1 << " * " << num2 << " = " << (num1 * num2) << "\n";
                break;
            case '/':
                if (num2 == 0.0) {
                    std::cout << "Error: Division by zero is undefined.\n";
                } else {
                    std::cout << num1 << " / " << num2 << " = " << (num1 / num2) << "\n";
                }
                break;
        }
        std::cout << "---------------------------------\n\n";
    }

    return 0;
}
