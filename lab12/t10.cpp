#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Не вдалося відкрити файл для читання." << std::endl;
        return 1;
    }

    std::vector<int> numbers;
    int number;
    while (inputFile >> number) {
        if (number >= 0) {
            numbers.push_back(number);
        }
    }

    inputFile.close();

    std::ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Не вдалося відкрити файл для запису." << std::endl;
        return 1;
    }

    for (size_t i = 0; i < numbers.size(); ++i) {
        outputFile << numbers[i];
        if (i < numbers.size() - 1) {
            outputFile << ' ';
        }
    }

    outputFile.close();

    std::cout << "Операції виконано успішно." << std::endl;

    return 0;
}
