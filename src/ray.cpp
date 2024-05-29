#include "../ray.h"

geometry::Ray::Ray(Point x, Point y) {
  x_ = x;
  y_ = y;
}
bool geometry::Ray::ContainsPoint(const Point& point) const {
  Vector op = point - x_;
  Vector direction = y_ - x_;
  bool cond1 = (direction.GetX() * op.GetY() == direction.GetY() * op.GetX());
  bool cond2 = (direction.GetX() * op.GetX() >= 0);
  bool cond3 = (direction.GetY() * op.GetY() >= 0);
  return cond1 && cond2 && cond3;
}
geometry::IShape& geometry::Ray::Move(const Vector& v) {
  x_.Move(v);
  y_.Move(v);
  return *this;
}
bool geometry::Ray::CrossesSegment(const Segment& s) const {
  Segment a = s;
  Vector p1 = a.GetX() - x_;
  Vector p2 = a.GetY() - x_;
  Vector dir = y_ - x_;
  Vector segDir = a.GetY() - a.GetX();
  int ccw1 = dir.GetX() * p1.GetY() - dir.GetY() * p1.GetX();
  int ccw2 = dir.GetX() * p2.GetY() - dir.GetY() * p2.GetX();
  int ccw3 = segDir.GetX() * p1.GetY() - segDir.GetY() * p1.GetX();
  int ccw4 = segDir.GetX() * p2.GetY() - segDir.GetY() * p2.GetX();
  if (((ccw1 > 0 && ccw2 < 0) || (ccw1 < 0 && ccw2 > 0)) && ((ccw3 > 0 && ccw4 < 0) || (ccw3 < 0 && ccw4 > 0))) {
    return true;
  }
  return ContainsPoint(a.GetX()) || ContainsPoint(a.GetY());
}
geometry::IShape* geometry::Ray::Clone() const {
  auto newray = new Ray(x_, y_);
  return newray;
}
std::string geometry::Ray::ToString() const {
  Vector a = Vector(y_.GetX() - x_.GetX(), y_.GetY() - x_.GetY());
  std::string s = "Ray(" + x_.ToString() + ", " + a.ToString() + ")";
  return s;
}
