#pragma once
#include"point.h"
#include"shape.h"
#include"square.h"
#include"line.h"
#include"cube.h"
#include"rectangle.h"
#include"circle.h"
#include"triangle.h"
#include"simplex.h"
#include<iostream>

struct Container
{
private:
  Shape** arr;
  int size;

public:
  Container();
  ~Container();
  Shape* operator[](const int i);

  int GetSize();
  template <class T>
  void Add(T& obj);//Добавить новый объект
  template <class T>
  void Delete(T& obj);//Удалить существующий объект
  void Visual(int index);
  friend std::ostream& operator<<(std::ostream& out, Container& obj);//отобразить все имеющиеся объекты
};

Container::Container()
{
  arr = 0;
  size = 0;
}
Container::~Container()
{
  if (arr != nullptr)
    delete[] arr;
  size = 0;
}

Shape* Container::operator[](const int i)
{
  return arr[i];
}

int Container::GetSize()
{
  return size;
}

void Container::Visual(int index)
{
  std::cout << *(arr[index]);
}

std::ostream& operator<<(std::ostream& out, Container& obj)
{
  for (int i = 0; i < obj.size; i++)
  {
    out << *(obj[i]) << std::endl;
  }
  return out;
}

template<class T>
void Container::Add(T& obj)
{
  Shape** objects = new Shape * [size];
  for (int i = 0; i < size; i++)
  {
    objects[i] = arr[i];
  }
  arr = 0;
  delete[]arr;
  size++;
  arr = new Shape * [size];
  for (int i = 0; i < size - 1; i++)
  {
    arr[i] = objects[i];
  }
  arr[size - 1] = (&obj);
  objects = 0;
  delete[]objects;
}

template<class T>
void Container::Delete(T& obj)
{
  Shape** objects = new Shape * [size];
  int j = 0;
  int k = 0;
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == &obj)
    {
      k = 1;
    }
    else
    {
      objects[j] = arr[i];
      j++;
    }
  }
  if (k == 0)
    throw "object not found";

  delete[] arr;
  arr = new Shape * [size - 1];
  size = size - 1;
  for (int i = 0; i < size; i++)
    arr[i] = objects[i];

  delete[] objects;
}