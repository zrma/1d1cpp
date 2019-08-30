//
// Created by zrma on 2019-08-28.
//

#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <string>
#include "introduction.h"


void hello_world() {
    std::cout << "Hello, World!";
}

void input_and_output(const std::vector<int> &arr) {
    std::cout << std::accumulate(arr.begin(), arr.end(), 0);
}

const auto num_label = std::array{
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};

void conditional_statements(int n) {
    if (n < num_label.size()) {
        std::cout << num_label[n];
        return;
    }
    std::cout << "Greater than 9";
}

void basic_data_types(int n, long l, char c, float f, double d) {
    printf("%d\n%ld\n%c\n%.3f\n%.9lf", n, l, c, f, d);
}

const auto even_odd = std::array{"even", "odd"};

void for_loop(int a, int b) {
    std::vector<decltype(a)> arr(b - a + 1);
    std::iota(arr.begin(), arr.end(), a);

    std::for_each(arr.begin(), arr.end(), [](const int &n) {
        if (n < num_label.size()) {
            std::cout << num_label[n] << std::endl;
            return;
        }
        std::cout << even_odd[n % 2] << std::endl;
    });
}