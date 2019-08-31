//
// Created by zrma on 2019-08-31.
//

#include "strings.h"

std::vector<int> parse_int(const std::string &str) {
    auto result = std::vector<int>();
    const auto delimiter = std::string(",");
    size_t start = 0, pos = 0;
    while ((pos = str.find(delimiter, start)) != std::string::npos) {
        const auto token = str.substr(start, pos - start);
        result.push_back(std::strtol(token.c_str(), nullptr, 10));
        start += token.size() + delimiter.length();
    }
    if (str.size() - start > 0) {
        const auto token = str.substr(start, str.size() - start);
        result.push_back(std::strtol(token.c_str(), nullptr, 10));
    }
    return result;
}
