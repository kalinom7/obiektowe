class Parallelogram{
    private:
    int height;
    int base;
    int side;

    public:
    Parallelogram(int height, int base, int side);
    const int area();
    const int perimeter();
};

class Rectangle : public Parallelogram{
    private:
    public:
    Rectangle(int base, int side);

};

class Square : public Rectangle{
    private:
    public:
    Square(int base);

};