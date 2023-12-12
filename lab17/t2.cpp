#include <iostream>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    void push(const T& value) {
        elements.push_back(value);
    }

    T pop() {
        if (elements.empty()) {
            throw std::out_of_range("Stack is empty");
        }

        T top = elements.back();
        elements.pop_back();
        return top;
    }

    bool isEmpty() const {
        return elements.empty();
    }
};

int inputArray(Stack<int>& stack) {
    int value;
    int count = 0;

    std::cout << "Enter integers (enter 0 to stop):\n";
    do {
        std::cout << "Enter an integer: ";
        std::cin >> value;

        if (value != 0) {
            stack.push(value);
            count++;
        }

    } while (value != 0);

    return count;
}

int main() {
    try {
        Stack<int> customStack;
        int customCount = inputArray(customStack);
        std::cout << "Custom Stack: ";
        while (!customStack.isEmpty()) {
            std::cout << customStack.pop() << " ";
        }
        std::cout << std::endl;
        std::cout << "Number of elements in Custom Stack: " << customCount << std::endl;

        // Using std::stack
        std::stack<int> stdStack;
        int stdCount = inputArray(stdStack);
        std::cout << "std::stack: ";
        while (!stdStack.empty()) {
            std::cout << stdStack.top() << " ";
            stdStack.pop();
        }
        std::cout << std::endl;
        std::cout << "Number of elements in std::stack: " << stdCount << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
