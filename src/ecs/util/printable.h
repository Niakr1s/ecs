#ifndef PRINTABLE_H
#define PRINTABLE_H

#include <iomanip>
#include <iostream>

class Printable {
 public:
  virtual ~Printable() = default;

  friend std::ostream& operator<<(std::ostream& out,
                                  const Printable& printable);

  std::ostream& print(std::ostream& out) const {
    std::ios tmp(nullptr);
    tmp.copyfmt(out);
    doPrint(out);
    out.copyfmt(tmp);
    return out;
  }

 protected:
  virtual std::ostream& doPrint(std::ostream& out) const = 0;
};

inline std::ostream& operator<<(std::ostream& out, const Printable& printable) {
  return printable.print(out);
}

#endif  // PRINTABLE_H
