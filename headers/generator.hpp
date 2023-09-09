#ifndef _GENERATOR_HPP_
#define _GENERATOR_HPP_

#include <random>
#include <stdexcept>

#include "traits.hpp"

namespace gen {

template <typename T>
bool checkRange(const T& min, const T& max) {
  return min <= max;
}

template <typename T>
constexpr bool is_int_type_v =
    traits::is_any_of_v<T, short, int, long, long long, unsigned short,
                        unsigned int, unsigned long, unsigned long long>;

template <typename T>
using enable_int_type_t = typename std::enable_if_t<is_int_type_v<T>>;

template <typename T, typename Enable = void>
class Generator {};

template <typename T>
class Generator<T, enable_int_type_t<T>> {
 private:
  std::mt19937_64 gen{std::random_device{}()};
  std::uniform_int_distribution<T> dist;

 public:
  Generator(const T& min, const T& max) : dist{min, max} {}
  Generator(const Generator&) = delete;
  Generator(Generator&&) = delete;

  T getMin() noexcept(noexcept(dist.min())) { return dist.min(); }
  T getMax() noexcept(noexcept(dist.max())) { return dist.max(); }

  void setRange(const T& min, const T& max) {
    if (!checkRange(min, max)) {
      throw std::logic_error{"min_range > max_range"};
    }

    dist = std::uniform_int_distribution<T>(min, max);
  }

  T operator()() { return dist(gen); }
  Generator& operator=(const Generator&) = delete;
  Generator& operator=(Generator&&) = delete;
};

}  // namespace gen

#endif  // _GENERATOR_HPP_