#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

std::string decryptWord(const std::string& encryptedWord) {
    std::string decryptedWord = encryptedWord;
    std::reverse(decryptedWord.begin(), decryptedWord.end());
    return decryptedWord;
}

int main() {
    std::ifstream inputFile("encrypted_text.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Не вдалося відкрити файл для читання." << std::endl;
        return 1;
    }

    std::string line;
    std::vector<std::string> words;

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string word;

        while (iss >> word) {
            size_t lastCharIndex = word.find_last_of(",.!?");

            if (lastCharIndex != std::string::npos) {
                words.push_back(word.substr(0, lastCharIndex));
                words.push_back(word.substr(lastCharIndex));
            } else {
                words.push_back(word);
            }
        }
    }
    inputFile.close();
    std::ofstream outputFile("decrypted_text.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Не вдалося відкрити файл для запису." << std::endl;
        return 1;
    }
    for (const auto& word : words) {
        outputFile << decryptWord(word) << " ";
    }
    outputFile.close();
    std::cout << "Розшифрування завершено. Результат записано в decrypted_text.txt." << std::endl;

    return 0;
}
