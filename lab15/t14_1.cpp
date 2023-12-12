#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

double calculateExpression(const std::vector<double>& numbers, const std::vector<char>& operators) {
    double result = numbers[0];

    for (size_t i = 0; i < operators.size(); ++i) {
        if (operators[i] == '+') {
            result += numbers[i + 1];
        } else if (operators[i] == '-') {
            result -= numbers[i + 1];
        }
    }

    return result;
}

int main() {
    std::ifstream inputFile("expression.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Не вдалося відкрити файл для читання." << std::endl;
        return 1;
    }

    std::string expression;
    std::getline(inputFile, expression);

    inputFile.close();

    std::vector<double> numbers;
    std::vector<char> operators;

    std::istringstream iss(expression);
    double number;
    char op;

    while (iss >> number) {
        numbers.push_back(number);

        if (iss >> op) {
            operators.push_back(op);
        }
    }

    double result = calculateExpression(numbers, operators);
    std::cout << "Значення виразу: " << result << std::endl;

    return 0;
}
