#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream inputFile("text.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Не вдалося відкрити файл для читання." << std::endl;
        return 1;
    }

    std::vector<std::string> words;
    std::string word;
    while (inputFile >> word) {
        words.push_back(word);
    }

    inputFile.close();

    for (size_t i = 0; i < words.size() - 2; ++i) {
        if (words[i] == "die" || words[i] == "der" || words[i] == "das") {
            std::transform(words[i + 2].begin(), words[i + 2].end(), words[i + 2].begin(), ::toupper);
        }
    }

    for (const auto& w : words) {
        std::cout << w << " ";
    }
    std::cout << std::endl;

    return 0;
}
