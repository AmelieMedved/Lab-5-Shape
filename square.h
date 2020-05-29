#pragma once
#include"shape.h"

template <class T>
struct Square : Shape
{
private:
  int side;
  T** data;


public:
  Square();
  Square(int _side, T _data);
  Square(const Square& _square);
  ~Square();
  float Area() override;
  std::ostream& Print(std::ostream& out) override;
  float Volume() override { throw "flat shape"; }

  int GetSide();
  T GetData();
  void SetSide(int _side);
  void SetData(T _data);
  void Data(T _data);
  Square<T> operator=(const Square<T>& obj);
  bool operator ==(const Square& obj);
};

template<class T>
inline Square<T>::Square()
{
  side = 2;
  this->Data('*');
}

template<class T>
inline Square<T>::Square(int _side, T _data)
{
  side = _side;
  this->Data(_data);
}

template<class T>
inline Square<T>::Square(const Square& _square)
{
  side = _square.side;
  if (data != 0)
  {
    for (int i = 0; i < side; i++)
    {
      data[i] = 0;
      delete[] data[i];
    }
    data = 0;
    delete[] data;
  }
  this->Data(_square.GetData());
}

template<class T>
inline Square<T>::~Square()
{
  if (data != 0)
  {
    for (int i = 0; i < side; i++)
    {
      data[i] = 0;
      delete[] data[i];
    }
    data = 0;
    delete[] data;
    side = 0;
  }
}

template<class T>
inline int Square<T>::GetSide()
{
  return side;
}

template<class T>
inline T Square<T>::GetData()
{
  if (data != 0)
  {
    return (data[0][0]);
  }
  else throw - 1;
}

template<class T>
inline void Square<T>::SetSide(int _side)
{
  side = _side;
}

template<class T>
inline void Square<T>::SetData(T _data)
{
  if (data != 0)
  {
    for (int i = 0; i < side; i++)
      for (int j = 0; j < side; j++)
        data[i][j] = _data;
  }
  else throw - 1;
}

template<class T>
inline float Square<T>::Area()
{
  return (side * side);
}

template<class T>
inline std::ostream& Square<T>::Print(std::ostream& out)
{
  for (int i = 0; i < side; i++)
  {
    for (int j = 0; j < side; j++)
      out << data[i][j];
    out << std::endl;
  }
  return out;
}

template<class T>
inline bool Square<T>::operator==(const Square& obj)
{
  if (side == obj.side && data[0][0] == obj.data[0][0])
  {
    return true;
  }
  return false;
}

template<class T>
inline Square<T> Square<T>::operator=(const Square<T>& obj)
{
  if (*this == obj)
  {
    return *this;
  }
  if (data != 0)
  {
    for (int i = 0; i < side; i++)
    {
      data[i] = 0;
      delete[] data[i];
    }
    data = 0;
    delete[] data;
  }
  side = obj.side;
  this->Data(obj.GetData());
  return *this;
}

template<class T>
inline void Square<T>::Data(T _data)
{
  data = new T * [side];
  for (int i = 0; i < side; i++)
    data[i] = new T[side];

  for (int i = 0; i < side; i++)
    for (int j = 0; j < side; j++)
      data[i][j] = _data;
}