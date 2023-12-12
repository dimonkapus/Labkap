#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cout << "Введіть масив цілих чисел через пробіл: ";
    std::vector<int> numbers;
    int num;
    while (std::cin >> num) {
        numbers.push_back(num);
    }

    std::vector<int> L = numbers;
    std::cout << "Елементи списку L у вихідному порядку: ";
    for (int element : L) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::cout << "Елементи списку L у оберненому порядку: ";
    for (auto it = L.rbegin(); it != L.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::sort(L.begin(), L.end());
    std::reverse(L.begin(), L.end());
    std::cout << "Елементи списку L відсортовані за зростанням, але виведені у порядку спадання: ";
    for (int element : L) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
