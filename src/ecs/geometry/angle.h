#ifndef ANGLE_H
#define ANGLE_H

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

#include <cmath>

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

class Angle {
 public:
  Angle(double degree);

  double diffX() const;
  double diffY() const;

 private:
  double degree_;
};

}  // namespace ecs

#endif  // ANGLE_H
