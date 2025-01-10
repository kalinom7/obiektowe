#include <iostream>
#include "pred.hpp"
#include <vector>
/*
Wykonanie
Out: 4 5
*/

int count(const std::vector<int> &el, const Predicate &pred) {
  int count = 0;
  for (int i = 0; i < el.size(); ++i) {
    if (pred(el[i])) {
      ++count;
    }
  }
  return count;
}
int main() {
  const std::vector<int> el {-7, 12, -11, 2, 9, -4, -6, 5, 23, -1};
  std::cout << count(el, Even()) << " " << count(el, Negative())
		<< std::endl;
  return 0;
}