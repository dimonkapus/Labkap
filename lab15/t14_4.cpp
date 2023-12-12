#include <iostream>
#include <fstream>
#include <stack>

bool checkTdTags(const std::string& line) {
    std::stack<char> tagStack;

    for (char ch : line) {
        if (ch == '<') {
            tagStack.push(ch);
        } else if (ch == '>') {
            if (!tagStack.empty() && tagStack.top() == '<') {
                tagStack.pop();
            } else {
                return false;
            }
        }
    }

    return tagStack.empty();
}

int main() {
    std::ifstream inputFile("your_file.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Не вдалося відкрити файл для читання." << std::endl;
        return 1;
    }

    std::string line;
    int lineNumber = 0;

    while (std::getline(inputFile, line)) {
        lineNumber++;
        if (!checkTdTags(line)) {
            std::cout << "Помилка в рядку " << lineNumber << ": неправильна розстановка тегів <td>." << std::endl;
            return 1;
        }
    }

    inputFile.close();

    std::cout << "Розстановка тегів <td> вірна у всіх рядках файлу." << std::endl;

    return 0;
}
