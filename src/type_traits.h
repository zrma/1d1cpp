#ifndef CLION_PRACTICE_TYPE_TRAIT_H
#define CLION_PRACTICE_TYPE_TRAIT_H

#include <type_traits>
#include <memory>

#include <boost/mpl/bool.hpp>

template<typename T>
struct is_shared_ptr : boost::mpl::false_ {
};

template<typename T>
struct is_shared_ptr<std::shared_ptr<T> > : boost::mpl::true_ {
};

template<typename T>
constexpr auto is_shared_ptr_t(T) {
    return is_shared_ptr<T>::value;
}

#endif //CLION_PRACTICE_TYPE_TRAIT_H
