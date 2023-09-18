#ifndef PAIRS_HPP
#define PAIRS_HPP
#include <algorithm>
#include <iostream>
#include <string>

template <typename T> class Pair {
private:
  T *_a;
  T *_b;
  T *_stray;

public:
  // Constructors/Desctructors
  Pair<T>();
  Pair<T>(T &a, T &b);
  Pair<T>(const Pair<T> &p);
  ~Pair<T>();

  // Getters
  T &getA() const;
  T &getB() const;
  T *getStray() const;

  // Setters
  void setA(T &a);
  void setB(T &b);
  void setStray(T *stray);

  // Operators
  Pair<T> &operator=(const Pair<T> &p);
  bool operator==(const Pair<T> &p) const;
  bool operator!=(const Pair<T> &p) const;
  bool operator<(const Pair<T> &p) const;
  bool operator>(const Pair<T> &p) const;
  bool operator<=(const Pair<T> &p) const;
  bool operator>=(const Pair<T> &p) const;

  // Useful
  void sort();
};

template <typename T> struct Printer {
  static void print(std::ostream &os, const T &value) { os << value; }
};

template <typename T> struct Printer<Pair<T>> {
  static void print(std::ostream &os, const Pair<T> &p) {
    os << "(";
    Printer<T>::print(os, p.getA());
    os << ", ";
    Printer<T>::print(os, p.getB());
    os << ")";
  }
};

template <typename T> struct Printer<std::vector<T>> {
  static void print(std::ostream &os, const std::vector<T> &vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
      Printer<T>::print(os, vec[i]);
      if (i < vec.size() - 1)
        os << ", ";
    }
    os << "]";
  }
};

/* template <typename T> */
/* std::ostream& operator<<(std::ostream& os, const Pair<T>& p); */
template <typename T>
std::ostream &operator<<(std::ostream &os, const Pair<T> &p) {
  Printer<Pair<T>>::print(os, p);
  return os;
}

#include "Pairs.tpp"
#endif
