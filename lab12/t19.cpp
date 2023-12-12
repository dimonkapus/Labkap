#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

struct Point {
    int x, y, z;
};

double distance(const Point& p1, const Point& p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2) + std::pow(p2.z - p1.z, 2));
}

int main() {
    std::ifstream inputFile("coordinates.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Не вдалося відкрити файл для читання." << std::endl;
        return 1;
    }

    std::vector<Point> points;
    int x, y, z;
    char comma;
    while (inputFile >> x >> comma >> y >> comma >> z) {
        points.push_back({x, y, z});
    }

    inputFile.close();

    double maxDistance = 0;
    Point startPoint, endPoint;

    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            double currentDistance = distance(points[i], points[j]);
            if (currentDistance > maxDistance) {
                maxDistance = currentDistance;
                startPoint = points[i];
                endPoint = points[j];
            }
        }
    }

    std::cout << "Найдовший відрізок між точками (" << startPoint.x << ", " << startPoint.y << ", " << startPoint.z
              << ") та (" << endPoint.x << ", " << endPoint.y << ", " << endPoint.z << ") з відстанню " << maxDistance << std::endl;

    return 0;
}
