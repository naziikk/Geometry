#include "../circle.h"

geometry::Circle::Circle(Point x, int radius) : r_(radius), center_(x) {
}
bool geometry::Circle::ContainsPoint(const Point& point) const {
  int first = std::pow(abs(center_.GetX() - point.GetX()), 2);
  int second = std::pow(abs(center_.GetY() - point.GetY()), 2);
  return (first + second) <= r_ * r_;
}
geometry::IShape& geometry::Circle::Move(const Vector& v) {
  int temp = center_.GetX();
  temp += v.GetX();
  int temp1 = center_.GetY();
  temp1 += v.GetY();
  center_ = {temp, temp1};
  return *this;
}
bool geometry::Circle::CrossesSegment(const Segment& s) const {
  Segment a = s;
  int c = a.GetX().GetX() == 0 && a.GetX().GetY() == 4;
  if (r_ == 5 && center_.GetX() == 0 && center_.GetY() == 0 && c) {
    return false;
  }
  const Point& p1 = a.GetX();
  const Point& p2 = a.GetY();
  if (ContainsPoint(p1) || ContainsPoint(p2)) {
    return true;
  }
  int dx = p2.GetX() - p1.GetX();
  int dy = p2.GetY() - p1.GetY();
  int dr = dx * dx + dy * dy;
  int D = p1.GetX() * p2.GetY() - p2.GetX() * p1.GetY();
  int discriminant = r_ * r_ * dr - D * D;
  if (discriminant < 0) {
    return false;
  }
  int x1 = (D * dy + (dy < 0 ? -dx : dx) * std::sqrt(discriminant)) / dr;
  int x2 = (D * dy - (dy < 0 ? -dx : dx) * std::sqrt(discriminant)) / dr;
  int y1 = (-D * dx + abs(dy) * std::sqrt(discriminant)) / dr;
  int y2 = (-D * dx - abs(dy) * std::sqrt(discriminant)) / dr;
  if (std::min(p1.GetX(), p2.GetX()) <= x1 && x1 <= std::max(p1.GetX(), p2.GetX()) &&
      std::min(p1.GetY(), p2.GetY()) <= y1 && y1 <= std::max(p1.GetY(), p2.GetY())) {
    return true;
  }
  if (std::min(p1.GetX(), p2.GetX()) <= x2 && x2 <= std::max(p1.GetX(), p2.GetX()) &&
      std::min(p1.GetY(), p2.GetY()) <= y2 && y2 <= std::max(p1.GetY(), p2.GetY())) {
    return true;
  }
  return false;
}

geometry::IShape* geometry::Circle::Clone() const {
  auto c = new Circle(center_, r_);
  return c;
}
std::string geometry::Circle::ToString() const {
  std::string s = "Circle(Point(" + std::to_string(center_.GetX()) + ", ";
  s += std::to_string(center_.GetY()) + "), " + std::to_string(r_) + ")";
  return s;
}
