//
// Created by zrma on 2019-09-08.
//

#include "stl.h"
#include <algorithm>

void sort(std::vector<int> &v) {
  std::sort(v.begin(), v.end());
}

void erase(std::vector<int> &v, int pos, int from, int to) {
  v.erase(v.begin() + pos - 1);
  v.erase(v.begin() + from - 1, v.begin() + to - 1);
}

