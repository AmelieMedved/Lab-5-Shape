#pragma once
#include "shape.h"

template <class T>
struct Line :public Shape
{
private:
  int size;
  T* data;

public:
  Line();
  Line(int _size, T* _data);
  Line(int _size, T _data);
  Line(const Line& obj);
  ~Line();
  float Area() override {throw "line";}
  std::ostream& Print(std::ostream& out) override;
  float Volume() override { throw "flat shape"; }

  int GetSize();
  T GetArr();
  void SetSize(int _size);
  void SetArr(int _size, T* _data);
  bool operator ==(const Line& obj);
  Line<T> operator=(const Line<T>& obj);
};

template<class T>
Line<T>::Line()
{
  size = 2;
  data = new char[2];
  for (int i = 0; i < size; i++)
  {
    data[i] = "*";
  }
}

template<class T>
Line<T>::Line(int _size, T* _data)
{
  size = _size;
  data = new char[size];
  for (int i = 0; i < size; i++)
  {
    data[i] = _data[i];
  }
}

template<class T>
Line<T>::Line(int _size, T _data)
{
  size = _size;
  data = new T[size];
  for (int i = 0; i < size; i++)
  {
    data[i] = _data;
  }
}

template<class T>
Line<T>::Line(const Line& obj)
{
  size = obj.size;
  if (data != 0)
  {
    data = 0;
    delete[] data;
  }
  data = new T[size];
  for (int i = 0; i < size; i++)
  {
    data[i] = obj.data[i];
  }
}

template<class T>
Line<T>::~Line()
{
  if (this->data != 0)
  {
    size = 0;
    data = 0;
    delete[] data;
  }
}

template<class T>
int Line<T>::GetSize()
{
  return size;
}

template<class T>
T Line<T>::GetArr()
{
  return data;
}

template<class T>
void Line<T>::SetSize(int _size)
{
  size = _size;
}

template<class T>
void Line<T>::SetArr(int _size, T* _data)
{
  size = _size;
  if (data != 0)
  {
    data = 0;
    delete[] data;
  }
  data = new T[size];
  for (int i = 0; i < size; i++)
  {
    data[i] = _data[i];
  }
}

template<class T>
Line<T> Line<T>::operator=(const Line<T>& obj)
{
  if (*this == obj)
  {
    return *this;
  }
  data = 0;
  delete[] data;
  size = obj.size;
  data = new T[size];
  for (int i = 0; i < size; i++)
  {
    data[i] = obj.data[i];
  }
  return *this;
}

template<class T>
std::ostream& Line<T>::Print(std::ostream& out)
{
  for (int i = 0; i < size; i++)
  {
    out << data[i];
  }
  out << std::endl;
  return out;
}

template<class T>
bool Line<T>::operator==(const Line& obj)
{
  int count = 0;
  if (size = obj.size)
  {
    for (int i = 0; i < size; i++)
    {
      count = count + 1;
    }
  }
  if (count == size)
  {
    return true;
  }
  else 
    return false;
}