//
// Created by zrma on 2019-09-06.
//

#ifndef INC_1D1CPP_SRC_HACKER_RANK_STRUCTS_H_
#define INC_1D1CPP_SRC_HACKER_RANK_STRUCTS_H_

#include <memory>
#include <utility>

struct Student {
  Student(const int &age,
          std::string first_name,
          std::string last_name,
          const int &standard
  ) : age(age), first_name(std::move(first_name)), last_name(std::move(last_name)), standard(standard) {}

  int age = 0;
  std::string first_name;
  std::string last_name;
  int standard = 0;
};

std::shared_ptr<Student> create_structs(
    const int &age,
    const std::string &first_name,
    const std::string &last_name,
    const int &standard
);

#endif //INC_1D1CPP_SRC_HACKER_RANK_STRUCTS_H_
