#pragma once
#include"shape.h"

template <class T>
struct Circle : Shape
{
private:
  int rad;
  T** data;
public:
  Circle();
  Circle(int _rad, T _data);
  Circle(const Circle& circle);
  ~Circle();
  void Data(T _data);
  float Area() override;
  std::ostream& Print(std::ostream& out) override;

  float Volume() override { throw "flat shape"; }

  int GetRad();
  T GetData();
  void SetRad(int _rad);
  bool operator ==(const Circle& obj);
  Circle<T> operator=(const Circle<T>& obj);
};

template<class T>
 Circle<T>::Circle()
{
  rad = 2;
  this->Data('*');
}
template<class T>
void Circle<T>::Data(T _data)//для выделения памяти и установки нового массива(новой размерности)
{
  data = new T * [2 * rad - 1];
  for (int i = 0; i < 2 * rad - 1; i++)
    data[i] = new T[2 * rad];

  for (int i = 0; i < rad; i++)
    for (int j = rad - 1 - i; j < rad + i + 1; j++)
      data[i][j] = _data;

  for (int i = rad; i < 2 * rad - 1; i++)
    for (int j = 1 + i - rad; j < 3 * rad - 1 - i; j++)
      data[i][j] = _data;
}

template<class T>
 Circle<T>::Circle(int _rad, T _data)
{
  rad = _rad;
  this->Data(_data);
}

template<class T>
 Circle<T>::Circle(const Circle& circle)
{
  rad = circle.rad;
  if (data != 0)
  {
    for (int i = 0; i < 2 * rad - 1; i++)
    {
      data[i] = 0;
      delete[] data[i];
    }
    data = 0;
    delete[] data;
  }
  this->Data(circle.GetData());
}

template<class T>
 Circle<T>::~Circle()
{
  if (data != 0)
  {
    for (int i = 0; i < 2 * rad - 1; i++)
    {
      data[i] = 0;
      delete[] data[i];
    }
    data = 0;
    delete[] data;
  }
  rad = 0;
}

template<class T>
 int Circle<T>::GetRad()
{
  return rad;
}

template<class T>
 T Circle<T>::GetData()
{
  if (data != 0)
  {
    return this->data[0][0];
  }
  else throw - 1;
}

template<class T>
 void Circle<T>::SetRad(int _rad)
{
  rad = _rad;
}

template<class T>
 float Circle<T>::Area()
{
  return (rad * rad * 3.14);
}

template<class T>
 std::ostream& Circle<T>::Print(std::ostream& out)
{
  for (int i = 0; i < 2 * rad - 1; i++)
  {
    for (int j = 0; j < 2 * rad; j++)
    {
      if ((i < rad && j >= (rad - 1 - i) && j < (rad + i + 1)) || (i >= rad && i < (2 * rad - 1) && j >= (1 + i - rad) && j < (3 * rad - 1 - i)))
        out << data[i][j];
      else out << " ";
    }
    out << std::endl;
  }
  return out;
}

template<class T>
 bool Circle<T>::operator==(const Circle& obj)
{
  if (rad == obj.GetRad)
  {
    if (data[rad][rad] == obj.data[rad][rad])
    {
      return true;
    }
  }
  return false;
}

template<class T>
 Circle<T> Circle<T>::operator=(const Circle<T>& obj)
{
  if (*this == obj)
  {
    return *this;
  }
  if (data != 0)
  {
    for (int i = 0; i < 2 * rad - 1; i++)
    {
      data[i] = 0;
      delete[] data[i];
    }
    data = 0;
    delete[] data;
  }
  rad = obj.rad;
  this->Data(obj.GetData());
  return *this;
}