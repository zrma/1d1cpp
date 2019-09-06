//
// Created by zrma on 2019-09-06.
//

#include "structs.h"

std::shared_ptr<StudentStruct> create_structs(
    const int &age,
    const std::string &first_name,
    const std::string &last_name,
    const int &standard
) {
  return std::make_shared<StudentStruct>(age, first_name, last_name, standard);
}

std::shared_ptr<StudentClass> create_classes(
    const int &age,
    const std::string &first_name,
    const std::string &last_name,
    const int &standard) {
  const auto s = std::make_shared<StudentClass>();
  s->set_age(age);
  s->set_standard(standard);
  s->set_first_name(first_name);
  s->set_last_name(last_name);
  return s;
}

