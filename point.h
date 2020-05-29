#pragma once
#include"shape.h"

template<class T>
struct Point : Shape
{
private:
  T point;

public:
  Point();
  Point(T _point);
  Point(const Point& obj);
  ~Point();
  float Area() override { throw "point"; };
  std::ostream& Print(std::ostream& out) override;
  float Volume() override { throw "flat shape"; }

  T GetPoint();
  void SetPoint(T _point);
  bool operator ==(const Point& obj);
  Point<T> operator=(const Point<T>& obj);
};

template<class T>
Point<T>::Point()
{
  point = '.';
}
template<class T>
Point<T>::Point(T _point)
{
  point = _point;
}
template<class T>
Point<T>::Point(const Point& obj)
{
  point = obj.point;
}
template<class T>
T Point<T>::GetPoint()
{
  return point;
}
template<class T>
Point<T>::~Point()
{
  point = 0;
}
template<class T>
void Point<T>::SetPoint(T _point)
{
  point = _point;
}

template<class T>
bool Point<T>::operator ==(const Point& obj)
{
  if (point == obj.point)
  {
    return true;
  }
  else false;
}

template<class T>
Point<T> Point<T>::operator=(const Point<T>& obj)//в абстрактном понимание, точка-это любой введённый тип данных соответствующий одному объекту
{
  if (*this == obj)
  {
    return *this;
  }
  Point = obj.Point;
  return *this;
}

template<class T>
std::ostream& Point<T>::Print(std::ostream& out)
{
  out << this->GetPoint();
  return out;
}