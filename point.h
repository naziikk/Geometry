#ifndef GEOMETRY_POINT_H
#define GEOMETRY_POINT_H

#include "ishape.h"

namespace geometry {
class Point : public IShape {
  int x_;
  int y_;

 public:
  Point();
  Point(int x, int y);
  ~Point() override = default;
  int GetX() const;
  int GetY() const;
  bool ContainsPoint(const Point& point) const override;
  IShape& Move(const Vector& v) override;
  bool CrossesSegment(const Segment& s) const override;
  IShape* Clone() const override;
  std::string ToString() const override;
  Vector operator-(const Point& point) const;
  bool operator==(const Point& point) const;
  bool operator!=(const Point& point) const;
  Point& operator+=(const Point& point);
};
}  // namespace geometry

#endif  // GEOMETRY_POINT_H
