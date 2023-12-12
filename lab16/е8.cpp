#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

class PolynomialError : public std::runtime_error {
public:
    PolynomialError(const std::string& message) : std::runtime_error(message) {}
};

class Polynomial {
private:
    int degree;
    std::vector<double> coefficients;

public:
    Polynomial() : degree(0), coefficients{0.0} {}

    Polynomial(int deg, const std::vector<double>& coeffs) : degree(deg), coefficients(coeffs) {
        if (degree < 0) {
            throw PolynomialError("Degree must be a non-negative integer.");
        }
        if (coefficients.size() != static_cast<size_t>(degree + 1)) {
            throw PolynomialError("Number of coefficients must match the degree.");
        }
    }

    void inputFromConsole() {
        std::cout << "Enter the degree of the polynomial: ";
        std::cin >> degree;

        if (degree < 0) {
            throw PolynomialError("Degree must be a non-negative integer.");
        }

        coefficients.resize(degree + 1);

        std::cout << "Enter coefficients in decreasing order of degree:\n";
        for (int i = degree; i >= 0; --i) {
            std::cout << "Coefficient for x^" << i << ": ";
            std::cin >> coefficients[i];
        }
    }

    void inputFromString(const std::string& polyStr) {
        std::istringstream iss(polyStr);
        iss >> degree;

        if (degree < 0) {
            throw PolynomialError("Degree must be a non-negative integer.");
        }

        coefficients.resize(degree + 1);

        for (int i = degree; i >= 0; --i) {
            iss >> coefficients[i];
        }

        if (iss.fail()) {
            throw PolynomialError("Invalid polynomial string format.");
        }
    }

    void output() const {
        std::cout << "Polynomial: ";
        for (int i = degree; i >= 0; --i) {
            std::cout << coefficients[i];
            if (i > 0) {
                std::cout << "x^" << i << " + ";
            }
        }
        std::cout << std::endl;
    }

    double evaluate(double x) const {
        double result = 0.0;
        for (int i = degree; i >= 0; --i) {
            result += coefficients[i] * std::pow(x, i);
        }
        return result;
    }

    Polynomial derivative() const {
        if (degree == 0) {
            return Polynomial();
        }

        std::vector<double> derivCoeffs(degree);
        for (int i = degree; i >= 1; --i) {
            derivCoeffs[i - 1] = i * coefficients[i];
        }

        return Polynomial(degree - 1, derivCoeffs);
    }

    Polynomial operator+(const Polynomial& other) const {
        int maxDegree = std::max(degree, other.degree);
        std::vector<double> sumCoeffs(maxDegree + 1, 0.0);

        for (int i = 0; i <= maxDegree; ++i) {
            if (i <= degree) {
                sumCoeffs[i] += coefficients[i];
            }
            if (i <= other.degree) {
                sumCoeffs[i] += other.coefficients[i];
            }
        }

        return Polynomial(maxDegree, sumCoeffs);
    }

    Polynomial operator-(const Polynomial& other) const {
        int maxDegree = std::max(degree, other.degree);
        std::vector<double> diffCoeffs(maxDegree + 1, 0.0);

        for (int i = 0; i <= maxDegree; ++i) {
            if (i <= degree) {
                diffCoeffs[i] += coefficients[i];
            }
            if (i <= other.degree) {
                diffCoeffs[i] -= other.coefficients[i];
            }
        }

        return Polynomial(maxDegree, diffCoeffs);
    }

    Polynomial operator*(const Polynomial& other) const {
        int prodDegree = degree + other.degree;
        std::vector<double> prodCoeffs(prodDegree + 1, 0.0);

        for (int i = 0; i <= degree; ++i) {
            for (int j = 0; j <= other.degree; ++j) {
                prodCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        return Polynomial(prodDegree, prodCoeffs);
    }
};

int main() {
    try {
        Polynomial p1, p2, p3;

        std::cout << "Enter the first polynomial:\n";
        p1.inputFromConsole();

        std::cout << "Enter the second polynomial (as a string):\n";
        std::string polyStr;
        std::cin.ignore();  // Ignore newline character left in the buffer
        std::getline(std::cin, polyStr);
        p2.inputFromString(polyStr);

        std::cout << "\nFirst polynomial:\n";
        p1.output();

        std::cout << "\nSecond polynomial:\n";
        p2.output();

        std::cout << "\nSum of polynomials:\n";
        p3 = p1 + p2;
        p3.output();

        std::cout << "\nDifference of polynomials:\n";
        p3 = p1 - p2;
        p3.output();

        std::cout << "\nProduct of polynomials:\n";
        p3 = p1 * p2;
        p3.output();

        std::cout << "\nEvaluate the first polynomial at x = 2: " << p1.evaluate(2.0) << std::endl;
        std::cout << "Evaluate the second polynomial at x = 3: " << p2.evaluate(3.0) << std::endl;

        std::cout << "\nDerivative of the first polynomial:\n";
        Polynomial p4 = p1.derivative();
        p4.output();

    } catch (const PolynomialError& e) {
        std::cerr << "Polynomial Error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
