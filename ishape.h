#ifndef GEOMETRY_ISHAPE_H
#define GEOMETRY_ISHAPE_H
#include "vector.h"
#include <string>

namespace geometry {
class Point;
class Segment;
class IShape {
 public:
  virtual ~IShape() = default;
  virtual IShape& Move(const Vector& arr) = 0;
  virtual bool ContainsPoint(const Point& point) const = 0;
  virtual bool CrossesSegment(const Segment& segment) const = 0;
  virtual IShape* Clone() const = 0;
  virtual std::string ToString() const = 0;
};
}  // namespace geometry

#endif  // GEOMETRY_ISHAPE_H
