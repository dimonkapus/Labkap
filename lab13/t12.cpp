#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::cout << "enter string: ";
    std::string input;
    std::getline(std::cin, input);

    bool capitalizeNext = true;
    for (char& c : input) {
        if (std::isalpha(c)) {
            if (capitalizeNext) {
                c = std::toupper(c);
                capitalizeNext = false;
            } else {
                c = std::tolower(c);
            }
        } else {
            capitalizeNext = true;
        }
    }

    std::cout << "result: " << input << std::endl;

    return 0;
}
