//
// Created by zrma on 2019-08-31.
//

#ifndef INC_1D1CPP_STRINGS_H
#define INC_1D1CPP_STRINGS_H

#include <list>
#include <map>
#include <memory>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

std::vector<int> parse_int(const std::string &str);
void strings(const std::string &s1, const std::string &s2);

using pair_map = std::map<std::string, std::string>;
std::tuple<std::string, pair_map> parse_attr(std::string str);
std::tuple<std::string, std::list<std::string>> parse_query(std::string str);

class Attribute;
using AttrPtr = std::shared_ptr<Attribute>;
using AttrWeakPtr = std::weak_ptr<Attribute>;

class Attribute {
 public:
  explicit Attribute(std::string name, pair_map attr)
      : name_(std::move(name)), attr_(std::move(attr)) {}
  explicit Attribute(AttrWeakPtr parent, std::string name, pair_map attr)
      : parent_(std::move(parent)), name_(std::move(name)), attr_(std::move(attr)) {}
  explicit Attribute() = delete;
  ~Attribute() = default;

  [[nodiscard]] std::string Find(const std::string &attr, std::list<std::string> nodes) const;
  AttrWeakPtr AddChild(const AttrWeakPtr &parent, const std::string &s);
  AttrWeakPtr GetParent();

 private:
  std::string name_;
  pair_map attr_;
  std::map<std::string, AttrPtr> child_;
  AttrWeakPtr parent_;
};

void attribute_parser(const std::vector<std::string> &ss, const std::vector<std::string> &query);

#endif //INC_1D1CPP_STRINGS_H
