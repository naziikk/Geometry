#ifndef GEOMETRY_RAY_H
#define GEOMETRY_RAY_H

#include "ishape.h"
#include "point.h"
#include "segment.h"
#include <iostream>
#include <string>

namespace geometry {
class Ray : public IShape {
  Point x_;
  Point y_;

 public:
  Ray(Point x, Point y);
  ~Ray() override = default;
  bool ContainsPoint(const Point& point) const override;
  IShape& Move(const Vector& v) override;
  bool CrossesSegment(const Segment& s) const override;
  IShape* Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry

#endif  // GEOMETRY_RAY_H
