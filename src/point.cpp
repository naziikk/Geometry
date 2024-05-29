#include "../point.h"
#include "../segment.h"

geometry::Point::Point() {
  x_ = 0;
  y_ = 0;
}
int geometry::Point::GetX() const {
  return x_;
}
int geometry::Point::GetY() const {
  return y_;
}
geometry::Point::Point(int x, int y) {
  x_ = x;
  y_ = y;
}
bool geometry::Point::ContainsPoint(const Point& point) const {
  return x_ == point.x_ && y_ == point.y_;
}
geometry::IShape& geometry::Point::Move(const Vector& v) {
  x_ += v.GetX();
  y_ += v.GetY();
  return *this;
}
bool geometry::Point::CrossesSegment(const Segment& s) const {
  return s.ContainsPoint(*this);
}
geometry::IShape* geometry::Point::Clone() const {
  auto p = new Point(x_, y_);
  return p;
}
std::string geometry::Point::ToString() const {
  std::string s = "Point(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";
  return s;
}
geometry::Vector geometry::Point::operator-(const Point& point) const {
  return {x_ - point.x_, y_ - point.y_};
}
bool geometry::Point::operator==(const Point& point) const {
  return x_ == point.x_ && y_ == point.y_;
}
bool geometry::Point::operator!=(const Point& point) const {
  return !(*this == point);
}
geometry::Point& geometry::Point::operator+=(const Point& point) {
  x_ = x_ + point.x_;
  y_ += point.y_;
  return *this;
}