#pragma once
#include"Square.h"

template <class T>
class Cube : public Shape
{
private:
  int side;
  T*** data;

public:
  Cube();
  Cube(int _side, T _data);
  Cube(const Cube& cube);
  ~Cube();

  int GetSide();
  T GetData();
  void SetSide(int _side);

  float Area() override;
  float Volume() override;
  std::ostream& Print(std::ostream& out) override;

  bool operator ==(const Cube& obj);
  Cube<T> operator=(const Cube<T>& obj);
  void Data(T _data);
};

template<class T>
inline Cube<T>::Cube()
{
  side = 1;
  this->Data('*');
}

template<class T>
inline Cube<T>::Cube(int _side, T _data)
{
  side = _side;
  this->Data(_data);
}

template<class T>
inline Cube<T>::Cube(const Cube& cube)
{
  if (data != 0)
  {
    for (int i = 0; i < side; i++)
      for (int j = 0; j < side; j++)
      {
        data[i][j] = 0;
        delete[] data[i][j];
      }
    for (int i = 0; i < side; i++)
    {
      data[i] = 0;
      delete[] data[i];
    }
    data = 0;
    delete[] data;
  }
  side = cube.side;
  this->Data(cube.GetData());
}

template<class T>
inline Cube<T>::~Cube()
{
  if (data != 0)
  {
    for (int i = 0; i < side; i++)
      for (int j = 0; j < side; j++)
      {
        data[i][j] = 0;
        delete[] data[i][j];
      }
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
inline int Cube<T>::GetSide()
{
  return side;
}

template<class T>
inline T Cube<T>::GetData()
{
  if (data != 0)
  {
    return (data[0][0][0]);
  }
  else throw - 1;
}

template<class T>
void Cube<T>::SetSide(int _side)
{
  side = _side;
}

template<class T>
float Cube<T>::Area()
{
  return (side * side);
}

template<class T>
float Cube<T>::Volume()
{
  return (side * side * side);
}

template<class T>
inline std::ostream& Cube<T>::Print(std::ostream& out)
{
  Square<T> tmp(side, data[0][0][0]);
  tmp.Print(out);
  return out;
}

template<class T>
inline bool Cube<T>::operator==(const Cube& obj)
{
  if (side == obj.side && data[0][0][0] == obj.data[0][0][0])
    return true;
  return false;
}

template<class T>
inline Cube<T> Cube<T>::operator=(const Cube<T>& obj)
{
  if (this == obj)
  {
    return *this;
  }
  if (data != 0)
  {
    for (int i = 0; i < side; i++)
      for (int j = 0; j < side; j++)
      {
        data[i][j] = 0;
        delete[] data[i][j];
      }
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
inline void Cube<T>::Data(T _data)
{
  data = new T * *[side];
  for (int i = 0; i < side; i++)
  {
    data[i] = new T * [side];
    for (int j = 0; j < side; j++)
      data[i][j] = new T[side];
  }
  for (int i = 0; i < side; i++)
    for (int j = 0; j < side; j++)
      for (int l = 0; l < side; l++)
        data[i][j][l] = _data;
}