//
// Created by zrma on 2019-08-28.
//

#ifndef INC_1D1CPP_INTRODUCTION_H
#define INC_1D1CPP_INTRODUCTION_H

#include <array>
#include <vector>
#include <list>
#include <tuple>

void hello_world();

void input_and_output(const std::vector<int> &arr);

void conditional_statements(int n);

void basic_data_types(int n, long l, char c, float f, double d);

void for_loop(int a, int b);

int max_of_four(int a, int b, int c, int d);

void update(int *a, int *b);

void arrays_introduction(std::initializer_list<int> list);

std::vector<int> variables_sized_arrays(
        const std::vector<std::vector<int>> &arr,
        const std::vector<std::tuple<int, int>> &query
);

#endif //INC_1D1C&PP_INTRODUCTION_H
