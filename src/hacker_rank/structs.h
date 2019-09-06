//
// Created by zrma on 2019-09-06.
//

#ifndef INC_1D1CPP_SRC_HACKER_RANK_STRUCTS_H_
#define INC_1D1CPP_SRC_HACKER_RANK_STRUCTS_H_

#include <memory>
#include <utility>
#include <sstream>

struct StudentStruct {
  StudentStruct(const int &age,
                std::string first_name,
                std::string last_name,
                const int &standard
  ) : age(age), first_name(std::move(first_name)), last_name(std::move(last_name)), standard(standard) {}

  int age = 0;
  std::string first_name;
  std::string last_name;
  int standard = 0;
};

std::shared_ptr<StudentStruct> create_structs(
    const int &age,
    const std::string &first_name,
    const std::string &last_name,
    const int &standard
);

class StudentClass {
 public:
  StudentClass(const int &age,
               std::string first_name,
               std::string last_name,
               const int &standard
  ) : age_(age), first_name_(std::move(first_name)), last_name_(std::move(last_name)), standard_(standard) {}
  StudentClass() = default;

  void set_age(const int &n) {
    this->age_ = n;
  }
  void set_standard(const int &n) {
    this->standard_ = n;
  }
  void set_first_name(const std::string &s) {
    this->first_name_ = s;
  }
  void set_last_name(const std::string &s) {
    this->last_name_ = s;
  }

  [[nodiscard]] auto get_age() const {
    return this->age_;
  }
  [[nodiscard]] auto get_standard() const {
    return this->standard_;
  }
  [[nodiscard]] auto get_first_name() const {
    return this->first_name_;
  }
  [[nodiscard]] auto get_last_name() const {
    return this->last_name_;
  }
  [[nodiscard]] auto to_string() const {
    std::stringstream result;
    result << this->age_ << "," << this->first_name_ << "," << this->last_name_ << "," << this->standard_;
    return result.str();
  }

 private:
  int age_ = 0;
  std::string first_name_;
  std::string last_name_;
  int standard_ = 0;
};

std::shared_ptr<StudentClass> create_classes(
    const int &age,
    const std::string &first_name,
    const std::string &last_name,
    const int &standard
);

#endif //INC_1D1CPP_SRC_HACKER_RANK_STRUCTS_H_
