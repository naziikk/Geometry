#ifndef GEOMETRY_LINE_H
#define GEOMETRY_LINE_H

#include "segment.h"

namespace geometry {
class Line : public IShape {
  Point one_;
  Point two_;

 public:
  Line(Point x, Point y);
  ~Line() override = default;
  bool ContainsPoint(const Point& point) const override;
  IShape& Move(const Vector& v) override;
  bool CrossesSegment(const Segment& s) const override;
  IShape* Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry

#endif  // GEOMETRY_LINE_H
