#include "geometric.hpp"
#include <cmath>

Geometric::Geometric(double a0, double q){
    this -> a0 = a0;
    this -> q = q;
};

const double Geometric::operator[](int n){

    return a0 * std::pow(q, n);

};


