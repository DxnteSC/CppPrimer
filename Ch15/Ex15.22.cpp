// (b): geometric primitives

class Shape
{
public:
    virtual double getArea() const = 0;
    virtual int getSides() const = 0;
    virtual double getPerimeter() const = 0;
    virtual double getLength() const = 0;
    virtual double getWidth() const = 0;
    virtual ~Shape();
};

class Shape2D : public Shape
{
};

class Shape3D : public Shape
{
    virtual double getVolume() const = 0;
    virtual double getHeight() const = 0;
};

class Circle : public Shape2D
{
};

class Square : public Shape2D
{
};

class Triangle : public Shape2D
{
};

class Cube : public Shape3D
{
};

class Sphere : public Shape3D
{
};

class Pyramid : public Shape3D
{
};
