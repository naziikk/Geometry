#ifndef GEOMETRY_POLYGON_H
#define GEOMETRY_POLYGON_H

#include "ishape.h"
#include "point.h"
#include <vector>
#include "segment.h"
#include <sstream>

namespace geometry {
class Polygon : public IShape {
  std::vector<Point> arr_;

 public:
  Polygon(std::vector<Point> a);  // NOLINT
  ~Polygon() override = default;
  bool ContainsPoint(const Point& point) const override;
  IShape& Move(const Vector& v) override;
  bool CrossesSegment(const Segment& s) const override;
  IShape* Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry

#endif  // GEOMETRY_POLYGON_H
