//
// Created by zrma on 2019-08-28.
//

#include <algorithm>
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

int max_of_four(int a, int b, int c, int d) {
    return std::max({a, b, c, d});
}

void update(int *a, int *b) {
    auto temp_a = *a;
    auto temp_b = *b;

    *a = temp_a + temp_b;
    *b = std::abs(temp_a - temp_b);
}

void arrays_introduction(std::initializer_list<int> list) {
    std::vector<int> vec{list};
    std::for_each(vec.rbegin(), vec.rend(), [](const int &n) {
        std::cout << n << " ";
    });
}

std::vector<int> variables_sized_arrays(
        const std::vector<std::vector<int>> &arr,
        const std::vector<std::tuple<int, int>> &query
) {
    auto result = std::vector<int>();
    std::for_each(query.begin(), query.end(), [&](const std::tuple<int, int> &q) {
        const auto[idx1, idx2] = q;
        result.push_back(arr[idx1][idx2]);
    });
    return result;
}

