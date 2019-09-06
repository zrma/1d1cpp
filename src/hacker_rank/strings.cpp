//
// Created by zrma on 2019-08-31.
//

#include <algorithm>
#include <iostream>
#include <sstream>
#include "strings.h"

std::vector<int> parse_int(const std::string &str) {
  auto result = std::vector<int>();
  constexpr auto delimiter = ',';
  constexpr auto delimiter_length = sizeof(delimiter);
  auto start = 0;

  while (start < str.size()) {
    const auto pos = std::min(str.find(delimiter, start), str.size());
    const auto token = str.substr(start, pos - start);
    result.push_back(std::strtol(token.c_str(), nullptr, 10));
    start += token.size() + delimiter_length;
  }
  return result;
}

void strings(const std::string &s1, const std::string &s2) {
  std::cout << s1.size() << " " << s2.size() << std::endl;

  std::cout << s1 << s2 << std::endl;
  std::cout << s2.c_str()[0] << s1.substr(1, s1.size() - 1) << " "
            << s1.c_str()[0] << s2.substr(1, s2.size() - 1) << std::endl;
}

std::tuple<std::string, pair_map> parse_attr(std::string str) {
  // remove < >
  str = str.substr(1, str.size() - 2);
  std::string name, key, value, tmp;

  std::stringstream ss;
  ss.str(str);
  ss >> name;

  auto result = pair_map();
  while (ss >> key >> tmp >> value) {
    // remove " "
    result[key] = value.substr(1, value.size() - 2);
  }
  return std::make_tuple(name, result);
}

std::tuple<std::string, std::list<std::string>> parse_query(std::string str) {
  constexpr auto nil = "";
  constexpr auto child_delimiter = '.';
  constexpr auto attrs_delimiter = '~';
  auto result = std::list<std::string>();

  auto pos = str.find(attrs_delimiter);
  if (pos == std::string::npos) {
    return std::tuple(nil, result);
  }

  const auto name = str.substr(pos + 1, str.size() - pos);
  str = str.substr(0, pos);

  while ((pos = str.find(child_delimiter)) != std::string::npos) {
    const auto token = str.substr(0, pos);
    result.push_back(token);
    str = str.substr(pos + 1, str.size() - pos);
  }
  if (!str.empty()) {
    result.push_back(str);
  }
  return std::tuple(name, result);
}

std::string Attribute::Find(const std::string &attr, std::list<std::string> nodes) const {
  constexpr auto nil = "";
  if (nodes.empty()) {
    return nil;
  }

  if (*nodes.begin() != this->name_) {
    return nil;
  }

  nodes.pop_front();
  if (!nodes.empty()) {
    const std::string child = *nodes.begin();
    if (this->child_.find(child) == this->child_.end()) {
      return nil;
    }
    return this->child_.at(child)->Find(attr, nodes);
  }

  if (this->attr_.find(attr) == this->attr_.end()) {
    return nil;
  }
  return this->attr_.at(attr);
}

AttrWeakPtr Attribute::AddChild(const AttrWeakPtr &parent, const std::string &s) {
  const auto&[name, attr] = parse_attr(s);
  const auto node = std::make_shared<Attribute>(parent, name, attr);
  this->child_[name] = node;
  return node;
}

AttrWeakPtr Attribute::GetParent() {
  return this->parent_;
}

void attribute_parser(const std::vector<std::string> &ss, const std::vector<std::string> &query) {
  if (query.empty()) {
    return;
  }

  const auto top = std::make_shared<Attribute>("header", pair_map());
  AttrWeakPtr pick = top;
  std::for_each(ss.begin(), ss.end(), [&pick](const std::string &s) {
    if (s.empty()) {
      return;
    }

    auto spt = pick.lock();
    if (!spt) {
      std::cerr << "pick is expired" << std::endl;
      return;
    }

    // close entry: </tag####>
    if (s.c_str()[1] == '/') {
      pick = spt->GetParent();
      return;
    }
    // open entry: <tag#### key1 = value1 key2 = value2 ... = ...>
    pick = spt->AddChild(spt, s);
  });

  std::for_each(query.begin(), query.end(), [top](const std::string &s) {
    if (s.empty()) {
      return;
    }
    const auto&[attr, nodes] = parse_query("header." + s);
    const auto result = top->Find(attr, nodes);
    if (result.empty()) {
      std::cout << "Not Found!" << std::endl;
      return;
    }
    std::cout << result << std::endl;
  });
}
