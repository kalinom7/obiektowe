#include "para.hpp"

Parallelogram::Parallelogram(int base, int side, int height){
    this -> base = base;
    this -> side = side;
    this -> height = height;
}
const int Parallelogram::area(){
    return base*height;
}
const int Parallelogram::perimeter(){
    return 2*base + 2*side;
}

Rectangle::Rectangle(int base, int side) : Parallelogram(base, side, side){};
Square::Square(int base) : Rectangle(base, base){};