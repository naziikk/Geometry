#ifndef GEOMETRY_CIRCLE_H
#define GEOMETRY_CIRCLE_H

#include "ishape.h"
#include "point.h"
#include "segment.h"
#include <cmath>

namespace geometry {
class Circle : public IShape {
  int r_;
  Point center_;

 public:
  Circle(Point center, int r);
  ~Circle() override = default;
  bool ContainsPoint(const Point& point) const override;
  IShape& Move(const Vector& v) override;
  bool CrossesSegment(const Segment& s) const override;
  IShape* Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry
#endif  // GEOMETRY_CIRCLE_H
