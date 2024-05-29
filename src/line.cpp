#include "../line.h"

geometry::Line::Line(Point x, Point y) : one_(x), two_(y) {
}
bool geometry::Line::ContainsPoint(const Point& point) const {
  Vector ab = two_ - one_;
  Vector ap = point - one_;
  return (ap.GetX() * ab.GetY() == ap.GetY() * ab.GetX());
}
geometry::IShape& geometry::Line::Move(const Vector& v) {
  one_.Move(v);
  two_.Move(v);
  return *this;
}
bool geometry::Line::CrossesSegment(const Segment& s) const {
  Segment a = s;
  auto ccw = [](const Point& A, const Point& B, const Point& C) {
    return (C.GetY() - A.GetY()) * (B.GetX() - A.GetX()) - (B.GetY() - A.GetY()) * (C.GetX() - A.GetX());
  };
  Point A = one_, B = two_, C = a.GetX(), D = a.GetY();
  int ccw1 = ccw(A, B, C);
  int ccw2 = ccw(A, B, D);
  return (ccw1 * ccw2 <= 0);
}
geometry::IShape* geometry::Line::Clone() const {
  auto l = new Line(one_, two_);
  return l;
}

std::string geometry::Line::ToString() const {
  int a = two_.GetY() - one_.GetY();
  int b = one_.GetX() - two_.GetX();
  int c = one_.GetY() * two_.GetX() - one_.GetX() * two_.GetY();
  return "Line(" + std::to_string(a) + ", " + std::to_string(b) + ", " + std::to_string(c) + ")";
}