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
  ) : age(age), first_name(std::move(first_name)), last_name(std::move(last_name)), standard(standard) {}
  StudentClass() = default;

  void set_age(const int &n) {
    this->age = n;
  }
  void set_standard(const int &n) {
    this->standard = n;
  }
  void set_first_name(const std::string &s) {
    this->first_name = s;
  }
  void set_last_name(const std::string &s) {
    this->last_name = s;
  }

  [[nodiscard]] auto get_age() const {
    return this->age;
  }
  [[nodiscard]] auto get_standard() const {
    return this->standard;
  }
  [[nodiscard]] auto get_first_name() const {
    return this->first_name;
  }
  [[nodiscard]] auto get_last_name() const {
    return this->last_name;
  }
  [[nodiscard]] auto to_string() const {
    std::stringstream result;
    result << this->age << "," << this->first_name << "," << this->last_name << "," << this->standard;
    return result.str();
  }

 private:
  int age = 0;
  std::string first_name;
  std::string last_name;
  int standard = 0;
};

std::shared_ptr<StudentClass> create_classes(
    const int &age,
    const std::string &first_name,
    const std::string &last_name,
    const int &standard
);

#endif //INC_1D1CPP_SRC_HACKER_RANK_STRUCTS_H_
