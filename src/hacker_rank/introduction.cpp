//
// Created by zrma on 2019-08-28.
//

#include <iostream>
#include <numeric>
#include <array>
#include <string>
#include "introduction.h"


void hello_world() {
    std::cout << "Hello, World!";
}

void input_and_output(const std::vector<int> &arr) {
    std::cout << std::accumulate(arr.begin(), arr.end(), 0);
}

void conditional_statements(const int n) {
    const auto size = 10;
    const auto arr = std::array{
            "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    };

    if (n < size) {
        std::cout << arr[n];
        return;
    }
    std::cout << "Greater than 9";
}