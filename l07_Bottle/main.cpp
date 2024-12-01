#include <iostream>
#include "bottle.hpp"






int main() {
  Bottle bottle(4.5);
  std::cout << bottle.volume()<<std::endl ;
  std::cout << bottle.fill(3.5)<<std::endl  ;
  std::cout << bottle.volume() <<std::endl ;
  std::cout << bottle.pour(5.5) <<std::endl ;
  std::cout << bottle.volume() << std::endl;

  return 0;
}