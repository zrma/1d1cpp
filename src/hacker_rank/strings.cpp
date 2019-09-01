//
// Created by zrma on 2019-08-31.
//

#include <iostream>
#include "strings.h"

std::vector<int> parse_int(const std::string &str) {
    auto result = std::vector<int>();
    const std::string delimiter(",");
    size_t start = 0;

    while (start < str.size()) {
        const auto pos = std::min(str.find(delimiter, start), str.size());
        const auto token = str.substr(start, pos - start);
        result.push_back(std::strtol(token.c_str(), nullptr, 10));
        start += token.size() + delimiter.length();
    }
    return result;
}

void strings(const std::string &s1, const std::string &s2) {
    std::cout << s1.size() << " " << s2.size() << std::endl;

    std::cout << s1 << s2 << std::endl;
    std::cout << s2.c_str()[0] << s1.substr(1, s1.size() - 1) << " "
              << s1.c_str()[0] << s2.substr(1, s2.size() - 1) << std::endl;
}
