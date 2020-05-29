#pragma once
#include"shape.h"
#include"line.h"

template <class T>
struct Triangle : Shape
{
private:
  int height;
  T** data;

public:
  Triangle();
  Triangle(int _height, T _data);
  Triangle(const Triangle& obj);
  ~Triangle();
  float Area() override;
  std::ostream& Print(std::ostream& out) override;
  float Volume() override { throw "flat shape"; }

  int GetHeight();
  T GetData();
  void SetHeight(int _height);
  bool operator ==(const Triangle& obj);
  Triangle<T> operator=(const Triangle<T>& obj);
  void Data(T _data);
};

template<class T>
Triangle<T>::Triangle()
{
  height = 3;
  this->Data('*');
}

template<class T>
Triangle<T>::Triangle(int _height, T _data)
{
  height = _height + 1;
  this->Data(_data);
}

template<class T>
Triangle<T>::Triangle(const Triangle& obj)
{
  if (data != 0)
  {
    for (int i = 0; i < height; i++)
      delete[] data[i];
    delete[] data;
  }
  height = obj.height;
  this->Data(obj.GetData());
}

template<class T>
Triangle<T>::~Triangle()
{
  if (data != 0)
  {
    for (int i = 0; i < height; i++)
    {
      data[i] = 0;
      delete[] data[i];
    }
    data = 0;
    delete[] data;
    height = 0;
  }
}

template<class T>
int Triangle<T>::GetHeight()
{
  return height - 1;
}

template<class T>
T Triangle<T>::GetData()
{
  if (data != 0)
  {
    return data[0][0];
  }
  else throw - 1;
}

template<class T>
void Triangle<T>::SetHeight(int _height)
{
  height = _height;
}

template<class T>
float Triangle<T>::Area()
{
  return ((height - 1) * (height - 1)) / 2;
}

template<class T>
std::ostream& Triangle<T>::Print(std::ostream& out)
{
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < i; j++)
      out << data[i][j];
    out << std::endl;
  }
  return out;
}

template<class T>
bool Triangle<T>::operator==(const Triangle& obj)
{
  if (height == obj.height && data[0][0] == obj.data[0][0])
    return true;
  return false;
}

template<class T>
Triangle<T> Triangle<T>::operator=(const Triangle<T>& obj)
{
  if (*this == obj)
  {
    return *this;
  }
  if (data != 0)
  {
    for (int i = 0; i < height; i++)
    {
      data[i] = 0;
      delete[] data[i];
    }
    data = 0;
    delete[] data;
  }
  height = obj.height;
  this->Data(obj.GetData());
  return *this;
}

template<class T>
void Triangle<T>::Data(T _data)
{
  data = new T * [height];
  for (int i = 0; i < height; i++)
    data[i] = new T[height];


  for (int i = 0; i < height; i++)
    for (int j = 0; j < i; j++)
      data[i][j] = _data;
}