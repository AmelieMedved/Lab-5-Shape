#pragma once
#include"shape.h"

template <class T>
struct Rectangle : Shape
{
private:
  int len;
  int width;
  T** data;
public:
  Rectangle();
  Rectangle(int _len, int _width, T _data);
  Rectangle(const Rectangle& obj);
  ~Rectangle();
  float Area() override;
  std::ostream& Print(std::ostream& out) override;
  float Volume() override { throw "flat shape"; }

  int GetLength();
  int GetWidth();
  T GetData();
  void SetSize(int _len, int _width);
  void SetData(T _data);
  bool operator ==(const Rectangle& obj);
  Rectangle<T> operator=(const Rectangle<T>& obj);
  void Data(T _data);
};

template<class T>
inline Rectangle<T>::Rectangle()
{
  len = 2;
  width = 3;
  this->Data('*');

}

template<class T>
inline Rectangle<T>::Rectangle(int _len, int _width, T _data)
{
  len = _len;
  width = _width;
  this->Data(_data);
}

template<class T>
inline Rectangle<T>::Rectangle(const Rectangle& obj)
{
  len = obj.len;
  width = obj.width;
  if (data != 0)
  {
    for (int i = 0; i < width; i++)
    {
      data[i] = 0;
      delete[] data[i];
    }
    data = 0;
    delete[] data;
  }
  this->Data(obj.GetData());
}

template<class T>
inline Rectangle<T>::~Rectangle()
{
  if (data != 0)
  {
    for (int i = 0; i < width; i++)
    {
      data[i] = 0;
      delete[] data[i];
    }
    data = 0;
    delete[] data;
    len = 0;
    width = 0;
  }
}

template<class T>
inline int Rectangle<T>::GetLength()
{
  return len;
}

template<class T>
inline int Rectangle<T>::GetWidth()
{
  return width;
}

template<class T>
inline T Rectangle<T>::GetData()
{
  if (data != nullptr)
  {
    return (data[0][0]);
  }
  else
    throw - 1;
}

template<class T>
inline void Rectangle<T>::SetSize(int _len, int _width)
{
  len = _len;
  width = _width;
}

template<class T>
inline void Rectangle<T>::SetData(T _data)
{
  if (data != 0)
  {
    for (int i = 0; i < width; i++)
      for (int j = 0; j < len; j++)
        data[i][j] = _data;
  }
  else throw - 1;
}

template<class T>
inline float Rectangle<T>::Area()
{
  return (width * len);
}

template<class T>
inline std::ostream& Rectangle<T>::Print(std::ostream& out)
{
  for (int i = 0; i < width; i++)
  {
    for (int j = 0; j < len; j++)
      out << data[i][j];
    out << std::endl;
  }
  return out;
}

template<class T>
inline bool Rectangle<T>::operator==(const Rectangle& obj)
{
  if (len == obj.len && width == obj.width && data[0][0] == obj.data[0][0])
    return true;
  return false;
}

template<class T>
inline Rectangle<T> Rectangle<T>::operator=(const Rectangle<T>& obj)
{
  if (*this == obj)
  {
    return *this;
  }
  if (data != 0)
  {
    for (int i = 0; i < width; i++)
    {
      data[i] = 0;
      delete[] data[i];
    }
    data = 0;
    delete[] data;
  }
  len = obj.len;
  width = obj.width;
  this->Data(obj.GetData());
  return *this;
}

template<class T>
inline void Rectangle<T>::Data(T _data)
{
  data = new T * [width];
  for (int i = 0; i < width; i++)
    data[i] = new T[len];

  for (int i = 0; i < width; i++)
    for (int j = 0; j < len; j++)
      data[i][j] = _data;
}