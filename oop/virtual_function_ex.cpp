#include <iostream>
#include <vector>

class Shape {
public:
    virtual void draw()
    {
        std::cout << "Drawing a generic shape\n";
    }
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Circle\n";
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Rectangle\n";
    }
};

class Triangle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Triangle\n";
    }
};

int main()
{
    // fyi i would use a vector when i don't know how many shapes i will draw,
    // for now this is just a demo so just use an array

    Circle circle;
    Rectangle rectangle;
    Triangle triangle;

    std::vector<Shape*> shapes { &circle, &rectangle, &triangle };

    for (auto itr = shapes.begin(); itr != shapes.end(); ++itr)
    {
        (*itr)->draw(); // Calls the correct draw() based on actual shape
    }

    return 0;
}
