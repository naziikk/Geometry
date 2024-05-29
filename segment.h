#ifndef GEOMETRY_SEGMENT_H
#define GEOMETRY_SEGMENT_H

#include "ishape.h"
#include "point.h"

namespace geometry {
class Segment : public IShape {
 private:
  Point x_;
  Point y_;
  int a_ = 0, b_ = 0, c_ = 0;
  void InitLine();

 public:
  Point GetX();
  Point GetY();
  Segment(Point x, Point y);
  Segment();
  ~Segment() override = default;
  bool ContainsPoint(const Point& point) const override;
  IShape& Move(const Vector& v) override;
  bool CrossesSegment(const Segment& s) const override;
  IShape* Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry

#endif  // GEOMETRY_SEGMENT_H
