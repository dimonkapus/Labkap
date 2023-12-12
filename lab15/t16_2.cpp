#include <iostream>
#include <cmath>

class Point {
protected:
    double x, y;

public:
    Point() : x(0), y(0) {}

    virtual void input() {
        std::cout << "Enter x-coordinate: ";
        std::cin >> x;
        std::cout << "Enter y-coordinate: ";
        std::cin >> y;
    }

    virtual void output() const {
        std::cout << "(" << x << ", " << y << ")";
    }
};

class Point3D : public Point {
protected:
    double z;

public:
    Point3D() : z(0) {}

    void input() override {
        Point::input();
        std::cout << "Enter z-coordinate: ";
        std::cin >> z;
    }

    void output() const override {
        Point::output();
        std::cout << ", " << z;
    }
};

class Segment {
private:
    Point start;
    Point end;

public:
    Segment() {}

    void input() {
        std::cout << "Enter start point:\n";
        start.input();
        std::cout << "Enter end point:\n";
        end.input();
    }

    void output() const {
        std::cout << "Segment from ";
        start.output();
        std::cout << " to ";
        end.output();
    }

    double length() const {
        double dx = end.x - start.x;
        double dy = end.y - start.y;
        return std::sqrt(dx * dx + dy * dy);
    }
};

class Segment3D {
private:
    Point3D start;
    Point3D end;

public:
    Segment3D() {}

    void input() {
        std::cout << "Enter start point:\n";
        start.input();
        std::cout << "Enter end point:\n";
        end.input();
    }

    void output() const {
        std::cout << "Segment from ";
        start.output();
        std::cout << " to ";
        end.output();
    }

    double length() const {
        double dx = end.x - start.x;
        double dy = end.y - start.y;
        double dz = end.z - start.z;
        return std::sqrt(dx * dx + dy * dy + dz * dz);
    }
};

int main() {
    Point p1;
    Point3D p3d1;
    Segment s1;
    Segment3D s3d;

    std::cout << "Enter 2D point:\n";
    p1.input();

    std::cout << "Enter 3D point:\n";
    p3d1.input();

    std::cout << "Enter 2D segment:\n";
    s1.input();

    std::cout << "Enter 3D segment:\n";
    s3d.input();

    std::cout << "\n2D Point:\n";
    p1.output();

    std::cout << "\n3D Point:\n";
    p3d1.output();

    std::cout << "\n2D Segment:\n";
    s1.output();
    std::cout << "\nLength: " << s1.length() << "\n";

    std::cout << "\n3D Segment:\n";
    s3d.output();
    std::cout << "\nLength: " << s3d.length() << "\n";

    return 0;
}
