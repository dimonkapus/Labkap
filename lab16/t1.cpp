#include <iostream>
#include <fstream>
#include <stdexcept>

class Rational {
private:
    int numerator;
    int denominator;

public:
    Rational() : numerator(0), denominator(1) {}

    Rational(int num, int den) : numerator(num), denominator(den) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        reduce();
    }

    void reduce() {
        int common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;
    }

    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    Rational operator-(const Rational& other) const {
        return Rational(numerator * other.denominator - other.numerator * denominator,
                        denominator * other.denominator);
    }

    Rational operator/(const Rational& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Cannot divide by zero.");
        }
        return Rational(numerator * other.denominator, denominator * other.numerator);
    }

    friend std::ostream& operator<<(std::ostream& os, const Rational& rational) {
        os << rational.numerator << '/' << rational.denominator;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Rational& rational) {
        std::cout << "Enter numerator: ";
        is >> rational.numerator;
        std::cout << "Enter denominator: ";
        is >> rational.denominator;

        if (rational.denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }

        rational.reduce();
        return is;
    }
};

void writeRationalToFile(const Rational& rational, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error opening file for writing.");
    }

    file << rational;
    file.close();
}

int main() {
    try {
        Rational r1, r2;
        std::cin >> r1 >> r2;

        Rational result = r1 - r2;
        std::cout << "Subtraction Result: " << result << std::endl;

        result = r1 / r2;
        std::cout << "Division Result: " << result << std::endl;

        writeRationalToFile(result, "result.txt");
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
