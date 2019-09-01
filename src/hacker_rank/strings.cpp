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
  size_t start = 0;

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

std::tuple<std::string, pair_map> parse(std::string str) {
  // 앞 뒤 < > 제거
  str = str.substr(1, str.size() - 2);
  std::string name, key, value, tmp;

  std::stringstream ss;
  ss.str(str);
  ss >> name;

  auto result = pair_map();
  while (ss >> key >> tmp >> value) {
    result[key] = value.substr(1, value.size() - 2);
  }
  return std::make_tuple(name, result);
}

std::string Attribute::Query(std::string q) {
  constexpr auto null_str = "";
  if (q.substr(0, this->m_Name.size()) != this->m_Name) {
    return null_str;
  }

  constexpr auto child_delimiter = '.';
  constexpr auto attrs_delimiter = '~';

  q = q.substr(this->m_Name.size(), q.size() - this->m_Name.size());
  if (q.c_str()[0] == attrs_delimiter) {
    q = q.substr(1, q.size() - 1);
    if (this->m_Attr.find(q) == this->m_Attr.end()) {
      return null_str;
    }
    return this->m_Attr[q];
  }

  const auto get_from_child = [&](auto pos) -> std::string {
    const auto child = q.substr(0, pos);
    if (this->m_Child.find(child) == this->m_Child.end()) {
      return null_str;
    }
    return this->m_Child[child]->Query(q);
  };

  q = q.substr(1);
  auto pos = q.find(child_delimiter);
  if (pos == std::string::npos) {
    pos = q.find(attrs_delimiter);
    if (pos == std::string::npos) {
      return null_str;
    }
  }
  return get_from_child(pos);
}

AttrWeakPtr Attribute::AddChild(const AttrWeakPtr &parent, const std::string &s) {
  const auto&[name, p] = parse(s);
  const auto node = std::make_shared<Attribute>(parent, name, p);
  this->m_Child[name] = node;

  return node;
}

AttrWeakPtr Attribute::GetParent() const {
  return this->m_Parent;
}

void attribute_parser(std::vector<std::string> ss, const std::vector<std::string> &query) {
  if (query.empty()) {
    return;
  }

  const auto top = std::make_shared<Attribute>("header", pair_map());
  std::weak_ptr<Attribute> pick = top;
  std::for_each(ss.begin(), ss.end(), [&](const std::string &s) {
    if (s.empty()) {
      return;
    }
    
    auto spt = pick.lock();
    if (!spt) {
      std::cerr << "pick is expired" << std::endl;
      return;
    }
    
    if (s.c_str()[1] == '/') {
      pick = spt->GetParent();
      return;
    }
    pick = spt->AddChild(spt, s);
  });

  std::for_each(query.begin(), query.end(), [&](const std::string &s) {
    if (s.empty()) {
      return;
    }
    const auto result = top->Query("header." + s);
    if (result.empty()) {
      std::cout << "Not Found!" << std::endl;
      return;
    }
    std::cout << result << std::endl;
  });
}
