#ifndef POS_H
#define POS_H

#include <iostream>

#include "printable.h"

namespace ecs {

class Pos : public Printable {
 public:
  Pos(int x, int y);

  inline int x() const { return x_; }
  inline int y() const { return y_; }

  Pos operator+(const Pos& rhs) const;
  void operator+=(const Pos& rhs);

  Pos operator-(const Pos& rhs) const;
  void operator-=(const Pos& rhs);

  bool operator==(const Pos& rhs) const;

 protected:
  std::ostream& doPrint(std::ostream& out) const override;

 private:
  int x_, y_;
};

}  // namespace ecs

#endif  // POS_H
