#ifndef POS_H
#define POS_H

#include <initializer_list>

namespace ecs {

class Pos {
 public:
  Pos(int x, int y);
  Pos(std::initializer_list<int> lst);

  inline int x() const { return x_; }
  inline int y() const { return y_; }

  Pos operator+(const Pos& rhs) const;
  void operator+=(const Pos& rhs);

  Pos operator-(const Pos& rhs) const;
  void operator-=(const Pos& rhs);

  bool operator==(const Pos& rhs) const;

 private:
  int x_, y_;
};

}  // namespace ecs

#endif  // POS_H
