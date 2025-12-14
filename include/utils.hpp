#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

namespace utils {
  // Better print
  template <typename T>
  inline void println(const T& x) {
    std::cout << x << '\n';
  }

  // Better rand()
  // still must put 'srand(time(0));' somewhere in code
  template <typename T>
  inline int rng(const T& x) {
    // if statement stops occasional floating point exception fault
    if (x == 0) return 0;
    return (std::rand() % x) + 1;
  }

  template <typename T>
  inline std::string readVec(const T& vec) {
    std::string buf;
      for (int i = 0; i < vec.size(); i++) {
        buf += vec[i];
      }
    return buf;
  }

  inline void clr() {
    // Ik it looks bad but it just clears the screen and moves cursor to top left
    std::cout << "\033[2J\033[H";
  }

}
#endif
