#ifndef ANGLE_H
#define ANGLE_H

#include "printable.h"

namespace ecs {

/*
 *          y
 * p/2..p   |  p..p/2
 *          |
 * ____________________x
 *          |
 * p..3/2p  |  3/2p..2p
 *          |
 */

class Angle : public Printable {
 public:
  inline static double PI = 3.14159265358979323846;

  static Angle fromRadians(double rad);
  static Angle fromDegrees(double deg);
  static Angle fromPi(double pi_multiplier);

  double diffX() const;
  double diffY() const;

  std::ostream &doPrint(std::ostream &out) const override;

 private:
  double rad_;

  Angle(double rad);
};

namespace angle_literals {

Angle operator"" _rad(long double rad);
Angle operator"" _deg(long double deg);
Angle operator"" _pi(long double pi_multiplier);

}  // namespace angle_literals

}  // namespace ecs

#endif  // ANGLE_H
