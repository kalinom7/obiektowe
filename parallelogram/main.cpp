#include <iostream>
#include "para.hpp"

/*
Out: 20 18
Out: 36 24
*/

int main() {
Parallelogram *rect = new Rectangle(4, 5);
 std::cout << rect->area() << " " << rect->perimeter() << std::endl;
delete rect;

Rectangle *square = new Square(6);
std::cout << square->area() << " " << square->perimeter() << std::endl;
delete square;
return 0;
}