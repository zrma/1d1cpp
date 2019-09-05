//
// Created by zrma on 2019-09-06.
//

#include "structs.h"

std::shared_ptr<Student> create_structs(
    const int &age,
    const std::string &first_name,
    const std::string &last_name,
    const int &standard
) {
  return std::make_shared<Student>(age, first_name, last_name, standard);
}

