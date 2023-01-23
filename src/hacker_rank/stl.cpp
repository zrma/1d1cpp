//
// Created by zrma on 2019-09-08.
//

#include "stl.h"
#include <algorithm>
#include <iostream>
#include <set>
#include <tuple>

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

void sets_stl(const std::vector<std::tuple<int, int>> &v) {
    auto s = std::set<int>();
    std::for_each(v.begin(), v.end(), [&s](const std::tuple<int, int> &t) {
        const auto &[op_code, op_land] = t;
        switch (op_code) {
            case 1: {
                s.insert(op_land);
                break;
            }
            case 2: {
                s.erase(op_land);
                break;
            }
            default:
                if (s.find(op_land) == s.end()) {
                    std::cout << "No" << std::endl;
                    return;
                }
                std::cout << "Yes" << std::endl;
        }
    });
}

