#include "pred.hpp"

bool Even::operator()(int value) const{
    auto valid = value % 2 == 0;
    return valid;
}
bool Negative::operator()(int value) const{
    auto valid = value < 0;
    return valid; 
}