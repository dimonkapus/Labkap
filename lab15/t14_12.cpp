#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

void createAndProcessFile(const std::string& filename, int numLines) {
    std::ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        std::cerr << "Не вдалося відкрити файл для запису." << std::endl;
        return;
    }

    for (int i = 0; i < numLines; ++i) {
        std::string line = "   Line " + std::to_string(i + 1) + "   ";
        outputFile << line << "\n";
    }

    outputFile.close();

    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Не вдалося відкрити файл для читання." << std::endl;
        return;
    }

    std::vector<std::string> lines;

    std::string line;
    while (std::getline(inputFile, line)) {
        line.erase(std::unique(line.begin(), line.end(), [](char a, char b) { return a == ' ' && b == ' '; }), line.end());
        line.erase(line.find_last_not_of(" \t") + 1);

        lines.push_back(line);
    }

    inputFile.close();

    std::ofstream editedFile(filename);

    if (!editedFile.is_open()) {
        std::cerr << "Не вдалося відкрити файл для запису." << std::endl;
        return;
    }

    for (const auto& editedLine : lines) {
        editedFile << editedLine << "\n";
    }

    editedFile.close();
}

int main() {
    createAndProcessFile("example.txt", 5);

    std::cout << "Файл був створений та відредагований." << std::endl;

    return 0;
}
