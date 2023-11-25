#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.141592653589793;

class Shape
{
public:
    virtual double calculateArea() const = 0;
    virtual void print() const
    {
        cout << "This is a generic shape." << endl;
    }
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double getLength() const { return length; }
    double getWidth() const { return width; }

    double calculateArea() const override
    {
        cout << "Calculating the area of a rectangle." << endl;
        return length * width;
    }

    void print() const override
    {
        cout << "This is a rectangle with length " << length << " and width " << width << "." << endl;
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculateArea() const override
    {
        cout << "Calculating the area of a circle." << endl;
        return PI * radius * radius;
    }

    void print() const override
    {
        cout << "This is a circle with radius " << radius << "." << endl;
    }
};

class Square : public Rectangle
{
public:
    Square(double side) : Rectangle(side, side) {}

    void print() const override
    {
        cout << "This is a square with side " << getLength() << "." << endl;  
    }
};

class Solid
{
public:
    virtual double calculateVolume() const = 0;
    virtual double calculateSurfaceArea() const = 0;
    virtual void print() const
    {
        cout << "This is a generic solid." << endl;
    }
};

class Sphere : public Solid
{
private:
    double radius;

public:
    Sphere(double r) : radius(r) {}

    double calculateVolume() const override
    {
        cout << "Calculating the volume of a sphere." << endl;
        return (4.0 / 3.0) * PI * pow(radius, 3);
    }

    double calculateSurfaceArea() const override
    {
        cout << "Calculating the surface area of a sphere." << endl;
        return 4 * PI * pow(radius, 2);
    }

    void print() const override
    {
        cout << "This is a sphere with radius " << radius << "." << endl;
    }
};

class Cube : public Solid
{
private:
    double side;

public:
    Cube(double s) : side(s) {}

    double calculateVolume() const override
    {
        cout << "Calculating the volume of a cube." << endl;
        return pow(side, 3);
    }

    double calculateSurfaceArea() const override
    {
        cout << "Calculating the surface area of a cube." << endl;
        return 6 * pow(side, 2);
    }

    void print() const override
    {
        cout << "This is a cube with side " << side << "." << endl;
    }
};

class Cone : public Solid
{
private:
    double radius;
    double height;

public:
    Cone(double r, double h) : radius(r), height(h) {}

    double calculateVolume() const override
    {
        cout << "Calculating the volume of a cone." << endl;
        return (1.0 / 3.0) * PI * pow(radius, 2) * height;
    }

    double calculateSurfaceArea() const override
    {
        cout << "Calculating the surface area of a cone." << endl;
        double slantHeight = sqrt(pow(radius, 2) + pow(height, 2));
        return PI * radius * (radius + slantHeight);
    }

    void print() const override
    {
        cout << "This is a cone with radius " << radius << " and height " << height << "." << endl;
    }
};

int main()
{
    Rectangle rectangle(5.0, 3.0);
    Circle circle(4.0);
    Square square(6.0);

    cout << "Rectangle Area: " << rectangle.calculateArea() << endl;
    rectangle.print();

    cout << "Circle Area: " << circle.calculateArea() << endl;
    circle.print();

    cout << "Square Area: " << square.calculateArea() << endl;
    square.print();

    Sphere sphere(3.0);
    Cube cube(4.0);
    Cone cone(2.0, 5.0);

    cout << "Sphere Volume: " << sphere.calculateVolume() << endl;
    cout << "Sphere Surface Area: " << sphere.calculateSurfaceArea() << endl;
    sphere.print();

    cout << "Cube Volume: " << cube.calculateVolume() << endl;
    cout << "Cube Surface Area: " << cube.calculateSurfaceArea() << endl;
    cube.print();  

    cout << "Cone Volume: " << cone.calculateVolume() << endl;
    cout << "Cone Surface Area: " << cone.calculateSurfaceArea() << endl;
    cone.print();

    return 0;
}