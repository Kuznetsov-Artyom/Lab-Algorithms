#ifndef _BENCHMARK_HPP_
#define _BENCHMARK_HPP_

#include <functional>
#include <string>

#include "timer.hpp"

#define BENCHMARK_CREATE(varName, typeTime, func, count) \
  bmk::Benchmark<typeTime> varName(std::function<void()>(func), count)
#define BENCHMARK_START(varName) varName()
#define BENCHMARK_RESET(varName) varName.reset()

namespace bmk {
using count_t = unsigned long long;
using avg_time_t = long double;

template <typename Period, typename Enable = void>
class Benchmark {};

template <typename Period>
class Benchmark<Period, tmr::enable_type_time_t<Period>> {
 private:
  std::function<void()> mFunc;
  count_t mCount;

 public:
  Benchmark(std::function<void()> func, count_t count)
      : mFunc{func}, mCount{count} {}

  Benchmark(const Benchmark&) = delete;
  Benchmark(Benchmark&&) = delete;

  long long operator()() {
    count_t total = 0.0;

    for (count_t i = 0; i < mCount; ++i) {
      tmr::Timer<Period> timer;
      mFunc();
      total += timer();
    }
    return total / mCount;
  }

  Benchmark& operator=(const Benchmark&) = delete;
  Benchmark& operator=(Benchmark&&) = delete;
};

}  // namespace bmk

#endif  // _BENCHMARK_HPP_