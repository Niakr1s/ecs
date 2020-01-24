#ifndef ANGLE_H
#define ANGLE_H

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

  inline static double PI = 3.14159265358979323846;

  double diffX() const;
  double diffY() const;

 private:
  double degree_;
};

}  // namespace ecs

#endif  // ANGLE_H
