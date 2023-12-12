#include <iostream>
#include <vector>
#include <string>

template <typename T>
T sum(T* x, size_t n) {
    T result = T();

    for (size_t i = 0; i < n; ++i) {
        result += x[i];
    }

    return result;
}

template <typename T>
T sum(T** x, size_t n) {
    std::vector<T> result;

    for (size_t i = 0; i < n; ++i) {
        if (x[i] != nullptr) {
            for (size_t j = 0; x[i][j] != '\0'; ++j) {
                result.push_back(x[i][j]);
            }
        }
    }

    return result;
}

int main() {
    int v1[] = {1, 2, 3};
    double v2[] = {1.0, 2.0, 3.0};
    std::string v3[] = {"a", "bc", "def"};
    char v4[] = {'a', 'b', 'c'};
    int* v5[] = {{1, 4}, {2}, {3}};

    int result1 = sum(v1, 3);
    double result2 = sum(v2, 3);
    std::string result3 = sum(v3, 3);
    std::string result4 = sum(v4, 3);
    std::vector<int> result5 = sum(v5, 3);

    std::cout << "Result 1: " << result1 << std::endl;
    std::cout << "Result 2: " << result2 << std::endl;
    std::cout << "Result 3: " << result3 << std::endl;
    std::cout << "Result 4: " << result4 << std::endl;
    std::cout << "Result 5: {";
    for (size_t i = 0; i < result5.size(); ++i) {
        std::cout << result5[i] << " ";
    }
    std::cout << "}" << std::endl;

    return 0;
}
