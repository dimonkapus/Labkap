#include <iostream>
#include <list>

template <typename T>
class Polynomial {
private:
    std::list<T> coefficients;

public:
    Polynomial(const std::list<T>& coeffs) : coefficients(coeffs) {}

    void input() {
        T coeff;
        std::cout << "Введіть коефіціенти полінома через пробіл (від найвищого до найнижчого ступенів): ";
        while (std::cin >> coeff) {
            coefficients.push_front(coeff);
        }
    }

    void output() const {
        std::cout << "Поліном: ";
        auto it = coefficients.begin();
        while (it != coefficients.end()) {
            std::cout << *it;
            ++it;
            if (it != coefficients.end()) {
                std::cout << "x^" << std::distance(coefficients.begin(), it);
                std::cout << " + ";
            }
        }
        std::cout << std::endl;
    }

    Polynomial<T> add(const Polynomial<T>& other) const {
        std::list<T> result;
        auto it1 = coefficients.begin();
        auto it2 = other.coefficients.begin();

        while (it1 != coefficients.end() && it2 != other.coefficients.end()) {
            result.push_front(*it1 + *it2);
            ++it1;
            ++it2;
        }

        while (it1 != coefficients.end()) {
            result.push_front(*it1);
            ++it1;
        }

        while (it2 != other.coefficients.end()) {
            result.push_front(*it2);
            ++it2;
        }

        return Polynomial<T>(result);
    }

    Polynomial<T> multiply(const Polynomial<T>& other) const {
        std::list<T> result(coefficients.size() + other.coefficients.size() - 1, 0);

        auto it1 = coefficients.begin();
        for (int i = 0; it1 != coefficients.end(); ++it1, ++i) {
            auto it2 = other.coefficients.begin();
            for (int j = 0; it2 != other.coefficients.end(); ++it2, ++j) {
                result[i + j] += (*it1) * (*it2);
            }
        }

        return Polynomial<T>(result);
    }

    T evaluate(const T& x) const {
        T result = 0;
        auto it = coefficients.begin();

        while (it != coefficients.end()) {
            result *= x;
            result += *it;
            ++it;
        }

        return result;
    }
};

int main() {
    std::list<int> coeffs1 = {1, 2, 3}; // Поліном: 1x^2 + 2x^1 + 3x^0
    Polynomial<int> poly1(coeffs1);

    std::list<int> coeffs2 = {2, -1, 0, 4}; // Поліном: 2x^3 - 1x^2 + 0x^1 + 4x^0
    Polynomial<int> poly2(coeffs2);

    poly1.output();
    poly2.output();

    Polynomial<int> sum = poly1.add(poly2);
    std::cout << "Сума поліномів: ";
    sum.output();

    Polynomial<int> product = poly1.multiply(poly2);
    std::cout << "Добуток поліномів: ";
    product.output();

    int x_value = 2;
    int result = poly1.evaluate(x_value);
    std::cout << "Значення полінома при x = " << x_value << ": " << result << std::endl;

    return 0;
}
