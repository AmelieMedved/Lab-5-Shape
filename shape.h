#pragma once
#include <iostream>

struct Shape
{
public:
  virtual float Area() = 0;//�������
  virtual float Volume() = 0;//�����
  virtual std::ostream& Print(std::ostream& out) = 0;//�����
  friend std::ostream& operator<<(std::ostream& out, Shape& obj);
  bool operator > (Shape& obj);
  bool operator < (Shape& obj);
};


std::ostream& operator<<(std::ostream& out, Shape& obj)
{
  return obj.Print(out);
}


bool Shape::operator >(Shape& obj)
{
  if (Area() > obj.Area())
    return true;
  return false;
}

bool Shape::operator < (Shape& obj)
{
  if (Area() < obj.Area())
    return true;
  return false;
}