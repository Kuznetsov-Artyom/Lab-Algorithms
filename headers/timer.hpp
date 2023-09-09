#ifndef _TIMER_HPP_
#define _TIMER_HPP_

#include <chrono>
#include "traits.hpp"

#define TIMER_START(valName, period) tmr::Timer<period> valName
#define TIMER_GET(valName) valName()
#define TIMER_RESET(valName) valName.reset()

namespace tmr {
using nanosecond_t = std::ratio<1, 1000000000>;
using microsecond_t = std::ratio<1, 1000000>;
using millisecond_t = std::ratio<1, 1000>;
using second_t = std::ratio<1>;
using minute_t = std::ratio<60>;
using hour_t = std::ratio<3600>;

template <typename T>
constexpr bool is_type_time_v =
    traits::is_any_of_v<T, nanosecond_t, microsecond_t, millisecond_t, second_t,
                minute_t, hour_t>;

template <typename T>
using enable_type_time_t = typename std::enable_if_t<is_type_time_v<T>>;

template <typename Period, typename Enable = void>
class Timer {};

template <typename Period>
class Timer<Period, enable_type_time_t<Period>> {
 private:
  using clock_t = std::chrono::high_resolution_clock;
  using type_time_t = std::chrono::duration<int64_t, Period>;

  std::chrono::time_point<clock_t> start;

 public:
  Timer() : start{clock_t::now()} {}
  Timer(const Timer&) = delete;
  Timer(Timer&&) = delete;

  void reset();

  int64_t operator()() const;
  Timer& operator= (const Timer&) = delete;
  Timer& operator= (Timer&&) = delete;
};

template <typename Period>
inline int64_t tmr::Timer<Period, enable_type_time_t<Period>>::operator()()
    const {
  return std::chrono::duration_cast<type_time_t>(clock_t::now() - start)
      .count();
}

template <typename Period>
inline void tmr::Timer<Period, enable_type_time_t<Period>>::reset() {
  start = clock_t::now();
}
}  // namespace tmr

#endif  // _TIMER_HPP_