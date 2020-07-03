#include "pch.h"

#include "type_traits.h"
#include <boost/type_index.hpp>

class Test {};

template<class T>
void type_name(T) {
  std::cout << "Short name: " << boost::typeindex::type_id<T>().raw_name() << std::endl;
  std::cout << "Readable name: " << boost::typeindex::type_id<T>().pretty_name() << std::endl << std::endl;
}

void print_type_name() {
  const auto a = 0;
  const auto b = "test";
  const auto c = new Test();
  const auto d = std::make_shared<Test>();

  const auto label = std::array<std::string, 2>{"false", "true"};

  std::cout << "a is shared_ptr: " << label[is_shared_ptr_t(a)] << std::endl;
  type_name(a);

  std::cout << "b is shared_ptr: " << label[is_shared_ptr_t(b)] << std::endl;
  type_name(b);

  std::cout << "c is shared_ptr: " << label[is_shared_ptr_t(c)] << std::endl;
  type_name(c);

  std::cout << "d is shared_ptr: " << label[is_shared_ptr_t(d)] << std::endl;
  type_name(d);
}

void array_and_wstring() {
  auto buf = std::array<wchar_t, 2048>();
  auto str = std::wstring(L"Hello World");
  _snwprintf_s(buf.data(), str.length(), 0, L"%s", str.c_str());

  std::wcout << "data: " << buf.data() << std::endl;
  std::wcout << "size: " << buf.size() << std::endl;
  std::wcout << "size: " << buf.max_size() << std::endl;
}

int main() {
  print_type_name();
  array_and_wstring();
}