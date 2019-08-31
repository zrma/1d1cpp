//
// Created by zrma on 2019-08-31.
//

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
