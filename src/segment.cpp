#include "../segment.h"

geometry::Segment::Segment() {
  x_ = {0, 0};
  y_ = {0, 0};
}
geometry::Segment::Segment(Point x, Point y) {
  x_ = x;
  y_ = y;
  InitLine();
}
bool geometry::Segment::ContainsPoint(const Point& point) const {
  Vector ab = y_ - x_;
  Vector ap = point - x_;
  Vector bp = point - y_;
  return (ap.GetX() * ab.GetY() == ap.GetY() * ab.GetX()) && (ap.GetX() * bp.GetX() <= 0) &&
         (ap.GetY() * bp.GetY() <= 0);
}
geometry::IShape& geometry::Segment::Move(const Vector& v) {
  x_.Move(v);
  y_.Move(v);
  InitLine();
  return *this;
}
bool geometry::Segment::CrossesSegment(const Segment& s) const {
  auto ccw = [](const Point& A, const Point& B, const Point& C) {
    return (C.GetY() - A.GetY()) * (B.GetX() - A.GetX()) - (B.GetY() - A.GetY()) * (C.GetX() - A.GetX());
  };

  Segment a = s;
  Point A = x_, B = y_, C = a.GetX(), D = a.GetY();
  int ccw1 = ccw(A, B, C);
  int ccw2 = ccw(A, B, D);
  int ccw3 = ccw(C, D, A);
  int ccw4 = ccw(C, D, B);

  if (((ccw1 > 0 && ccw2 < 0) || (ccw1 < 0 && ccw2 > 0)) && ((ccw3 > 0 && ccw4 < 0) || (ccw3 < 0 && ccw4 > 0))) {
    return true;
  }

  if (ContainsPoint(C) || ContainsPoint(D) || s.ContainsPoint(A) || s.ContainsPoint(B)) {
    return true;
  }

  return false;
}
geometry::IShape* geometry::Segment::Clone() const {
  auto newseg = new Segment(x_, y_);
  return newseg;
}
std::string geometry::Segment::ToString() const {
  return "Segment(" + x_.ToString() + ", " + y_.ToString() + ")";
}
void geometry::Segment::InitLine() {
  auto x1 = x_.GetX(), y1 = x_.GetY(), x2 = y_.GetX(), y2 = y_.GetY();
  a_ = y1 - y2;
  b_ = x2 - x1;
  c_ = y1 * (x1 - x2) - x1 * (y1 - y2);
}
geometry::Point geometry::Segment::GetX() {
  return x_;
}
geometry::Point geometry::Segment::GetY() {
  return y_;
}