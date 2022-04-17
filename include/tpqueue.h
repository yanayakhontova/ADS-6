// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
template<typename T, int size>
class TPQueue {
 private:
    T b[size] = {0};
    int f = 0, l = 0;
 public:
  void push(T value) {
      int i = l;
      while ((--i >= f) && (value.prior > b[i % size].prior)) {
          b[(i + 1) % size] = b[i % size];
      }
      b[(i+1) % size] = value;
      l++;
  }
  T pop() {
      return b[(f++) % size];
  }
};
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
