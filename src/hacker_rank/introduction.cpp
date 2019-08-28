//
// Created by zrma on 2019-08-28.
//

#include <iostream>
#include <numeric>
#include "introduction.h"


void hello_world() {
    std::cout << "Hello, World!";
}

void input_and_output(const std::vector<int> &arr) {
    std::cout << std::accumulate(arr.begin(), arr.end(), 0);
}

