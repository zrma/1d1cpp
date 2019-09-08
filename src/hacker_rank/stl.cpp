//
// Created by zrma on 2019-09-08.
//

#include "stl.h"
#include <algorithm>
#include <iostream>

void sort(std::vector<int> &v) {
  std::sort(v.begin(), v.end());
}

void erase(std::vector<int> &v, int pos, int from, int to) {
  v.erase(v.begin() + pos - 1);
  v.erase(v.begin() + from - 1, v.begin() + to - 1);
}

void lower_bound_stl(const std::vector<int> &v, int num) {
  auto low = std::lower_bound(v.begin(), v.end(), num);
  const auto low_idx = (low - v.begin());

  if (v.at(low_idx) == num) {
    std::cout << "Yes " << low_idx + 1 << std::endl;
    return;
  }
  std::cout << "No " << low_idx + 1 << std::endl;
}

