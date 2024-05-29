#include "../vector.h"
#include <iostream>

int geometry::Vector::GetX() const {
  return x_;
}
int geometry::Vector::GetY() const {
  return y_;
}
geometry::Vector::Vector(int x, int y) {
  x_ = x;
  y_ = y;
}
geometry::Vector geometry::Vector::operator+() const {
  return *this;
}
geometry::Vector geometry::Vector::operator+(const Vector& val) const {
  return {x_ + val.x_, y_ + val.y_};
}
geometry::Vector geometry::Vector::operator-() const {
  return {-x_, -y_};
}
geometry::Vector geometry::Vector::operator-(const Vector& val) const {
  return {x_ - val.x_, y_ - val.y_};
}
geometry::Vector geometry::Vector::operator/(int val) const {
  if (val == 0) {
    throw std::exception();
  }
  return {x_ / val, y_ / val};
}
geometry::Vector geometry::Vector::operator*(int val) const {
  return {x_ * val, y_ * val};
}
geometry::Vector& geometry::Vector::operator+=(const Vector& val) {
  x_ += val.x_;
  y_ += val.y_;
  return *this;
}
geometry::Vector& geometry::Vector::operator-=(const Vector& val) {
  x_ -= val.x_;
  y_ -= val.y_;
  return *this;
}
geometry::Vector& geometry::Vector::operator*=(int val) {
  x_ *= val;
  y_ += val;
  return *this;
}
geometry::Vector& geometry::Vector::operator/=(int val) {
  if (val == 0) {
    throw std::exception();
  }
  x_ /= val;
  y_ /= val;
  return *this;
}
bool geometry::Vector::operator==(const Vector& val) const {
  return x_ == val.x_ && y_ == val.y_;
}
bool geometry::Vector::operator!=(const Vector& val) const {
  return x_ != val.x_ || y_ != val.y_;
}
std::string geometry::Vector::ToString() {
  std::string s = "Vector(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";
  return s;
}